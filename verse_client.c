#include <verse.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/* My session ID */
static uint8_t my_session_id = 255;

/* Error value */
static int error;

/* My callback function for user authentication */
void cb_receive_user_authenticate(const uint8_t session_id,
        const char *username,
        const uint8_t auth_methods_count,
        const uint8_t *methods)
{
    char name[64], *password;

    /* Get username, when it is requested */
    if(username == NULL) {
        printf("Username: ");
        scanf("%s", name);
        vrs_send_user_authenticate(session_id, name, 0, NULL);
    } else {
        /* We assume that VRS_UA_METHOD_PASSWORD is in methods array */
        strcpy(name, username);
        /* Get password from user */
        password = getpass("Password: ");
        vrs_send_user_authenticate(session_id, name, VRS_UA_METHOD_PASSWORD, password);
    }
}

/* My callback function for connect accept */
void cb_receive_connect_accept(const uint8_t session_id,
        const uint16_t user_id,
        const uint32_t avatar_id)
{
    /* When we are connected, then terminate connection. */
    printf("Connection to Verse server established. Terminating this connection.\n");
    vrs_send_connect_terminate(my_session_id);
}

/* My callback function for connect terminate */
void cb_receive_connect_terminate(const uint8_t session_id,
        const uint8_t error_num)
{
    /* Connection to Verse server was terminated */
    printf("Connection to Verse server terminated.\n");
    my_session_id = 255;
    if(!(error_num == VRS_CONN_TERM_CLIENT || error_num == VRS_CONN_TERM_SERVER)) {
        error = VRS_FAILURE;
    }
}

int main(void)
{
    /* Register basic callback functions */
    vrs_register_receive_user_authenticate(cb_receive_user_authenticate);
    vrs_register_receive_connect_accept(cb_receive_connect_accept);
    vrs_register_receive_connect_terminate(cb_receive_connect_terminate);

    /* Send connect request to the server */
    error = vrs_send_connect_request("localhost", "12345", 0, &my_session_id);

    if(error == VRS_SUCCESS) {
        /* Never ending loop */
        while(my_session_id != 255) {
            vrs_callback_update(my_session_id);
            sleep(1);
        }
    }

    if(error != VRS_SUCCESS) {
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}

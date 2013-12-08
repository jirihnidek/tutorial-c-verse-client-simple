#include <verse.h>
#include <stdio.h>
#include <stdlib.h>

/* My session ID */
static uint8_t my_session_id = -1;

/* My callback function for user authentication */
void cb_receive_user_authenticate(const uint8_t session_id,
        const char *username,
        const uint8_t auth_methods_count,
        const uint8_t *methods)
{
    /* TODO: Do something useful here */
}

/* My callback function for connect accept */
void cb_receive_connect_accept(const uint8_t session_id,
        const uint16_t user_id,
        const uint32_t avatar_id)
{
    /* TODO: Do something useful here */
}

/* My callback function for connect terminate */
void cb_receive_connect_terminate(const uint8_t session_id,
        const uint8_t error_num)
{
    /* TODO: Do something useful here */
}

int main(void)
{
    int error_num;

    /* Send connect request to the server */
    error_num = vrs_send_connect_request("localhost", "12345", 0, &my_session_id);

    return EXIT_SUCCESS;
}

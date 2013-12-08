#include <verse.h>
#include <stdio.h>
#include <stdlib.h>

/* My session ID */
static uint8_t my_session_id = -1;

int main(void)
{
    int error_num;

    /* Send connect request to the server */
    error_num = vrs_send_connect_request("localhost", "12345", 0, &my_session_id);

    return EXIT_SUCCESS;
}

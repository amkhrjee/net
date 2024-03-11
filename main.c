#include <stdio.h>
#include <arpa/inet.h>
#include <sys/socket.h>

int main(void)
{
    struct sockaddr_in sa;

    inet_pton(AF_INET, "10.12.110.58", &sa.sin_addr);

    printf("The value stored in sockaddr_in = %u\n", sa.sin_addr);

    char ip4[INET_ADDRSTRLEN];

    inet_ntop(AF_INET, &(sa.sin_addr), ip4, INET_ADDRSTRLEN);

    printf("The original IP Address: %s\n", ip4);

    return 0;
}

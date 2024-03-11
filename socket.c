#include <string.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>

int main(void)
{
    struct addrinfo hints, *res;
    int sockfd;

    // we need to make sure that the hints struct is empty
    memset(&hints, 0, sizeof hints);
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = AI_PASSIVE;

    getaddrinfo(NULL, "3490", &hints, &res);

    sockfd = socket(res->ai_family, res->ai_socktype, res->ai_protocol);

    // we assign the socket file descriptor to a port on our system
    bind(sockfd, res->ai_addr, res->ai_addrlen);
}
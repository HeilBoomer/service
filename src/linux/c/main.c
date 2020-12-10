#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <netinet/in.h>
#include <string.h>

#define PORT 42069

static volatile sig_atomic_t stop = 0;
static void interrupt_handler(int sig)
{
    stop = 1;
}

int main(int argc, char *argv[])
{
    int server_fd, new_socket, valread;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[1024] = {0};

    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0)
    {
        perror(" \x1b[1;31m=> \x1b[1;37mFailed to create socket!\x1b[;m");
        return EXIT_FAILURE;
    }
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt)))
    {
        perror(" \x1b[1;31m=> \x1b[1;37mFailed to attach socket to port!\x1b[;m");
        return EXIT_FAILURE;
    }
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0)
    {
        perror(" \x1b[1;31m=> \x1b[1;37mFailed to bind server!\x1b[;m");
        return EXIT_FAILURE;
    }
    if (listen(server_fd, 3) < 0)
    {
        perror(" \x1b[1;31m=> \x1b[1;37mCouldn't listen to port!\x1b[;m");
        return EXIT_FAILURE;
    }
    if ((new_socket = accept(server_fd, (struct sockaddr*) &address, (socklen_t*) &addrlen)) < 0)
    {
        perror(" \x1b[1;31m=> \x1b[1;37mCouldn't accept the client!\x1b[;m");
        return EXIT_FAILURE;
    }

    while (!stop)
    {
        if (stop)
            break;

        if (!valread)
            new_socket = accept(server_fd, (struct sockaddr*) &address, (socklen_t*) &addrlen);

        valread = read(new_socket, buffer, 1024);
        if (valread)
        {
            printf(" \x1b[1;32m=> \x1b[1;37mReceived message: \x1b[;m%s\n", buffer);
        }
    }

    return EXIT_SUCCESS;
}

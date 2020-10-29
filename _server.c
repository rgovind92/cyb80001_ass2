#include <stdio.h>
#include <netdb.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

#define MAX 80
#define PORT 8080
#define SA struct sockaddr

void func(int sock_fd)
{
    char buf[MAX];
    int n;

    while (1) {
        bzero(buf, MAX);

        read(sock_fd, buf, sizeof(buf));

        printf("From client: %s", buf);

        bzero(buf, MAX);
        n = 0;

        while ((buf[n++] = getchar()) != '\n');

        write(sock_fd, buf, sizeof(buf));

        if (strncmp("exit", buf, 4) == 0) {
            printf("Server exit...\n");
            break;
        }
    }
}

int main()
{
    int sock_fd, conn_fd, len;
    struct sockaddr_in server, client;

    sock_fd = socket(AF_INET, SOCK_STREAM, 0);
    
    if (sock_fd == -1) {
        printf("Socket creation failed...\n");
        return 0;
    }
    else
        printf("Socket created...\n");

    bzero(&server, sizeof(server));

    server.sin_family = AF_INET;
    server.sin_addr.s_addr = htonl(INADDR_ANY);
    server.sin_port = htons(PORT);

    if ((bind(sock_fd, (SA*) &server, sizeof(server))) != 0) {
        printf("Socket bind failed...\n");
        return 0;
    }
    else
        printf("Socket bound...\n");

    if ((listen(sock_fd, 5)) != 0) {
        printf("Listen failed...\n");
        return 0;
    }
    else
        printf("Server listening...\n");

    len = sizeof(client);

    conn_fd = accept(sock_fd, (SA*) &client, &len);

    if (conn_fd < 0) {
        printf("Server accept failed...\n");
        return 0;
    }
    else
        printf("Server accepted");

    func(conn_fd);

    close(sock_fd);
}

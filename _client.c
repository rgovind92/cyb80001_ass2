#include <netdb.h> 
#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX 80
#define PORT 8080
#define SA struct sockaddr

void func(int sock_fd)
{
    char buf[MAX];
    int n;

    while (1) {
        bzero(buf, sizeof(buf));
        printf("Enter: ");
        n = 0;

        while ((buf[n++] = getchar()) != '\n');
 
        write(sock_fd, buf, sizeof(buf));
        bzero(buf, sizeof(buf));
        read(sock_fd, buf, sizeof(buf));
        printf("From server : %s", buf);

        if ((strncmp(buf, "exit", 4)) == 0) {
            printf("Client exit...\n");
            break;
        }
    }
}
  
int main() 
{ 
    int sock_fd, conn_fd; 
    struct sockaddr_in server, client; 
  
    sock_fd = socket(AF_INET, SOCK_STREAM, 0); 
    
    if (sock_fd == -1) {
        printf("Socket creation failed...\n");
        exit(0);
    }
    else
        printf("Socket created..\n"); 
    
    bzero(&server, sizeof(server)); 
  
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = inet_addr("127.0.0.1");
    server.sin_port = htons(PORT);
  
    if (connect(sock_fd, (SA*) &server, sizeof(server)) != 0) {
        printf("Connection with the server failed...\n");
        exit(0);
    }
    else
        printf("Connected to the server..\n");
  
    func(sock_fd);
  
    close(sock_fd); 
} 

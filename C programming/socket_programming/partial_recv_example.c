#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

void recv_all(int sockfd, char *buffer, size_t length) {
    size_t total_received = 0;
    ssize_t bytes_received;
    
    while (total_received < length) {
        bytes_received = recv(sockfd, buffer + total_received, length - total_received, 0);
        if (bytes_received <= 0) {
            perror("Receive failed");
            return;
        }
        total_received += bytes_received;
    }
}

int main() {
    int sockfd;
    struct sockaddr_in server_addr;
    char buffer[1024];
    
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(8080);
    inet_pton(AF_INET, "127.0.0.1", &server_addr.sin_addr);
    
    connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr));
    recv_all(sockfd, buffer, 1024);
    
    printf("Received all data: %s\n", buffer);
    close(sockfd);
    return 0;
}

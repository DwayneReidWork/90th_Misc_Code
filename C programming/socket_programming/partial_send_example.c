#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

void send_all(int sockfd, const char *data, size_t len) {
    size_t total_sent = 0;
    ssize_t bytes_sent;
    
    while (total_sent < len) {
        bytes_sent = send(sockfd, data + total_sent, len - total_sent, 0);
        if (bytes_sent <= 0) {
            perror("Send failed");
            return;
        }
        total_sent += bytes_sent;
    }
}

int main() {
    int sockfd;
    struct sockaddr_in server_addr;
    const char *message = "This is a large message sent in parts.";
    
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(8080);
    inet_pton(AF_INET, "127.0.0.1", &server_addr.sin_addr);
    
    connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr));
    send_all(sockfd, message, strlen(message));
    
    printf("All data sent successfully.\n");
    close(sockfd);
    return 0;
}

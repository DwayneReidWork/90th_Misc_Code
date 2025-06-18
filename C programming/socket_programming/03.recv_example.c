#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

int main() {
    int sockfd, client_sock;
    struct sockaddr_in server_addr, client_addr;
    char buffer[1024] = {0};
    socklen_t client_len = sizeof(client_addr);
    
    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("Socket creation failed");
        return 1;
    }
    
    // Set up server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(8080);
    server_addr.sin_addr.s_addr = INADDR_ANY;
    
    // Bind the socket
    if (bind(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("Bind failed");
        close(sockfd);
        return 1;
    }
    
    // Listen for connections
    listen(sockfd, 5);
    printf("Server is listening on port 8080...\n");
    
    // Accept a connection
    client_sock = accept(sockfd, (struct sockaddr*)&client_addr, &client_len);
    if (client_sock < 0) {
        perror("Accept failed");
        close(sockfd);
        return 1;
    }
    
    // Receive data
    ssize_t bytes_received = recv(client_sock, buffer, sizeof(buffer) - 1, 0);
    if (bytes_received == -1) {
        perror("Receive failed");
    } else {
        buffer[bytes_received] = '\0'; // Null-terminate the string
        printf("Received message: %s\n", buffer);
    }
    
    // Close sockets
    close(client_sock);
    close(sockfd);
    return 0;
}

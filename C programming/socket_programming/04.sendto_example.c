#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

int main() {
    int sockfd;
    struct sockaddr_in dest_addr;
    char *message = "Hello, UDP Server!";
    
    // Create a UDP socket
    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd == -1) {
        perror("Socket creation failed");
        return 1;
    }
    
    // Set up destination address
    dest_addr.sin_family = AF_INET;
    dest_addr.sin_port = htons(8080);
    inet_pton(AF_INET, "127.0.0.1", &dest_addr.sin_addr);
    
    // Send a message
    ssize_t bytes_sent = sendto(sockfd, message, strlen(message), 0, (struct sockaddr*)&dest_addr, sizeof(dest_addr));
    if (bytes_sent == -1) {
        perror("Sendto failed");
    } else {
        printf("Sent %zd bytes to the server\n", bytes_sent);
    }
    
    // Close the socket
    close(sockfd);
    return 0;
}

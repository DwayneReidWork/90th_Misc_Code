#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>

int main() {
    int sockfd;
    
    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("Socket creation failed");
        return 1;
    }
    
    printf("Socket created successfully. Descriptor: %d\n", sockfd);
    return 0;
}

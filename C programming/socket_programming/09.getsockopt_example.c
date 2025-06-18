#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

int main() {
    int sockfd;
    int optval;
    socklen_t optlen = sizeof(optval);
    
    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("Socket creation failed");
        return 1;
    }
    
    // Get the SO_REUSEADDR option
    if (getsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &optval, &optlen) < 0) {
        perror("Getsockopt failed");
    } else {
        printf("SO_REUSEADDR is %s\n", (optval ? "ON" : "OFF"));
    }
    
    // Close the socket
    close(sockfd);
    return 0;
}

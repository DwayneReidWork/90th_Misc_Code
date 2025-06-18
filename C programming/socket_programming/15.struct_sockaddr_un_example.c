#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <unistd.h>

int main() {
    int sockfd;
    struct sockaddr_un server_addr;
    
    // Create a UNIX domain socket
    sockfd = socket(AF_UNIX, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("Socket creation failed");
        return 1;
    }
    
    // Set up the address
    server_addr.sun_family = AF_UNIX;
    strncpy(server_addr.sun_path, "/tmp/my_socket", sizeof(server_addr.sun_path) - 1);
    
    // Print the address path
    printf("Socket path: %s\n", server_addr.sun_path);
    
    close(sockfd);
    return 0;
}

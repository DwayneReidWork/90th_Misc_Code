#include <stdio.h>
#include <string.h>
#include <arpa/inet.h>

int main() {
    struct sockaddr_in server_addr;
    
    // Set up the IPv4 address
    server_addr.sin_family = AF_INET;               // IPv4 family
    server_addr.sin_port = htons(8080);             // Port number in network byte order
    inet_pton(AF_INET, "127.0.0.1", &server_addr.sin_addr); // Convert and set IP address
    
    printf("IPv4 Address: %s\n", inet_ntoa(server_addr.sin_addr));
    printf("Port: %d\n", ntohs(server_addr.sin_port));
    
    return 0;
}

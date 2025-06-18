#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>

int main() {
    struct sockaddr_storage addr_storage;
    struct sockaddr_in *addr_v4 = (struct sockaddr_in *)&addr_storage;
    
    // Set up an IPv4 address
    addr_v4->sin_family = AF_INET;                // IPv4 family
    addr_v4->sin_port = htons(8080);              // Port number
    inet_pton(AF_INET, "127.0.0.1", &addr_v4->sin_addr);
    
    // Cast back to sockaddr_storage for compatibility
    printf("Address family: %d\n", addr_storage.ss_family);
    printf("IP: %s\n", inet_ntoa(addr_v4->sin_addr));
    printf("Port: %d\n", ntohs(addr_v4->sin_port));
    
    return 0;
}

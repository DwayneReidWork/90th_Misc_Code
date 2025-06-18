#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>

int main() {
    struct sockaddr sa;
    
    // Set up a generic address
    sa.sa_family = AF_INET;  // Specify IPv4
    strncpy(sa.sa_data, "127.0.0.1", sizeof(sa.sa_data)); // Store example address (not used directly)
    
    printf("Address family: %d\n", sa.sa_family);
    printf("Raw address data: %s\n", sa.sa_data);
    
    return 0;
}

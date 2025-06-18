#include <stdio.h>
#include <unistd.h>

int main() {
    char hostname[1024];
    
    // Get the hostname
    if (gethostname(hostname, sizeof(hostname)) < 0) {
        perror("gethostname failed");
        return 1;
    }
    
    printf("Hostname: %s\n", hostname);
    return 0;
}

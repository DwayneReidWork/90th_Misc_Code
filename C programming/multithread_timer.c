#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

void* timer_function(void* arg) {
    int timer_id = *(int*)arg;  // Get timer ID
    int duration = timer_id == 1 ? 1 : 2; // Timer interval in seconds
    free(arg); // Free dynamically allocated memory for thread argument

    for (int i = 1; i <= 10; ++i) {
        printf("Timer %d: %d seconds elapsed\n", timer_id, i * duration);
        sleep(duration);
    }

    printf("Timer %d finished!\n", timer_id);
    pthread_exit(NULL);
}

int main() {
    pthread_t thread1, thread2;

    // Create the first thread
    int* timer1_id = malloc(sizeof(int));
    if (timer1_id == NULL) {
        perror("Failed to allocate memory for timer1_id");
        return 1;
    }
    *timer1_id = 1;

    if (pthread_create(&thread1, NULL, timer_function, timer1_id) != 0) {
        perror("Failed to create thread 1");
        return 1;
    }

    // Create the second thread
    int* timer2_id = malloc(sizeof(int));
    if (timer2_id == NULL) {
        perror("Failed to allocate memory for timer2_id");
        return 1;
    }
    *timer2_id = 2;

    if (pthread_create(&thread2, NULL, timer_function, timer2_id) != 0) {
        perror("Failed to create thread 2");
        return 1;
    }

    // Wait for both threads to finish
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    printf("Both timers completed.\n");

    return 0;
}

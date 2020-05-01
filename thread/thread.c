#include <pthread.h>
#include <stdio.h>

int count;

void* run(void* noarg) {
    for (int i = 0; i < 100000; i++) {
        count++;
    }
    pthread_exit(NULL);
    return NULL;
}

int main() {
    count = 0;
    pthread_t t1, t2;

    pthread_create(&t1, NULL, run, NULL);
    pthread_create(&t2, NULL, run, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    printf("Count: %d\n", count);

    return 0;
}
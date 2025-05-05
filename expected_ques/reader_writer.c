#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

int data = 0;  // Shared data
int writing = 0;

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void* reader(void* arg) {
    while (1) {
        pthread_mutex_lock(&mutex);

        if (!writing) {
            printf("Reader reads: %d\n", data);
        } else {
            printf("Reader is waiting...\n");
        }

        pthread_mutex_unlock(&mutex);
        sleep(1);
    }
    return NULL;
}

void* writer(void* arg) {
    while (1) {
        pthread_mutex_lock(&mutex);
        writing = 1;

        data++;
        printf("Writer writes: %d\n", data);

        writing = 0;
        pthread_mutex_unlock(&mutex);
        sleep(2);
    }
    return NULL;
}

int main() {
    pthread_t r, w;

    pthread_create(&r, NULL, reader, NULL);
    pthread_create(&w, NULL, writer, NULL);

    pthread_join(r, NULL);
    pthread_join(w, NULL);

    return 0;
}

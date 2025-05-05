#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

int buffer;                  // Shared buffer (1 slot)
int full = 0;                // 0 = empty, 1 = full

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond_produce = PTHREAD_COND_INITIALIZER;
pthread_cond_t cond_consume = PTHREAD_COND_INITIALIZER;

void* producer(void* arg) {
    while (1) {
        int item = rand() % 100;
        pthread_mutex_lock(&mutex);

        while (full)  // Wait if buffer is full
            pthread_cond_wait(&cond_produce, &mutex);

        buffer = item;
        full = 1;
        printf("Produced: %d\n", item);

        pthread_cond_signal(&cond_consume);
        pthread_mutex_unlock(&mutex);
        sleep(1);
    }
    return NULL;
}

void* consumer(void* arg) {
    while (1) {
        pthread_mutex_lock(&mutex);

        while (!full)
            pthread_cond_wait(&cond_consume, &mutex);

        int item = buffer;
        full = 0;
        printf("Consumed: %d\n", item);

        pthread_cond_signal(&cond_produce);
        pthread_mutex_unlock(&mutex);
        sleep(2);
    }
    return NULL;
}

int main() {
    pthread_t t1, t2;

    pthread_create(&t1, NULL, producer, NULL);
    pthread_create(&t2, NULL, consumer, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    return 0;
}

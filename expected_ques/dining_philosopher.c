#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define N 5  // Number of philosophers

pthread_mutex_t forks[N];

void* philosopher(void* arg) {
    int id = *(int*)arg;
    int left = id;
    int right = (id + 1) % N;

    while (1) {
        printf("Philosopher %d is thinking.\n", id);
        sleep(1);

        pthread_mutex_lock(&forks[left]);
        pthread_mutex_lock(&forks[right]);

        printf("Philosopher %d is eating.\n", id);
        sleep(2);

        pthread_mutex_unlock(&forks[right]);
        pthread_mutex_unlock(&forks[left]);

        printf("Philosopher %d finished eating.\n", id);
    }
    return NULL;
}

int main() {
    pthread_t phils[N];
    int ids[N];

    for (int i = 0; i < N; i++)
        pthread_mutex_init(&forks[i], NULL);

    for (int i = 0; i < N; i++) {
        ids[i] = i;
        pthread_create(&phils[i], NULL, philosopher, &ids[i]);
    }

    for (int i = 0; i < N; i++)
        pthread_join(phils[i], NULL);

    return 0;
}

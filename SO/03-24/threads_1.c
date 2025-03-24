#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define NUM_THREADS 5
#define NUM_ITERATIONS 100000

int counter = 0;
pthread_mutex_t counter_mutex;
sem_t counter_sem;

void *thread_func_mutex(void *arg) {
    for (int i = 0; i < NUM_ITERATIONS; i++) {
        pthread_mutex_lock(&counter_mutex);
        counter++;
        pthread_mutex_unlock(&counter_mutex);
    }
    pthread_exit(NULL);
}

void *thread_func_semaphore(void *arg) {
    for (int i = 0; i < NUM_ITERATIONS; i++) {
        sem_wait(&counter_sem);
        counter++;
        sem_post(&counter_sem);
    }
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[NUM_THREADS];
    int i;
   
    // Sincronização usando Mutex
    counter = 0;
    pthread_mutex_init(&counter_mutex, NULL);
    for (i = 0; i < NUM_THREADS; i++) {
        if(pthread_create(&threads[i], NULL, thread_func_mutex, NULL)) {
            perror("Erro na criação da thread (mutex)");
            exit(EXIT_FAILURE);
        }
    }
    for (i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }
    printf("Valor final do contador (mutex): %d\n", counter);
    pthread_mutex_destroy(&counter_mutex);

    // Sincronização usando Semáforo
    counter = 0;
    sem_init(&counter_sem, 0, 1);
    for (i = 0; i < NUM_THREADS; i++) {
        if(pthread_create(&threads[i], NULL, thread_func_semaphore, NULL)) {
            perror("Erro na criação da thread (semaphore)");
            exit(EXIT_FAILURE);
        }
    }
    for (i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }
    printf("Valor final do contador (semaphore): %d\n", counter);
    sem_destroy(&counter_sem);
   
    return 0;
}


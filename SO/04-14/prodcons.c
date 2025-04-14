// produtor_consumidor.c
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define BUFFER_SIZE 5

int buffer[BUFFER_SIZE];
int in = 0, out = 0;

sem_t empty;     // Contador de espaços vazios
sem_t full;      // Contador de itens no buffer
pthread_mutex_t mutex;

void* producer(void *arg) {
    int item;
    while (1) {
        item = rand() % 100;  // produz um item aleatório
        sem_wait(&empty);     // aguarda existir um espaço vazio
        pthread_mutex_lock(&mutex);
        buffer[in] = item;
        printf("Produtor produziu: %d (na posicao %d)\n", item, in);
        in = (in + 1) % BUFFER_SIZE;
        pthread_mutex_unlock(&mutex);
        sem_post(&full);      // sinaliza que há um novo item
        sleep(1);
    }
    return NULL;
}

void* consumer(void *arg) {
    int item;
    while (1) {
        sem_wait(&full);      // aguarda ter item para consumir
        pthread_mutex_lock(&mutex);
        item = buffer[out];
        printf("Consumidor consumiu: %d (da posicao %d)\n", item, out);
        out = (out + 1) % BUFFER_SIZE;
        pthread_mutex_unlock(&mutex);
        sem_post(&empty);     // sinaliza que há um espaço vazio disponível
        sleep(2);
    }
    return NULL;
}

int main() {
    pthread_t prod, cons;
    srand(time(NULL));

    sem_init(&empty, 0, BUFFER_SIZE);
    sem_init(&full, 0, 0);
    pthread_mutex_init(&mutex, NULL);

    pthread_create(&prod, NULL, producer, NULL);
    pthread_create(&cons, NULL, consumer, NULL);

    pthread_join(prod, NULL);
    pthread_join(cons, NULL);

    sem_destroy(&empty);
    sem_destroy(&full);
    pthread_mutex_destroy(&mutex);
    return 0;
}

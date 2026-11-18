#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define N 5                 // Tamaño del buffer circular
#define ITEMS_POR_HILO 10   

// Buffer circular y variables compartidas
int buf[N];
int front = 0;
int rear = 0;

// Declaración de semáforos
sem_t empty;
sem_t full;
sem_t mutexP;
sem_t mutexC;

// Función del Productor
void* producer(void* arg) {
    int id = *((int*)arg);
    
    for (int i = 0; i < ITEMS_POR_HILO; i++) {
        int data = rand() % 100; 
        
        sem_wait(&empty);   
        sem_wait(&mutexP);  

        // Sección Crítica de Productores
        buf[rear] = data;
        printf("Productor %d insertó el dato [%d] en el índice %d\n", id, data, rear);
        rear = (rear + 1) % N;

        sem_post(&mutexP); 
        sem_post(&full);    
        
        sleep(1);           
    }
    pthread_exit(NULL);
}

// Función del Consumidor
void* consumer(void* arg) {
    int id = *((int*)arg);
    
    for (int i = 0; i < ITEMS_POR_HILO; i++) {
        sem_wait(&full);    
        sem_wait(&mutexC);  

        // Sección Crítica de Consumidores
        int result = buf[front];
        printf("Consumidor %d extrajo el dato [%d] del índice %d\n", id, result, front);
        front = (front + 1) % N;

        sem_post(&mutexC); 
        sem_post(&empty);   
        
        sleep(1);          
    }
    pthread_exit(NULL);
}

int main() {
    pthread_t prod1, prod2, cons1, cons2;
    int id_prod1 = 1, id_prod2 = 2;
    int id_cons1 = 1, id_cons2 = 2;

    // Inicialización de semáforos
    sem_init(&empty, 0, N);  
    sem_init(&full, 0, 0);  
    sem_init(&mutexP, 0, 1); 
    sem_init(&mutexC, 0, 1); 

    // Creación de los hilos (2 Productores, 2 Consumidores)
    pthread_create(&prod1, NULL, producer, &id_prod1);
    pthread_create(&prod2, NULL, producer, &id_prod2);
    pthread_create(&cons1, NULL, consumer, &id_cons1);
    pthread_create(&cons2, NULL, consumer, &id_cons2);

    pthread_join(prod1, NULL);
    pthread_join(prod2, NULL);
    pthread_join(cons1, NULL);
    pthread_join(cons2, NULL);

    sem_destroy(&empty);
    sem_destroy(&full);
    sem_destroy(&mutexP);
    sem_destroy(&mutexC);

    printf("Procesamiento completado\n");
    return 0;
}
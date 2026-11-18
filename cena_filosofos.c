#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define N 5  

sem_t tenedores[N];

void* filosofo(void* arg) {
    int id = *((int*)arg);
 
    for (int i = 0; i < 3; i++) {
        printf("Filósofo %d está PENSANDO.\n", id);
        sleep(rand() % 2 + 1); 
        
        if (id == N - 1) {
            sem_wait(&tenedores[0]);      
            sem_wait(&tenedores[id]);      
        } else {
            sem_wait(&tenedores[id]);      
            sem_wait(&tenedores[id + 1]);  
        }
        
        // Sección Crítica
        printf("Filósofo %d está COMIENDO.\n", id);
        sleep(rand() % 2 + 1); 
        
        // Protocolo de salida: Liberar los tenedores
        if (id == N - 1) {
            sem_post(&tenedores[0]);
            sem_post(&tenedores[id]);
        } else {
            sem_post(&tenedores[id]);
            sem_post(&tenedores[id + 1]);
        }
    }
    pthread_exit(NULL);
}

int main() {
    pthread_t hilos[N];
    int ids[N];
    
    // 1. Inicializar los 5 semáforos (tenedores) 
    for (int i = 0; i < N; i++) {
        sem_init(&tenedores[i], 0, 1);
    }
    
    // 2. Crear los hilos (filósofos)
    for (int i = 0; i < N; i++) {
        ids[i] = i;
        pthread_create(&hilos[i], NULL, filosofo, &ids[i]);
    }
    
    // 3. Esperar a que todos los hilos terminen su ejecución
    for (int i = 0; i < N; i++) {
        pthread_join(hilos[i], NULL);
    }
    
    // 4. Destruir los semáforos para liberar recursos
    for (int i = 0; i < N; i++) {
        sem_destroy(&tenedores[i]);
    }
    
    printf("Todos los filósofos han terminado de comer y pensar.\n");
    return 0;
}
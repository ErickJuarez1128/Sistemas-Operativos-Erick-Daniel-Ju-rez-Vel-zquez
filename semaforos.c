#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

// Declaración del semáforo global
sem_t sem_bloqueo;

void* imprimir_numeracion(void* arg) {
    int id_hilo = *((int*)arg);

    for (int i = 1; i <= 10000; i++) {
        
        if (i == 4000) {
            sem_wait(&sem_bloqueo);
        }

        printf("Hilo %d: %d\n", id_hilo, i);

        if (i == 6000) {
            sem_post(&sem_bloqueo);
        }
    }
    
    pthread_exit(NULL);
}

int main() {
    pthread_t hilo1, hilo2;
    int id1 = 1, id2 = 2;

    if (sem_init(&sem_bloqueo, 0, 1) != 0) {
        perror("Error al inicializar el semáforo");
        return 1;
    }

    pthread_create(&hilo1, NULL, imprimir_numeracion, &id1);
    pthread_create(&hilo2, NULL, imprimir_numeracion, &id2);

    pthread_join(hilo1, NULL);
    pthread_join(hilo2, NULL);

    sem_destroy(&sem_bloqueo);

    return 0;
}
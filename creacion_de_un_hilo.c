#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

void* impdes(void* arg) {
    for (int i = 10000; i >= 1; i--) {
        printf("Hilo secundario: %d\n", i);
    }
    return NULL;
}

int main() {
    pthread_t hilo;

    // Crear el hilo secundario
    if (pthread_create(&hilo, NULL, impdes, NULL) != 0) {
        perror("Error al crear el hilo");
        return 1;
    }

    for (int i = 1; i <= 10000; i++) {
        printf("Proceso principal: %d\n", i);
    }

    // Esperar a que el hilo secundario termine su ejecución
    if (pthread_join(hilo, NULL) != 0) {
        perror("Error al esperar al hilo");
        return 1;
    }

    return 0;
}
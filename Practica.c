#include <stdio.h>
#include <unistd.h>    
#include <sys/types.h> 

int main() {
    
    FILE *f_init = fopen("salida.txt", "w");
    if (f_init == NULL) {
        perror("Error al inicializar el archivo");
        return 1;
    }
    fclose(f_init);

    pid_t pid = fork();

    if (pid < 0) {
        fprintf(stderr, "Error al crear el proceso.\n");
        return 1;
    } 
    else if (pid == 0) {
        
        FILE *f = fopen("salida.txt", "a");
        if (f == NULL) {
            perror("Error al abrir el archivo en el hijo");
            return 1;
        }

        for (int i = 10000; i >= 1; i--) {
            fprintf(f, "Hijo: %d\n", i);
        }
        
        fclose(f);
    } 
    else {
       
        FILE *f = fopen("salida.txt", "a");
        if (f == NULL) {
            perror("Error al abrir el archivo en el padre");
            return 1;
        }

        for (int i = 1; i <= 10000; i++) {
            fprintf(f, "Padre: %d\n", i);
        }
        
        fclose(f);
    }

    return 0;
}
# Sistemas Operativos - Juárez Velázquez Erick Daniel 

Repositorio para las prácticas, códigos y tareas de la materia de Sistemas Operativos.
**Práctica 2: Creación de un hilo** 
Escribir, compilar y ejecutar un programa para la creación de un hilo utilizando la biblioteca pthread en el cual el proceso principal debe de imprimir números del uno al 10,000 y el hilo números del 10,000 al uno.

### En el repositorio el código fuente esta con el nombre de `creacion_de_un_hilo.c` y su salida esta con el nombre de `salida.txt` 

### ¿Cómo compilar y ejecutar los programas?
Como primer paso es dirigirte mediante el comando `cd` donde se encuentra el archivo descargado `creacion_de_un_hilo.c`.
Una vez dentro escribir los siguientes comandos:
1. **Compilar el código fuente:**
   ```bash
   gcc creacion_de_un_hilo.c -o hilos -pthread
2. **Ejercutar el programa**
   ```bash
   ./hilos
 3. **Ejecutar el programa y guardar la salida en un archivo de texto**
   ```bash
./hilos > salida.txt


# Sistemas Operativos - Juárez Velázquez Erick Daniel 

Repositorio para las prácticas, códigos y tareas de la materia de Sistemas Operativos.

## Prácticas y Programas

### 1. Creación de un hilo
Escribir, compilar y ejecutar un programa para la creación de un hilo utilizando la biblioteca pthread en el cual el proceso principal debe de imprimir números del uno al 10,000 y el hilo números del 10,000 al uno.
* **Código fuente:** `creacion_de_un_hilo.c` 
* **Salida:** `salida.txt` 

### 2. Semáforos y Sección Crítica
Programa para la creación de dos hilos donde cada uno imprime una cuenta del 1 al 10000. Utiliza semáforos para garantizar que cuando un hilo llegue a 4000, no sea interrumpido hasta llegar a 6000 (sección crítica).
* **Código fuente:** `semaforos.c` 
* **Salida:** `salida_semaforo.txt` 

### 3. Problema Productor - Consumidor
Implementación del clásico problema de sincronización productor-consumidor con múltiples productores y consumidores (dos de cada uno) utilizando un buffer compartido circular y semáforos.
* **Código fuente:** `produc-consum.c` 
* **Salida:** `salida_productor_consumidor.txt` 

### 4. La Cena de los Filósofos
Implementación del problema de la cena de los filósofos, utilizando hilos para simular los filósofos y semáforos para simular los tenedores compartidos, con una solución asimétrica para evitar interbloqueos (deadlocks).
* **Código fuente:** `cena_filosofos.c` 
* **Salida:** `salida_cena_filosofos.txt` 

---

## ¿Cómo compilar y ejecutar los programas?

Como primer paso, es necesario dirigirte mediante el comando `cd` al directorio donde se encuentran descargados o clonados los archivos. 

Una vez dentro de la carpeta, puedes utilizar los siguientes comandos dependiendo del programa que desees probar (compilando siempre con la bandera `-pthread` o `-lpthread`):

### Creación de un hilo
1. **Compilar:**
   ```bash
   gcc creacion_de_un_hilo.c -o hilos -pthread
   ```
2. **Ejecutar y guardar la salida:**
   ```bash
   ./hilos > salida.txt
   ```

### Semáforos y Sección Crítica
1. **Compilar:**
   ```bash
   gcc semaforos.c -o semaforos -pthread
   ```
2. **Ejecutar y guardar la salida:**
   ```bash
   ./semaforos > salida_semaforo.txt
   ```

### Productor - Consumidor
1. **Compilar:**
   ```bash
   gcc produc-consum.c -o produc_consum -pthread
   ```
2. **Ejecutar y guardar la salida:**
   ```bash
   ./produc_consum > salida_productor_consumidor.txt
   ```

### La Cena de los Filósofos
1. **Compilar:**
   ```bash
   gcc cena_filosofos.c -o cena_filosofos -pthread
   ```
2. **Ejecutar y guardar la salida:**
   ```bash
   ./cena_filosofos > salida_cena_filosofos.txt
   ```

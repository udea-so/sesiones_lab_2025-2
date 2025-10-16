#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>

/*
 * p5.c: Este programa demuestra cómo implementar una tubería (pipe) en C,
 * ejecutando el equivalente al comando de shell: 'cat p5.c | wc'.
 *
 * Para compilar y ejecutar (asumiendo que tienes un archivo p4.c):
 * 1. gcc -o p5 p5.c -Wall
 * 2. ./p5
 */

int main(int argc, char *argv[]) {
    // 1. Crear la tubería (pipe)
    // fd[0] es para leer (extremo de lectura)
    // fd[1] es para escribir (extremo de escritura)
    int fd[2];
    if (pipe(fd) == -1) {
        perror("pipe falló");
        exit(1);
    }

    // 2. Crear el primer proceso hijo para ejecutar 'cat p4.c'
    int pid1 = fork();
    if (pid1 < 0) {
        perror("fork falló");
        exit(1);
    }

    if (pid1 == 0) {
        // --- Código del primer hijo (será 'cat') ---

        // Redirigir la salida estándar (stdout) al extremo de escritura de la tubería
        dup2(fd[1], STDOUT_FILENO);

        // Cerrar los descriptores de la tubería que ya no necesitamos en este hijo
        close(fd[0]); // No vamos a leer de la tubería
        close(fd[1]); // Ya lo hemos duplicado a stdout

        // Preparar los argumentos para 'cat'
        char *cmd[] = {"cat", "p5.c", NULL};
        execvp(cmd[0], cmd);

        // execvp solo retorna si hay un error
        perror("execvp cat falló");
        exit(1);
    }

    // 3. Crear el segundo proceso hijo para ejecutar 'wc'
    int pid2 = fork();
    if (pid2 < 0) {
        perror("fork falló");
        exit(1);
    }

    if (pid2 == 0) {
        // --- Código del segundo hijo (será 'wc') ---

        // Redirigir la entrada estándar (stdin) al extremo de lectura de la tubería
        dup2(fd[0], STDIN_FILENO);

        // Cerrar los descriptores de la tubería que ya no necesitamos en este hijo
        close(fd[0]); // Ya lo hemos duplicado a stdin
        close(fd[1]); // No vamos a escribir en la tubería

        // Preparar los argumentos para 'wc'
        char *cmd[] = {"wc", NULL};
        execvp(cmd[0], cmd);
        
        // execvp solo retorna si hay un error
        perror("execvp wc falló");
        exit(1);
    }

    // --- Código del proceso padre ---

    // 4. El padre debe cerrar ambos extremos de la tubería.
    //    Esto es crucial. Si no lo hace, el segundo hijo ('wc') nunca
    //    detectará el fin de la entrada y se quedará esperando para siempre.
    close(fd[0]);
    close(fd[1]);

    // 5. Esperar a que ambos hijos terminen para evitar procesos zombies.
    printf("Proceso padre esperando a los hijos...\n");
    waitpid(pid1, NULL, 0);
    waitpid(pid2, NULL, 0);
    printf("Ambos hijos han terminado.\n");

    return 0;
}
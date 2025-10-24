#include <stdio.h>
#include <stdlib.h> // Necesaria para malloc y free
#include "common.h" // Para GetTime()

/*
To compile: gcc -o suma_s suma_s.c -I. -Wall -lpthread
To run: ./suma_s <size>
*/

int main(int argc, char* argv[]) {
    // Manejo de argumentos
    int size = 1000000;  // Default size
    if (argc > 2) {
        printf("Uso: %s <size>\n", argv[0]);
        return 1;
    }
    else if (argc == 2) {
        // Tamaño definido por el usuario
        size = atoi(argv[1]);
        printf("Suma con vectores de tamaño: %d\n", size);        
    }
    else if (argc == 1)    {
        // Tamaño por defecto
        printf("Suma con vectores de tamaño: %d\n", size);        
    }
    // Asignacion de memoria para los vectores
    int* v1 = (int*)malloc(size * sizeof(int));
    int* v2 = (int*)malloc(size * sizeof(int));
    int* resultado = (int*)malloc(size * sizeof(int));

    if (!v1 || !v2 || !resultado) {
        printf("Error al asignar memoria.\n");
        return 1;
    }

    // Inicializar vectores (igual que antes)
    for (int i = 0; i < size; i++) {
        v1[i] = i;
        v2[i] = i * 2;
    }

    // ======================================================
    // Medición de la versión serial
    // ======================================================

    printf("Ejecutando la suma en modo serial...\n");
    
    // INICIA LA MEDICIÓN
    double t_inicio_serial = GetTime();

    // Un único bucle que hace todo el trabajo
    for (int i = 0; i < size; i++) {
        resultado[i] = v1[i] + v2[i];
    }
    
    // FINALIZA LA MEDICIÓN
    double t_fin_serial = GetTime();
    double tiempo_serial = t_fin_serial - t_inicio_serial;

    printf("Tiempo de ejecución serial (Ts): %f segundos.\n", tiempo_serial);

    // Liberar memoria
    free(v1);
    free(v2);
    free(resultado);

    return 0;
}
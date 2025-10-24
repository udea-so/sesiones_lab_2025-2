#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/time.h> // Necesario para gettimeofday
#include <assert.h>   // Necesario para assert
# include "common.h" // Para GetTime() y Spin()


/*
To compile: gcc -o suma_p suma_p.c -I. -Wall -lpthread
To run: ./suma_p <size> <num_threads>
*/

// ======================================================
// Estructura y función del hilo (sin cambios)
// ======================================================
typedef struct {
    int id;
    int* vector1;
    int* vector2;
    int* vectorSuma;
    int tamano_total;
    int num_hilos;
} thread_args_t;

void* sumar_porcion_vector(void* args) {
    thread_args_t* data = (thread_args_t*)args;
    int tamano_trozo = data->tamano_total / data->num_hilos;
    int inicio = data->id * tamano_trozo;
    int fin = inicio + tamano_trozo;

    if (data->id == data->num_hilos - 1) {
        fin = data->tamano_total;
    }

    for (int i = inicio; i < fin; i++) {
        data->vectorSuma[i] = data->vector1[i] + data->vector2[i];
        // Descomenta la siguiente línea para simular una carga de trabajo más pesada
        // Spin(0.000001);
    }

    pthread_exit(NULL);
    return NULL;
}

// ======================================================
// Función principal con tus funciones integradas
// ======================================================
int main(int argc, char* argv[]) {
    // Manejo de argumentos
    int size = 1000000;  // Default size
    int num_threads = sysconf(_SC_NPROCESSORS_ONLN);  // Default number of threads
    if (argc > 3) {
        printf("Uso: %s <size> <num_threads>\n", argv[0]);
        return 1;
    }
    else if (argc == 3) {
        // Tamaño y numero de hilos definido por el usuario
        size = atoi(argv[1]);
        num_threads = atoi(argv[2]);        
    }
    else if (argc == 2)    {
        // Tamaño definido por el usuario
        size = atoi(argv[1]);  
    }  
    printf("Suma con vectores de tamaño: %d\n", size);
    printf("Usando %d hilos para la suma.\n", num_threads);

    
    int* v1 = (int*)malloc(size * sizeof(int));
    int* v2 = (int*)malloc(size * sizeof(int));
    int* resultado = (int*)malloc(size * sizeof(int));

    if (!v1 || !v2 || !resultado) {
        printf("Error al asignar memoria.\n");
        return 1;
    }

    for (int i = 0; i < size; i++) {
        v1[i] = i;
        v2[i] = i * 2;
    }    

    pthread_t hilos[num_threads];
    thread_args_t args_hilo[num_threads];

    // INICIA LA MEDICIÓN DE TIEMPO
    double t_inicio = GetTime();

    // Crear los hilos
    for (int i = 0; i < num_threads; i++) {
        args_hilo[i] = (thread_args_t){i, v1, v2, resultado, size, num_threads};
        pthread_create(&hilos[i], NULL, sumar_porcion_vector, (void*)&args_hilo[i]);
    }

    // Esperar a que todos los hilos terminen
    for (int i = 0; i < num_threads; i++) {
        pthread_join(hilos[i], NULL);
    }

    // FINALIZA LA MEDICIÓN DE TIEMPO
    double t_fin = GetTime();
    double tiempo_total = t_fin - t_inicio;

    printf("Suma paralela completada.\n");
    printf("Tiempo de ejecución: %f segundos.\n", tiempo_total);

    // Liberar memoria
    free(v1);
    free(v2);
    free(resultado);

    return 0;
}
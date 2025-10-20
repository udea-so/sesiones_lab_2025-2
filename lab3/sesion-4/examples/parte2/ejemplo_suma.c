#include <stdio.h>
#include <stdlib.h> // Necesaria para malloc y free

/**
 * @brief Suma dos vectores de enteros elemento por elemento.
 * * @param vector1 Puntero al primer vector.
 * @param vector2 Puntero al segundo vector.
 * @param tamano El número de elementos en los vectores.
 * @return Un puntero al nuevo vector que contiene la suma.
 * Retorna NULL si no se pudo asignar memoria.
 */
int* sumarVectores(int* vector1, int* vector2, int tamano) {
    // 1. Asignar memoria para el vector resultante
    // Se solicita memoria para 'tamano' enteros.
    int* vectorSuma = (int*)malloc(tamano * sizeof(int));

    // 2. Verificar si la memoria fue asignada correctamente
    // malloc devuelve NULL si no hay memoria disponible.
    if (vectorSuma == NULL) {
        printf("Error: No se pudo asignar memoria.\n");
        return NULL; // Retornar NULL para indicar el error
    }

    // 3. Recorrer los vectores y sumar sus elementos
    for (int i = 0; i < tamano; i++) {
        vectorSuma[i] = vector1[i] + vector2[i];
    }

    // 4. Retornar el puntero al nuevo vector con el resultado
    return vectorSuma;
}

// --- Ejemplo de uso ---
int main() {
    int v1[] = {10, 20, 30, 40, 50, 60};
    int v2[] = {7, 8, 9, 10, 11, 12};
    int tamano = sizeof(v1) / sizeof(v1[0]); // Calcula el tamaño dinámicamente

    // Llamar a la función para obtener el vector resultante
    int* resultado = sumarVectores(v1, v2, tamano);

    // Si la función no retornó un error (NULL)
    if (resultado != NULL) {
        // Imprimir el resultado
        printf("El vector suma es: [ ");
        for (int i = 0; i < tamano; i++) {
            printf("%d ", resultado[i]);
        }
        printf("]\n");

        // --- ¡MUY IMPORTANTE! ---
        // Liberar la memoria asignada con malloc cuando ya no se necesite
        free(resultado);
    }

    return 0;
}
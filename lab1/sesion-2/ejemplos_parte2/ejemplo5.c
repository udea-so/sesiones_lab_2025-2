#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* 
Para compilar: gcc ejemplo4.c -o ejemplo4.out -Wall
*/


#define TAM1 6
#define TAM2 4

// Arreglo global
int array_global[TAM1] = {1, 2, 3, 4, 5, 6};

void copy_array_float(float *array_dst, float *array_src, int tam);
void copy_array_int(int *array_dst, int *array_src, int tam);
void print_array_int(int *array, int tam);
void print_array_float(float *array, int tam); 
void reverse_array_float(float *array, int tam); 

// Funcion main
int main(int argc, char *argv[]) {
    // Arreglo local en el main
    int *int_array_reverse = (int *)malloc(TAM1*sizeof(int));  // Se crea espacio en el heap (No olvidar liberar)
    printf("---------------- Arreglo entero ----------------\n");
    print_array_int(array_global, TAM1);
    // Inversion del array
    for(int i = 0; i < TAM1; i++) {
        int_array_reverse[(TAM1 - 1) - i] = array_global[i];
    }
    print_array_int(int_array_reverse, TAM1);
    printf("---------------- Arreglo float ----------------\n");
    // copy_array_float();
    float array_local[4] = {0.5, 1, 1.5, 2.0};
    float *float_array_reverse;
    float_array_reverse = (float *)malloc(TAM2*sizeof(float)); // Se crea espacio en el heap (No olvidar liberar)
    copy_array_float(float_array_reverse, array_local, TAM2);
    print_array_float(float_array_reverse, TAM2);  
    reverse_array_float(float_array_reverse, TAM2);
    print_array_float(float_array_reverse, TAM2);  
    // Se debe liberar el espacio en el heap
    free(int_array_reverse);
    free(float_array_reverse);
    return 0;
}

void reverse_array_float(float *array, int tam) {  
    float *p_rev = &array[tam - 1];
    float temp;
    for(int i = 0; i < tam/2; i++) {
        // printf("%f - %f\n", array[i],*p_rev);
        temp = array[i];
        array[i] = *p_rev;
        *p_rev = temp;        
        // printf("%f - %f\n", array[i],*p_rev);
        p_rev--;
    }
}

void copy_array_float(float *array_dst, float *array_src, int tam) {
    for(int i = 0; i < tam; i++) {
        *(array_dst + i) = *(array_src + i); // array_dst[i] = array_src[i];
    }
}

void copy_array_int(int *array_dst, int *array_src, int tam) {
    for(int i = 0; i < tam; i++) {
        *(array_dst + i) = *(array_src + i); // array_dst[i] = array_src[i];
    }
}

void print_array_int(int *array, int tam) {
    printf("[ ");
    for(int i = 0; i < tam; i++) {
        printf("%d ", array[i]);
    }
    printf("]\n");
}

void print_array_float(float *array, int tam) {
    printf("[ ");
    for(int i = 0; i < tam; i++) {
        printf("%.2f ", array[i]);
    }
    printf("]\n");
}



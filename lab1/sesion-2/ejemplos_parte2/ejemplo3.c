#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/* 
Para compilar: gcc ejemplo3.c -o ejemplo3.out -Wall
*/

// Prototipos de las funciones
void print_array(int *array, int length);  //void print_array(int *, int); 
void init_array_random(int *arr, int start, int end, int length); // void init_array_random(int *, int, int, int); 
void get_extreme_values(int *arr, int length, int *min, int *max);
int *get_max_value(int *arr, int length);

// Funcion main
int main(int argc, char *argv[]) {
    int tam = 10;
    int A[tam];
    int lim_inf = 1;
    int lim_sup = 100;
    int minimo;
    int maximo;
    int *p_max;

    // Seed the random number generator with the current time
    srand(time(NULL));

    init_array_random(A, lim_inf, lim_sup, tam); // init_array_random(&A[0], num_min, num_max, tam);
    print_array(A,tam);
    get_extreme_values(A, tam, &minimo, &maximo); 
    printf("Valor minimo: %d\n", minimo);
    printf("Valor maximo: %d\n", maximo);
    p_max = get_max_value(A,tam);
    printf("Valor maximo: %d\n", *p_max);
    return 0;
}


void print_array(int *array, int length) {
    printf("[ ");
    for(int i = 0; i < length; i++) {
        printf("%d ", array[i]);
    }
    printf("]\n");
}

void init_array_random(int *arr, int start, int end, int length) {
    for (int i = 0; i < length; i++) {
        arr[i] = rand() % (end - start + 1) + start;
    }
}

void get_extreme_values(int *arr, int length, int *min, int *max) {
    *min = *arr;
    *max = *(arr + 0);
    for(int i = 1; i < length ;i++) {
        if(*max < *(arr + i)) {      // *max < array[i]
            *max = *(arr + i);       // *max = array[i] 
        }
        if(*min > *(arr + i)) {      // *min > array[i]
            *min = *(arr + i);       // *min = array[i] 
        }
    }
}

int *get_max_value(int *arr, int length) {
    int *p_max = arr; // int *p_max = &arr[0];
    for(int i = 1; i < length ;i++) {
        if(*p_max < *(arr + i)) {      // *p_max < array[i]
            p_max = arr + i;           // p_max = &array[i] 
        }
    }
    return p_max;
}
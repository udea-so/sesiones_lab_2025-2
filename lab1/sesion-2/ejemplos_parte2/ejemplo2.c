#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* 
Para compilar: gcc ejemplo1.c -o ejemplo1.out -Wall
*/

// Prototipos de las funciones
void init_to_zero1(double array[], int tam);
void init_to_zero2(double *array, int tam);
void sum_array1(double dest_array[], double src_array[], int tam);
void sum_array2(double *dest_array, double *src_array, int tam);
void print_array(double *array, int tam);

// Funcion main
int main(int argc, char *argv[]) {
    // ----------- Repaso apuntadores -----------
    double A[4];
    double B[] = {1,2,3,4};
    double C[4];
    double *p1, *p2, *p3; 
    // ----------- Apuntadores y elementos de un array -----------
    // Arreglo A
    p1 = &A[0];   // Forma 1
    *p1 = 5;
    printf("&A[0] = %p = %p\n", &A[0], p1);
    printf("A[0] = %.2lf = %.2lf\n", A[0], *p1);
    init_to_zero1(A, 4);
    printf("\n");
    printf("A = ");
    print_array(A, 4);
    printf("Presiona cualquier tecla para continuar...\n");
    getchar();
    // Arreglo B
    p2 = B;       // Forma 2
    printf("&B[0] = %p = %p\n", B, p2);
    printf("B[0] = %.2lf = %.2lf\n", B[0], *p2);
    printf("\n");
    printf("B = ");
    print_array(B, 4);
    printf("Presiona cualquier tecla para continuar...\n");
    getchar();
    // Arreglo C
    p3 = C;   
    printf("&C[0] = %p = %p\n", B, p2);
    printf("C = ");
    print_array(C, 4);
    *p3 = 3;
    p3++;
    *p3 = C[0]*(-2);
    *(p3 + 1) = *(p3 - 1) + *p3;
    p3 += 2;
    *p3 = 10;    
    printf("\n");
    printf("C = ");
    print_array(C, 4);
    printf("Presiona cualquier tecla para continuar...\n");
    getchar();
    p1 = A;   // p1 = &A[0];
    p2 = B;   // p2 = &B[0];
    p3 = C;   // p3 = &C[0];
    // A = B + C
    sum_array1(A,B,4);  // A = A + B
    sum_array1(A,C,4);  // A = A + C
    print_array(B, 4);
    print_array(C, 4);
    printf("------------\n");
    print_array(A, 4);
    printf("Presiona cualquier tecla para continuar...\n");
    getchar();
    return 0;
}

void init_to_zero1(double array[], int tam) {
    for(int i = 0; i < tam; i++) {
        array[i] = 0;
    }
}

void init_to_zero2(double *array, int tam) {
    for(int i = 0; i < tam; i++) {
        *(array + i) = 0; // array[i] = 0;
    }
}

void sum_array1(double dest_array[], double src_array[], int tam) {
    int i = 0;
    while(i < tam) {
        dest_array[i] += src_array[i];
        i++;
    }
}

void sum_array2(double *dest_array, double *src_array, int tam) {
    int i = 0;
    while(i < tam) {
        *(dest_array + i) += *(src_array + i); // dest_array[i] += src_array[i];
        i++;
    }
}

void print_array(double *array, int tam) {
    printf("[ ");
    double *p = array;
    for(int i = 0; i < tam; i++) {
        printf("%.2lf ", *p);
        p++;
    }
    printf("]\n");
}



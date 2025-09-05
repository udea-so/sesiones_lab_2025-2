#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* 
Para compilar: gcc ejemplo6.c -o ejemplo6.out -Wall
*/

// Prototipos de las funciones
void swap(int, int);
void swap2(int*, int*);

// Funcion main

int main(int argc, char *argv[]) {
    
    // --- 6. Funciones por referencia y valor [apuntadores] --- //
    // Llamado por valor
    printf("Ejemplo - Llamada por por valor");
    int a_ = 3 , b_ = 4, c_;  // En el codigo aparece un Warning al compilar con la opcion -Wall. ¿Como se quitaria?
    printf("a_ = %d ; b_ = %d\n", a_, b_);
    swap(a_, b_);
    printf("a_ = %d ; b_ = %d\n", a_, b_); 
    // Llamado por referencia
    printf("Ejemplo - Llamada por referencia\n");
    printf("a_ = %d ; b_ = %d\n", a_, b_);
    swap2(&a_, &b_);
    printf("a_ = %d ; b_ = %d\n", a_, b_);
    return 0;
}

// ------------------------- Definicion de funciones --------------------------------

void swap(int x, int y) {
    int z;
    z = x;
    x = y;
    y = z; 
}

void swap2(int* x, int* y) {
    int z;
    z = *x;
    *x = *y;
    *y = z; 
}

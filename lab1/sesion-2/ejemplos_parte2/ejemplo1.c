#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* 
Para compilar: gcc ejemplo1.c -o ejemplo1.out -Wall
*/

// Prototipos de las funciones
int suma1(int, int);
int suma2(int*, int*);

// Funcion main

int main(int argc, char *argv[]) {
    
    // ----------- Repaso apuntadores -----------
    int a = 3, b = 2, c = -5;
    int *p = &a;
    int *q, *r;
    q = &b;
    r = q;
    *r = c + *q;
    r = &c;
    *r = (*p)*(*q+1);
    *p = 3;
    *q = 2;
    *r = -5; 
    printf("Presiona cualquier tecla para continuar...\n");
    getchar();

    // ----------- Apuntadores y funciones -----------
    // Parte 1
    c = suma1(a, b);
    printf("c = a + b = %d + %d = %d\n", a, b, c);
    *r = suma1(*p, *q);
    printf("c = a + b = %d + %d = %d\n", *p, *q, *r);
    c = suma1(*p, b);
    printf("c = a + b = %d + %d = %d\n", *p, b, c);
    printf("Presiona cualquier tecla para continuar...\n");
    getchar();

    // Parte 2
    c = suma2(&a, &b);
    printf("c = a + b = %d + %d = %d\n", a, b, c);
    *r = suma2(p, q);
    printf("c = a + b = %d + %d = %d\n", *p, *q, *r);
    *r = suma2(&a, q);
    printf("c = a + b = %d + %d = %d\n", a, *q, *r);
    printf("Presiona cualquier tecla para continuar...\n");
    getchar();
    
    return 0;
}

// ------------------------- Definicion de funciones --------------------------------
int suma1(int x, int y) {
    return x + y;
}

int suma2(int *x, int *y) {
    return *x + *y;
}
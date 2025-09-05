#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* 
Para compilar: gcc ejemplo1.c -o ejemplo1.out -Wall
*/

int main(int argc, char *argv[]) {
    
    // ----1. Sobre salida estandar y a error ---- clear
    int age = 15;   // %d
    char sex = 'F'; // %c
    char name[] = "Chimoltrufia"; // %s
    printf("Soy la %s (sexo: %c) y tengo %d años\n", name, sex, age);
    fprintf(stderr, "Esto es un error\n");
    float peso = 2.3;         // %f
    double cosa = 1.602;  // %lf
    printf("peso = %f - cosa = %lf\n", peso, cosa);
    return 0;
}


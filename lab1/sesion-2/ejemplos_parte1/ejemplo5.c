#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* 
Para compilar: gcc ejemplo5.c -o ejemplo5.out -Wall
*/

// Prototipos de las funciones

double sumar(double x, double y);  // double sumar(double, double);



// Funcion main

int main(int argc, char *argv[]) {
    
    // --- 5. Funciones --- //

    double a = 3.3, b = 4.3, c;
    c = sumar(a,b);
    printf("a + b = %.2lf + %.2lf = %.2lf\n", a, b, c);
    return 0;
}

// ------------------------- Definicion de funciones --------------------------------

double sumar(double x, double y) {
  return x + y;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Prototipos de las funciones
double sumar(double, double);
void swap(int, int);
void swap2(int*, int*);
// Funcion

int main(int argc, char *argv[]) {
    
    // ----1. Sobre salida estandar y a error ---- clear
    /*
    int age = 15;   // %d
    char sex = 'F'; // %c
    char name[] = "Chimoltrufia"; // %s
    printf("Soy la %s (sexo: %c) y tengo %d años\n", name, sex, age);
    fprintf(stderr, "Esto es un error\n");
    float peso = 2.3;         // %f
    double cosa = 1.602;  // %lf
    printf("peso = %f - cosa = %lf\n", peso, cosa);
    */

    // ----2. Sobre entrada de datos ---- //
    /* 
    int edad;
    char ciudad[51]; // 50 + 1(Null)
    printf("Por favor diga su edad: ");
    scanf("%d",&edad);
    printf("Su edad en dias es %d\n", 365*edad);
    printf("Donde vives? ");
    scanf("%s",ciudad); 
    printf("Vivo en %s",ciudad);
    */ 
    // ---3. Argumentos por linea de comandos --- //
    /*
    if(argc == 2) {
        int edad = atoi(argv[1]);
        int meses = 12*edad;
        printf("Edad %d \n", meses);                   
    } 
    else if (argc == 3) {
        printf("Hola %s tienes %d\n", argv[1],atoi(argv[2]));
    }
    else {        
        fprintf(stderr, "Se debe usa asi: edad <años> o asi edad <nombre> <años> \n"); 
    }
    */
    // --- 4. Apuntadores --- //
    /*
    int a = 3;
    printf("a = %d\n", a);
    printf("Direccion de a = &a = %p\n", &a);
    int* p; // Apuntador
    p = &a;
    printf("Direccion de a = p = %p\n", p);
    printf("a = %d = %d\n", a, *p);
    *p = *p + 2; // a = a + 2;
    printf("a = %d\n", a);
    int b;
    int* q = &b;
    *q = 0;
    int *r = p;
    *r = 2*(*p);
    printf("a = %d = %d = %d\n", a, *p, *r);
    p = &b;
    r = q;
    */
    // --- 5. Funciones --- //
    /*
    double a = 3.3, b = 4.3, c;
    c = sumar(a,b);
    printf("a + b = %.2lf + %.2lf = %.2lf\n", a, b, c);
    */

    // --- 6. Funciones por referencia y valor [apuntadores] --- //
    // Llamado por valor
    printf("Ejemplo - Llamada por por valor");
    int a_ = 3 , b_ = 4, c_;
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

double sumar(double x, double y) {
  return x + y;
}

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
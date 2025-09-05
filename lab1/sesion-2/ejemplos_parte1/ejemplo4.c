#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* 
Para compilar: gcc ejemplo4.c -o ejemplo4.out -Wall
*/

int main(int argc, char *argv[]) {
    // --- 4. Apuntadores --- //
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
    return 0;
}

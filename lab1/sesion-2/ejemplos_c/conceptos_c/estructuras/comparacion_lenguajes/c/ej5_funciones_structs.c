#include <stdio.h>

typedef struct {
    char nombre[50];
    int edad;
} Persona;

// Paso por referencia (puntero)
void imprimir(Persona *p) {
    printf("%s tiene %d años\n", p->nombre, p->edad);
}

int main() {
    Persona p1 = {"Carlos", 28};

    imprimir(&p1);

    return 0;
}

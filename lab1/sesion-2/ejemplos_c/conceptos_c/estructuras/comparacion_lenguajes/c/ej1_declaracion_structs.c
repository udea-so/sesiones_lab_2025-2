#include <stdio.h>

// Definición de la estructura
struct Persona {
    char nombre[50];
    int edad;
};

int main() {
    // Declaración de una variable de tipo estructura
    struct Persona p1;

    // Asignación de valores
    p1.edad = 20;
    printf("Edad: %d\n", p1.edad);

    return 0;
}
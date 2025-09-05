#include <stdio.h>

typedef struct {
    char nombre[50];
    int edad;
} Persona;

int main() {
    Persona p1 = {"Marta", 25};
    Persona *ptr = &p1;

    // Acceso con operador ->
    printf("Nombre: %s\n", ptr->nombre);
    printf("Edad: %d\n", ptr->edad);

    return 0;
}
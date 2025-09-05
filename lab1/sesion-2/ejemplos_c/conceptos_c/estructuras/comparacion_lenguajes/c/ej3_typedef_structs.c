#include <stdio.h>

typedef struct {
    char nombre[50];
    int edad;
} Persona;

int main() {
    Persona p1 = {"Luis Gomez", 30};
    Persona p2 = {.nombre = "Marta Peralta", 
                  .edad = 30};

    printf("%s tiene %d años\n", p1.nombre, p1.edad);
    printf("%s tiene %d años\n", p2.nombre, p2.edad);

    return 0;
}
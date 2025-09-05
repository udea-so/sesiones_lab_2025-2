#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* 
Para compilar: gcc ejemplo2.c -o ejemplo2.out -Wall
*/


void limpiar_buffer(); 


int main(int argc, char *argv[]) {
    
    // ----2. Sobre entrada de datos ---- //
    int edad;
    char ciudad[51]; // 50 + 1(Null)
    printf("Por favor diga su edad: ");
    scanf("%d",&edad);
    printf("Su edad en dias es %d\n", 365*edad);
    printf("[Forma 1] Donde vives? "); // Problema: Usa el caso por defecto de scanf pero toma el espacio como delimitador
    scanf("%s",ciudad);
    printf("[Forma 1] Vivo en %s\n",ciudad);
    limpiar_buffer();  // Que pasa si no se usa

    printf("[Forma 2] Donde vives? "); // Solucion: Usa scanf pero no toma el espacio como fin
    scanf("%[^\n]",ciudad);
    printf("[Forma 2] Vivo en %s\n",ciudad);
    limpiar_buffer();  

    printf("[Forma 3] Donde vives? ");
    fgets(ciudad, sizeof(ciudad), stdin); // Solucion: Usa fgets y no tomo el espacio como delimitador
    printf("[Forma 3] Vivo en %s\n",ciudad); 
    // limpiar_buffer(); 
    printf("Eso es todo amigos\n");
    return 0;
}


void limpiar_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {
        // Vaciar el búfer
    }
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/* 
Para compilar: gcc ejemplo3.c -o ejemplo3.out -Wall
*/


int main(int argc, char *argv[]) {

    // ---3. Argumentos por linea de comandos --- //
    if(argc == 2) {
        int edad = atoi(argv[1]);
        int meses = 12*edad;
        // printf("Hola, los %s años que tienes equivalen a %d meses \n", argv[1], meses);                   
        printf("Hola, los %d años que tienes equivalen a %d meses \n", edad, meses);                   
    } 
    else if (argc == 3) {
        printf("Hola %s tienes %s años (%d meses)\n", argv[1], argv[2] ,12*atoi(argv[2]));
    }
    else {        
        fprintf(stderr, "Se debe usa asi: edad <años> o asi edad <nombre> <años> \n"); 
    }
    return 0;
}

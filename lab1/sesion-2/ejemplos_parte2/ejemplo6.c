#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
Para compilar: gcc ejemplo5.c -o ejemplo5.out -Wall
*/

#define TAM1 6
#define TAM2 4

// Arreglo global

// Funcion main
int main(int argc, char *argv[]) {    
    if (argc == 1) {
        char *mess[] = {"UdeA",
                        "Alma mater",
                        "de la raza",
        }; 
        // Stack
        char *mess_stack[3];
        for (int i = 0; i < 3; i++) {
            mess_stack[i] = mess[i];
        }
        for (int i = 0; i < 3; i++) {
            printf("-> %s\n", mess_stack[i]);
        }
        printf("\n");
        // Heap
        char **mess_heap = (char **)malloc(3*sizeof(char *));
        for (int i = 0; i < 3; i++) {
            *(mess_heap + i) = mess[i]; // mess_heap[i] = mess[i];
        }
        for (int i = 0; i < 3; i++) {
            printf("-> %s\n", mess_heap[i]);
        }
        printf("\n");
        free(mess_heap);
    }
    else {
        // Stack
        char *mess_stack[argc - 1];
        for (int i = 0; i < argc - 1; i++) {
            mess_stack[i] = argv[i + 1];
        }
        for (int i = 0; i < argc - 1; i++) {
            printf("-> %s\n", mess_stack[i]);
        }
        printf("\n");
        // heap
        char **mess_heap = (char **)malloc((argc - 1)*sizeof(char *));
        for (int i = 0; i < argc - 1; i++) {
            *(mess_heap + i) = argv[i + 1]; // mess_heap[i] = mess[i];
        }
        for (int i = 0; i < argc - 1; i++) {
            printf("-> %s\n", *(mess_heap + i)); // printf("-> %s\n", mess_heap[i]);
        }
        printf("\n");
        free(mess_heap);
    }
    return 0;
}

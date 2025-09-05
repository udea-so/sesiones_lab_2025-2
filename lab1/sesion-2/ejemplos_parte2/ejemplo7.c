#include <stdio.h>
#include <stdlib.h>

#define TAM 10

void print_array(int *array, int tam);

int main(int argc, char *argv[]) {
    int *p;
    p = (int *)malloc(TAM*sizeof(int));
    if(argc == 1) {        
        for (int i = 0; i < TAM; i++) {
            *(p + i) = i + 1; // p[i] = i + 1
        }
        print_array(p,TAM);
    }
    else if(argc == 2) {
        int num = atoi(argv[1]);
        int new_tam;
        if (num < TAM) {
            new_tam = TAM;
            p = realloc(p,new_tam*sizeof(int));
            for (int i = 0; i < num; i++) {
                *(p + i) = i + 1; // p[i] = i + 1
            }         
        }
        else {
            new_tam = TAM;
            while(new_tam < num) {
                new_tam *=2;
            }
            
            p = realloc(p,new_tam*sizeof(int));
            for (int i = 0; i < num; i++) {
                *(p + i) = i + 1; // p[i] = i + 1
            }
        }
        print_array(p,new_tam);
    }
    free(p);    
    return 0;
}

void print_array(int *array, int tam) {
    printf("[ ");
    for(int i = 0; i < tam; i++) {
        printf("%d ", array[i]);
    }
    printf("]\n");
}
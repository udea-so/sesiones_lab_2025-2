#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* 
Para compilar: gcc ejemplo4.c -o ejemplo4.out -Wall
*/

#include <stdio.h>
#include <string.h>

#define UDEA "UdeA"

int main() {  
  char *udea_1 = UDEA;
  char udea_2[] = UDEA;
  printf("%s\n", udea_1);
  printf("%s\n", udea_2);
  char *udea_3;
  int tam = strlen(udea_1);
  printf("%d\n", tam);
  udea_3 = (char *)malloc((tam+1)*sizeof(char));
  strcpy(udea_3, udea_1);
  printf("%s\n", udea_3);
  free(udea_3);
  udea_3 = NULL;
  return 0;
}

# Reserva dinamica de memoria

## Actividad

Descargue el archivo [dynamic_mem_examples.zip](dynamic_mem_examples.zip), descomprimalo e ingrese al directorio resultante:

```bash
cd dynamic_mem_examples
```

Una vez allí, liste los archivos en este directorio y verifique que se encuentre el archivo `Makefile`:

```bash
ls
```

Luego, compile y genere los ejecutables mediante el siguiente comando:

```bash
make
```

Si todo sale bien, por cada archivo fuente (`.c`) se genera un archivo ejecutable cuyo nombre será el mismo del archivo fuente si na extención. 

Para ejecutar los ejemplos use el nombre del archivo resultante al compilar sin tener en cuenta la extención (`.c`). Por ejemplo, si el archivo se llama `ejemplo.c`, para ejecutar el archivo generado por el makefile use el siguiente comando comando:

```bash
./ejemplo
```

## Ejemplos

Analice y ejecute la siguiente lista de ejemplos:

1. [dynamic_array01.c](#ejemplo-1)
2. [dynamic_array02.c](#ejemplo-2)
3. [dynamic_array03.c](#ejemplo-3)
4. [dynamic_array04.c](#ejemplo-4)
5. [dynamic_array05.c](#ejemplo-5)
6. [dynamic_array06.c](#ejemplo-6)
7. [dynamic_array07.c](#ejemplo-7)
8. [dynamic_array_inclass.c](#ejemplo-8)
9. [linked_list.c](#ejemplo-1)
10. [linked_list_inclass.c](#ejemplo-1)
11. [sizeof_arrays.c](#ejemplo-1)

### Ejemplo 1

**Archivo**: [dynamic_array01.c](dynamic_array01.c)

```c
/*
Author: Adalbert Gerald Soosai Raj
URL: https://pages.cs.wisc.edu/~gerald/cs354/Spring2019/code/lecture04/dynamic_array01.c
*/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "USAGE: %s <num_elems>\n", argv[0]);
		exit(1);
    }

    int num = atoi(argv[1]);
    printf("num = %d\n", num);

	// create a variable length array (vla)
    int a[num];

    for (int i = 0; i < num; ++i) {
        a[i] = 0;
    }

    for (int i = 0; i < num; ++i) {
        printf("a[%d] = %d\n", i, a[i]);
    }

    return 0;
}
```

Para ejecutar use el comando:

```
./dynamic_array01
```

### Ejemplo 2

**Archivo**: [dynamic_array02.c](dynamic_array02.c)

```c
/*
Author: Adalbert Gerald Soosai Raj
URL: https://pages.cs.wisc.edu/~gerald/cs354/Spring2019/code/lecture04/dynamic_array02.c
*/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "USAGE: %s <num_elems>\n", argv[0]);
        exit(1);
    }

    int num = atoi(argv[1]);
    printf("num = %d\n", num);

    // create a dynamic array on the heap 
    int *a = malloc(num * sizeof(int));

    if (a == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        exit(1);
    }

    for (int i = 0; i < num; ++i) {
        a[i] = 0;
    }

    for (int i = 0; i < num; ++i) {
        printf("a[%d] = %d\n", i, a[i]);
    }

    free(a);

    return 0;
}
```

Para ejecutar use el comando:

```
./dynamic_array02
```

### Ejemplo 3

**Archivo**: [dynamic_array03.c](dynamic_array03.c)

```c
/*
Author: Adalbert Gerald Soosai Raj
URL: https://pages.cs.wisc.edu/~gerald/cs354/Spring2019/code/lecture04/dynamic_array03.c
*/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "USAGE: %s <num_elems>\n", argv[0]);
        exit(1);
    }

    int num = atoi(argv[1]);
    printf("num = %d\n", num);

    // create a dynamic array on the heap 
    // clear all the memory to zeros.
    int *a = calloc(num, sizeof(int));

    if (a == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        exit(1);
    }

    for (int i = 0; i < num; ++i) {
        printf("a[%d] = %d\n", i, a[i]);
    }

    free(a);

    return 0;
}
```

Para ejecutar use el comando:

```
./dynamic_array03
```

### Ejemplo 4

**Archivo**: [dynamic_array04.c](dynamic_array04.c)

```c
/*
Author: Adalbert Gerald Soosai Raj
URL: https://pages.cs.wisc.edu/~gerald/cs354/Spring2019/code/lecture04/dynamic_array04.c
*/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "USAGE: %s <num_elems>\n", argv[0]);
        exit(1);
    }

    int num = atoi(argv[1]);
    printf("num = %d\n", num);

    // create a dynamic array on the heap.
    int *a = malloc(num * sizeof(int));

    if (a == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        exit(1);
    }

    for (int i = 0; i < num; ++i) {
        a[i] = i;
    }

    for (int i = 0; i < num; ++i) {
        printf("a[%d] = %d\n", i, a[i]);
    }

    // Question: is there a problem below?
    // Need double the size of the original array.
    printf("Resize array:\n");
    a = malloc(2 * num * sizeof(int));

    for (int i = 0; i < 2 * num; ++i) {
        printf("a[%d] = %d\n", i, a[i]);
    }


    free(a);

    return 0;
}
```

Para ejecutar use el comando:

```
./dynamic_array04
```

### Ejemplo 5

**Archivo**: [dynamic_array05.c](dynamic_array05.c)

```c
/*
Author: Adalbert Gerald Soosai Raj
URL: https://pages.cs.wisc.edu/~gerald/cs354/Spring2019/code/lecture04/dynamic_array05.c
*/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "USAGE: %s <num_elems>\n", argv[0]);
        exit(1);
    }

    int num = atoi(argv[1]);
    printf("num = %d\n", num);

    // create a dynamic array on the heap.
    int *a = malloc(num * sizeof(int));

    if (a == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        exit(1);
    }

    for (int i = 0; i < num; ++i) {
        a[i] = i;
    }

    for (int i = 0; i < num; ++i) {
        printf("a[%d] = %d\n", i, a[i]);
    }

    printf("Resize array:\n");
    // Need double the size of the original array.
    int *p = malloc(2 * num * sizeof(int));

    for (int i = 0; i < num; ++i) {
        p[i] = a[i];
    }

    free(a);

    for (int i = 0; i < 2 * num; ++i) {
        printf("a[%d] = %d\n", i, a[i]);
    }

    free(p);

    return 0;
}
```

Para ejecutar use el comando:

```
./dynamic_array05
```

### Ejemplo 6

**Archivo**: [dynamic_array06.c](dynamic_array06.c)

```c
/*
Author: Adalbert Gerald Soosai Raj
URL: https://pages.cs.wisc.edu/~gerald/cs354/Spring2019/code/lecture04/dynamic_array06.c
*/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "USAGE: %s <num_elems>\n", argv[0]);
        exit(1);
    }

    int num = atoi(argv[1]);
    printf("num = %d\n", num);

    // create a dynamic array on the heap.
    int *a = malloc(num * sizeof(int));

    if (a == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        exit(1);
    }

    for (int i = 0; i < num; ++i) {
        a[i] = i;
    }

    for (int i = 0; i < num; ++i) {
        printf("a[%d] = %d\n", i, a[i]);
    }

    printf("Resize array:\n");
    // Need double the size of the original array.
    a = realloc(a, 2 * num * sizeof(int));

    for (int i = 0; i < 2 * num; ++i) {
        printf("a[%d] = %d\n", i, a[i]);
    }

    free(a);

    return 0;
}
```

Para ejecutar use el comando:

```
./dynamic_array06
```

### Ejemplo 7

**Archivo**: [dynamic_array07.c](dynamic_array07.c)

```c
/*
Author: Adalbert Gerald Soosai Raj
URL: https://pages.cs.wisc.edu/~gerald/cs354/Spring2019/code/lecture04/dynamic_array07.c
*/

#include <stdio.h>
#include <stdlib.h>

#define ROWS 3
#define COLS 3

int** transpose(int a[][COLS]) {
    int **p = malloc(ROWS * sizeof(int *));
    for (int i = 0; i < ROWS; ++i) {
        p[i] = malloc(COLS * sizeof(int));
    }

    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            // p[i][j] = a[j][i];
            *(*(p + i) + j) = a[j][i];
        }
    }
    return p;
}

int main() {
    int a[ROWS][COLS] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            printf("a[%d][%d] = %d\t", i, j, a[i][j]);
        }
        printf("\n");
    }
    int **t = transpose(a);
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            printf("t[%d][%d] = %d\t", i, j, t[i][j]);
        }
        printf("\n");
    }
    // TODO: free the 2d array.
    return 0;
}
```

Para ejecutar use el comando:

```
./dynamic_array07
```

### Ejemplo 8

**Archivo**: [dynamic_array_inclass.c](dynamic_array_inclass.c)

```c
/*
Author: Adalbert Gerald Soosai Raj
URL: https://pages.cs.wisc.edu/~gerald/cs354/Spring2019/code/lecture04/dynamic_array_inclass.c
*/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "USAGE: %s <num_elems>\n", argv[0]);
        exit(1);
    }

    int num = atoi(argv[1]);
    printf("num = %d\n", num);

    // create a dynamic array on the heap 
    int *a = malloc(num * sizeof(int));

    if (a == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        exit(1);
    }

    for (int i = 0; i < num; ++i) {
        a[i] = i;
    }

    for (int i = 0; i < num; ++i) {
        printf("a[%d] = %d\n", i, a[i]);
    }

    a = realloc(a, 2 * num * sizeof(int));

    for (int i = 0; i < 2 * num; ++i) {
        printf("a[%d] = %d\n", i, a[i]);
    }

    free(a);

    free(a);

    return 0;
}
```

Para ejecutar use el comando:

```
./dynamic_array_inclass
```

### Ejemplo 9

**Archivo**: [linked_list.c](linked_list.c)

```c
/*
Author: Adalbert Gerald Soosai Raj
URL: https://pages.cs.wisc.edu/~gerald/cs354/Spring2019/code/lecture04/linked_list.c
*/

#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

struct node {
    int data;
    struct node * next;
};

void print_list(struct node *head);
struct node * insert_at_end(struct node *head, int data);
int delete_at_front(struct node **phead); 
 
int main() {
    struct node * head = NULL;
    print_list(head);
    head = insert_at_end(head, 10);
    print_list(head);
    head = insert_at_end(head, 20);
    print_list(head);
    head = insert_at_end(head, 30);
    print_list(head);
    delete_at_front(&head);
    print_list(head);
    delete_at_front(&head);
    print_list(head);
    delete_at_front(&head);
    print_list(head);
    return 0;
}

int delete_at_front(struct node **phead) {
    struct node * first = *phead;
    assert(first != NULL);
    *phead = first->next;
    int data = first->data;
    free(first);
    return data;
}

struct node * insert_at_end(struct node *head, int data) {
    // create a new node.
    struct node * new_node = malloc(sizeof(struct node));
    assert(new_node != NULL);
    new_node->data = data;
    new_node->next = NULL;

    // list is empty.
    if (head == NULL) {
        head = new_node;
        return head;    
    }

    // list has some elements already.
    struct node *current = head;
    while (current->next != NULL) {
        current = current->next;
    }

    current->next = new_node;
    return head;
}

void print_list(struct node *head) {
    struct node * current = head;
    if (current == NULL) {
        printf("Empty list.\n");
        return;
    } else {
        while (current) {
            printf("|%d|%p| -> ", current->data, current->next);
            current = current->next;
        } 
        printf("\n");
    } 
}
```

Para ejecutar use el comando:

```
./linked_list
```

### Ejemplo 10

**Archivo**: [linked_list_inclass.c](linked_list_inclass.c)

```c
/*
Author: Adalbert Gerald Soosai Raj
URL: https://pages.cs.wisc.edu/~gerald/cs354/Spring2019/code/lecture04/linked_list_inclass.c
*/

#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

struct node {
    int data;
    struct node * next;
};

struct node* insert_at_end(struct node* head, int data) {
    struct node *new_node = malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;

    if (head == NULL) {
        return new_node;
    }

    struct node *curr = head;
    while (curr->next != NULL) {
        curr = curr->next;
    }

    curr->next = new_node;
    return head;
}

void print_list(struct node *head) {
    while (head != NULL) {
        printf("|%d|%p| -> ", head->data, head->next);
        head = head->next;
    }
    printf("\n");
}

void delete_at_begin(struct node **phead) {
    struct node *first = *phead;
    *phead = (*phead)->next;
    free(first);
}

void addOne(int *pn) {
    *pn = *pn + 1;
}

int main() {
    int n = 100;
    addOne(&n);
    printf("n = %d\n", n);

    struct node * head = NULL;
    head = insert_at_end(head, 10);
    print_list(head);
    head = insert_at_end(head, 20);
    print_list(head);
    head = insert_at_end(head, 30);
    print_list(head);
    delete_at_begin(&head);
    print_list(head);
    delete_at_begin(&head);
    print_list(head);
    delete_at_begin(&head);
    print_list(head);
    return 0;
}
```

Para ejecutar use el comando:

```
./linked_list_inclass
```

### Ejemplo 11

**Archivo**: [sizeof_arrays.c](sizeof_arrays.c)

```c
/*
Author: Adalbert Gerald Soosai Raj
URL: https://pages.cs.wisc.edu/~gerald/cs354/Spring2019/code/lecture04/sizeof_arrays.c
*/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    int a[100];
    int *p = malloc(sizeof(int) * 100);
    printf("size of a = %d\n", sizeof(a));
    printf("size of p = %d\n", sizeof(p));
    return 0;
}
```

Para ejecutar use el comando:

```
./sizeof_arrays
```

## Referencias teoricas

A continuación se muestran algunos apuntes de clase que ilustran algunos conceptos teoricos necesarios para comprender la lista de ejemplos adjuntos:

* **Apuntadores y arreglos** [[link]](https://udea-so.github.io/intro-c/content/CH_02-S02.html)
* **Apuntadores y arreglos multidimensionales** [[link]](https://udea-so.github.io/intro-c/content/CH_02-S03.html)
* **Estructuras en C** [[link]](https://udea-so.github.io/intro-c/content/CH_02-S04.html)
* **Memoria dinámica en C** [[link]](https://udea-so.github.io/intro-c/content/CH_02-S05.html)
* **Dynamic Memory Allocation** [[link]](https://diveintosystems.org/book/C2-C_depth/dynamic_memory.html)

## Referencias

* https://skills.microchip.com/page/c-programming
* https://diveintosystems.org/book/C2-C_depth/dynamic_memory.html
* https://skills.microchip.com/fundamentals-of-the-c-programming-language-part-i
* https://skills.microchip.com/fundamentals-of-the-c-programming-language-part-ii
* https://skills.microchip.com/fundamentals-of-the-c-programming-language-part-iii


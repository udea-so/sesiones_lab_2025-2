# Apuntadores

## Actividad

Descargue el archivo [pointer_examples.zip](pointer_examples.zip), descomprimalo e ingrese al directorio resultante:

```bash
cd pointer_examples
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

### Apuntadores

Analice y ejecute la siguiente lista de ejemplos:

1. [pointers01.c](#ejemplo-1)
2. [pointers02.c](#ejemplo-2)
3. [pointers03.c](#ejemplo-3)
4. [pointers04.c](#ejemplo-4)
5. [pointers05.c](#ejemplo-5)
6. [null.c](#ejemplo-6)

#### Ejemplo 1

**Archivo**: [pointers01.c](pointers01.c)

```c
#include <stdio.h>

int main()
{
    int a = 1000;
    int b = 2000;

    int *pa = &a;
    int *pb;

    pb = &b;

    // Print values of a and b.
    printf("a = %d\t *pa = %d\n", a, *pa);
    printf("b = %d\t *pb = %d\n", b, *pb);

    // Print addresses of a and b.
    printf("&a = %p\t pa = %p\n", &a, pa);
    printf("&b = %p\t pb = %p\n", &b, pb);
}
```

Para ejecutar use el comando:

```bash
./pointers01
```

#### Ejemplo 2

**Archivo**: [pointers02.c](pointers02.c)

```c
#include <stdio.h>

main() {
    int x = 15;
    printf("\n Value of x = %d", x);
    printf("\n Address of x = %u", &x);
    printf("\n Value at address %d = %d", *(&x));
}
```


Para ejecutar use el comando:

```bash
./pointers02
```

#### Ejemplo 3

**Archivo**: [pointers03.c](pointers03.c)

```c
#include <stdio.h>

int main() {
    int num = 10;
    int * pnum = &num;
    printf("num = %d\n", num);
    printf("*pnum = %d\n", *pnum);
    printf("&num = %p\n", &num);
    printf("pnum = %p\n", pnum);
    ++pnum;
    printf("pnum = %p\n", pnum);
    
    int arr[5] = {10, 20, 30, 40 ,50};
    int * parr = &arr[0];
    
    int i;
    for (i = 0; i < 5; i++) {
        printf("%d\n", arr[i]);
    }
    printf("\n");
    for (i = 0; i < 5; i++) {
        printf("%p\t", parr);
        printf("%d\n", *parr);
        parr++;
    }
    
    return 0;
}
```


Para ejecutar use el comando:

```bash
./pointers03
```

#### Ejemplo 4

**Archivo**: [pointers04.c](pointers04.c)

```c
#include <stdio.h>

main() {
    int x = 15;
    int *y;
    y = &x;
    printf("\n Value of x = %d", x);
    printf("\n Address of x = %u", &x);
    printf("\n Value of x = %d", *y);
    printf("\n Address of x = %u", y);
    printf("\n Address of y = %u", &y);
}
```

Para ejecutar use el comando:

```bash
./pointers04
```

#### Ejemplo 5

**Archivo**: [pointers05.c](pointers05.c)

```c
/* This program illustrates the usage of pointers to
exchange the contents of two variables */

#include <stdio.h>

main() {
    int x, y;
    int *p1, *p2, *p3; /* pointers to integers */
    printf("\n Enter two integer values");
    scanf("%d %d", &x, &y);
    /* Assign the addresses x and y to p1 and p2 */
    p1 = &x;
    p2 = &y;
    /* Exchange the pointers */
    p3 = p1;
    p1 = p2;
    p2 = p3;
    /* Print the contents through exchanged contents */
    printf("\n The exchanged contents are");
    printf(" %d & %d", *p1, *p2);
}
```


Para ejecutar use el comando:

```bash
./pointers05
```

#### Ejemplo 6

**Archivo**: [null.c](null.c)

```c
#include <stdio.h>

int main()
{
    int *p = NULL;
    *p = 10;
    return 0;
}
```

Para ejecutar use el comando:

```bash
./null
```

### Apuntadores y Arreglos

Analice y ejecute la siguiente lista de ejemplos:

7. [arrays_and_pointers01.c](#ejemplo-7)
8. [arrays_and_pointers02.c](#ejemplo-8)
9. [arrays_and_pointers03.c](#ejemplo-9)
10. [arrays_and_pointers04.c](#ejemplo-10)
11. [arrays_and_pointers05.c](#ejemplo-11)
   
#### Ejemplo 7

**Archivo**: [arrays_and_pointers01.c](arrays_and_pointers01.c)

```c
/* Pointer variable method of processing an array */
#include <stdio.h>

main() {
    static int list[] = {20, 30, 35, 36, 39};
    int *p;
    int i = 0;
    p = list; /* Assign the starting address of the list */
    printf("\n The list is ...");
    while (i < 5)
    {
        printf("\n %d %d ---element", *p, i);
        i++;
        p++; /* increment pointer */
    }
}
```

Para ejecutar use el comando:

```bash
./arrays_and_pointers01
```

#### Ejemplo 8

**Archivo**: [arrays_and_pointers02.c](arrays_and_pointers02.c)

```c
/* This program illustrates the usage of pointer to a string */
#include <stdio.h>

main()
{
    char text[] = "ENGINEERING"; /* The string */
    char *p;                     /* The pointer */
    p = text;                    /* Assign the starting address of string to p */
    printf("\n The string..");   /* Print the string */
    while (*p != '\0')
    {
        printf("%c", *p);
        p++;
    }
}
```

Para ejecutar use el comando:

```bash
./arrays_and_pointers02
```

#### Ejemplo 9

**Archivo**: [arrays_and_pointers03.c](arrays_and_pointers03.c)

```c
/*
Author: Adalbert Gerald Soosai Raj
URL: https://pages.cs.wisc.edu/~gerald/cs354/Spring2019/code/lecture03/arrays_and_pointers01.c
*/


#include <stdio.h>

#define MAX 10

void print_array(int a[]);

int main() {
    int array[MAX];
    int *parray;
    int i;

    // Fill some values in the array.
    for (i = 0; i < MAX; ++i) {
        array[i] = i;
    }

	print_array(array);

    parray = &array[0];     // parray = array; also does the same thing.

    // Modify the array using the array index notation.
    printf("The array is modified using the array index notation!\n");
    for (i = 0; i < MAX; ++i) {
        array[i] = i * 2;
    }
	print_array(array);

    // Modify the array using the pointer notation.
    printf("The array is modified using the array name as a pointer!\n");
    for (i = 0; i < MAX; ++i) {
        *(array + i) = i * 3;
    }
	print_array(array);

    // Modify the array using the pointer notation.
    printf("The array is modified using the pointer named parray!\n");
    for (i = 0; i < MAX; ++i) {
        *(parray + i) = i * 4;
    }
	print_array(array);

    return 0;
}

void print_array(int a[]) {
	int i;
    for (i = 0; i < MAX; ++i) {
        printf("array[%d] = %d\n", i, a[i]);
    }
}
```

Para ejecutar use el comando:

```bash
./arrays_and_pointers03
```

#### Ejemplo 10

**Archivo**: [arrays_and_pointers04.c](arrays_and_pointers04.c)

```c
/*
Author: Adalbert Gerald Soosai Raj
URL: https://pages.cs.wisc.edu/~gerald/cs354/Spring2019/code/lecture03/arrays_and_pointers01.c
*/


#include <stdio.h>

#define MAX 10

void print_array(int a[]);

int main() {
    int array[MAX];
    int i;

    // Fill some values in the array.
    for (i = 0; i < MAX; ++i) {
        array[i] = i;
    }

	print_array(array);

    return 0;
}

// An array can be passed as a pointer.
// Note the *a instead of a[] in parameters.
void print_array(int *a) {
	int i;
    for (i = 0; i < MAX; ++i) {
        printf("array[%d] = %d\n", i, a[i]);
    }
}
```

Para ejecutar use el comando:

```bash
./arrays_and_pointers04
```

#### Ejemplo 11

**Archivo**: [arrays_and_pointers05.c](arrays_and_pointers05.c)

```c
#include <stdio.h>

char *item [] = { 
                  "Chair",
                  "Table",
                  "Stool",
                  "Desk"
                };


int main() {
    char *ptr;      // declare a pointer to a string
    ptr = item[1]; // assign the appropriate pointer to ptr

    printf("Item 1:%s\n", ptr);

    printf("Items:\n");
    for (int i = 0; i < 4; i++) {
        printf("%s\n", item[i]);
    }
    return 0;
}
```

Para ejecutar use el comando:

```bash
./arrays_and_pointers05
```

### Apuntadores y Estructuras

Analice y ejecute la siguiente lista de ejemplos:

12. [structs_and_pointers01.c](#ejemplo-12)
13. [structs_and_pointers01.c](#ejemplo-13)
14. [structs_and_pointers01.c](#ejemplo-14)

#### Ejemplo 12

**Archivo**: [structs_and_pointers01.c](structs_and_pointers01.c)

```c
/*
Author: Adalbert Gerald Soosai Raj
URL: https://pages.cs.wisc.edu/~gerald/cs354/Spring2019/code/lecture03/structs_and_pointers01.c
*/

#include <stdio.h>

struct student {
	char *name;
	int id;
};

void print_student(struct student s) {
	printf("name: %s\t id: %d\n", s.name, s.id);
}

int main() {
	// Create a student.
	struct student s1;
	s1.name = "Oliver";
	s1.id = 1;
	print_student(s1);

	// Create a pointer to a student.
	struct student *ps;
	ps = &s1;
	print_student(*ps);
	
	// Create another student.
	struct student s2;
	s2.name = "Jonathan";
	s2.id = 2;
	print_student(s2);

	ps = &s2;
	print_student(*ps);
	
	return 0;
}
```

Para ejecutar use el comando:

```bash
./structs_and_pointers01
```

#### Ejemplo 13

**Archivo**: [structs_and_pointers02.c](structs_and_pointers02.c)

```c
/*
Author: Adalbert Gerald Soosai Raj
URL: https://pages.cs.wisc.edu/~gerald/cs354/Spring2019/code/lecture03/structs_and_pointers02.c
*/


#include <stdio.h>

struct student {
	char *name;
	int id;
};

typedef struct student Student;

void print_student(Student *ps) {
	printf("name: %s\t id: %d\n", ps->name, ps->id);
}

int main() {
	// Create an array of Students.
	Student s[3];

	s[0].name = "Liangchen";
	s[0].id = 1;

	s[1].name = "Olivia";
	s[1].id = 2;

	s[2].name = "Kelsey";
	s[2].id = 3;

	int i = 0;
	for (i = 0; i < 3; ++i) {
		print_student(&s[i]);
	}

	return 0;
}
```

Para ejecutar use el comando:

```bash
./structs_and_pointers02
```


#### Ejemplo 14

**Archivo**: [structs_and_pointers03.c](structs_and_pointers03.c)

```c
/* This program demonstrates the usage of an arrow operator */
#include <stdio.h>

struct item {
	char code[5];
	int Qty;
	float cost;
};

int main() {

	struct item item_rec; /* Define a variable of struct type */
	struct item *ptr;	  /* Define a pointer of type struct */

	/* Read data through dot operator */
	printf("\n Enter the data for an item");
	printf("\nCode:");
	scanf("%s", &item_rec.code);
	printf("\nQty:");
	scanf("%d", &item_rec.Qty);
	printf("\nCost:");
	scanf("%f", &item_rec.cost);
	/* Assign the address of item_rec */
	ptr = &item_rec;
	printf("\n The data for the item...");
	printf("\nCode : %s", ptr->code);
	printf("\nQty : %d", ptr->Qty);
	printf("\nCost : %5.2f", ptr->cost);
	return 0;
}
```

Para ejecutar use el comando:

```bash
./structs_and_pointers03
```

## Referencias teoricas

A continuación se muestran algunos apuntes de clase que ilustran algunos conceptos teoricos necesarios para comprender la lista de ejemplos adjuntos:

* **Apuntadores y arreglos** [[link]](https://udea-so.github.io/intro-c/content/CH_02-S02.html)
* **Apuntadores y arreglos multidimensionales** [[link]](https://udea-so.github.io/intro-c/content/CH_02-S03.html)
* **Estructuras en C**[[link]](https://udea-so.github.io/intro-c/content/CH_02-S04.html)
* **Structs** [[link]](https://diveintosystems.org/book/C2-C_depth/structs.html)

## Referencias

* Fundamentals of the C Programming Language [[link]](https://skills.microchip.com/page/c-programming)
* Fundamentals of the C Programming Language (Part I) [[link]](https://skills.microchip.com/fundamentals-of-the-c-programming-language-part-i)
* Fundamentals of the C Programming Language (Part II) [[link]](https://skills.microchip.com/fundamentals-of-the-c-programming-language-part-ii)
* Fundamentals of the C Programming Language (Part III) [[link]](https://skills.microchip.com/fundamentals-of-the-c-programming-language-part-iii)


# Arreglos y matrices

## Actividad

Descargue el archivo [arrays_examples.zip](arrays_examples.zip), descomprimalo e ingrese al directorio resultante:

```bash
cd arrays_examples
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

1. [array01.c](#ejemplo-1)
2. [array02.c](#ejemplo-2)
3. [array03.c](#ejemplo-3)
4. [array04.c](#ejemplo-4)
5. [2d-array01.c](#ejemplo-5)
6. [2d-array02.c](#ejemplo-6)
7. [2d-array03.c](#ejemplo-7)

### Ejemplo 1

**Archivo**: [array01.c](array01.c)

```c
/*
Author: Adalbert Gerald Soosai Raj
URL: https://pages.cs.wisc.edu/~gerald/cs354/Spring2019/code/lecture03/array01.c 
*/

#include <stdio.h>

#define MAX 10

int main()
{
    int a[MAX];

    int i;

    // initialize the array to zeros.
    for (i = 0; i < MAX; ++i) {
        a[i] = 0;
    }

    for (i = 0; i < MAX; ++i) {
        printf("a[%d] = %d\n", i, a[i]);
    }

    return 0;
}
```

Para ejecutar use el comando:

```
./array01
```

### Ejemplo 2

**Archivo**: [array02.c](array02.c)

```c
/*
Author: Adalbert Gerald Soosai Raj
URL: https://pages.cs.wisc.edu/~gerald/cs354/Spring2019/code/lecture03/array02.c 
*/


#include <stdio.h>

#define MAX 10

int main()
{
    int a[MAX];

    int i;

    // initialize the array to zeros.
    // Question: what happens if you forget to initialize the array?
    // for (i = 0; i < MAX; ++i) {
    //     a[i] = 0;
    // }

    for (i = 0; i < MAX; ++i) {
        printf("a[%d] = %d\n", i, a[i]);
    }

    return 0;
}
```

Para ejecutar use el comando:

```
./array02
```

### Ejemplo 3

**Archivo**: [array03.c](array03.c)

```c
/*
Author: Adalbert Gerald Soosai Raj
URL: https://pages.cs.wisc.edu/~gerald/cs354/Spring2019/code/lecture03/array03.c 
*/

#include <stdio.h>

#define MAX 10

int main()
{
    int a[MAX];

    int i;

    // initialize the array to zeros.
    for (i = 0; i < MAX; ++i) {
        a[i] = 0;
    }

    // What happens if the array index is out of bounds?
    // Compare the behaviour with Java.
    for (i = 0; i < 2 * MAX; ++i) {
        printf("a[%d] = %d\n", i, a[i]);
    }

    return 0;
}
```

Para ejecutar use el comando:

```
./array03
```

### Ejemplo 4

**Archivo**: [array04.c](array04.c)

```c
/*
Author: Adalbert Gerald Soosai Raj
URL: https://pages.cs.wisc.edu/~gerald/cs354/Spring2019/code/lecture03/array04.c 
*/

#include <stdio.h>

#define MAX 10

int main()
{
    int a[MAX];

    int i;

    // initialize the array to zeros.
    for (i = 0; i < MAX; ++i) {
        a[i] = 0;
    }

	// Name of an array points to the address of the first element in the array.
	printf("a = %p\n", a);

	// Where is this array stored in memory?
    for (i = 0; i < MAX; ++i) {
        printf("addr: %p | a[%d] = %d\n", &a[i], i, a[i]);
    }

    return 0;
}
```

Para ejecutar use el comando:

```
./array04
```

### Ejemplo 5

**Archivo**: [2d-array01.c](2d-array01.c)

```c
#include <stdio.h>

#define MAXROW 3
#define MAXCOL 3

int main()
{
	int matrix[MAXROW][MAXCOL];

	int i;
	int j;

	// initialize the 2d-array.
	for (i = 0; i < MAXROW; ++i) {
		for (j = 0; j < MAXCOL; ++j) {
			matrix[i][j] = i + j;
		}
	}

	for (i = 0; i < MAXROW; ++i) {
		for (j = 0; j < MAXCOL; ++j) {
			printf("%d \t", matrix[i][j]);
		}
		printf("\n");
	}

	return 0;
}
```

Para ejecutar use el comando:

```
./2d-array01
```

### Ejemplo 6

**Archivo**: [2d-array02.c](2d-array02.c)

```c
#include <stdio.h>

#define MAXROW 3
#define MAXCOL 3

int main()
{
	int matrix[MAXROW][MAXCOL];

	int i;
	int j;

	// initialize the 2d-array.
	for (i = 0; i < MAXROW; ++i) {
		for (j = 0; j < MAXCOL; ++j) {
			matrix[i][j] = i + j;
		}
	}

	for (i = 0; i < MAXROW; ++i) {
		for (j = 0; j < MAXCOL; ++j) {
			printf("%d \t", matrix[i][j]);
		}
		printf("\n");
	}

	// How are the elements in a 2d-array stored in memory?
	for (i = 0; i < MAXROW; ++i) {
		for (j = 0; j < MAXCOL; ++j) {
			printf("addr = %p\t i, j = %d, %d\t value = %d\n", &matrix[i][j], i, j, matrix[i][j]);
		}
	}

	return 0;
}
```

Para ejecutar use el comando:

```
./2d-array02
```

### Ejemplo 7

**Archivo**: [2d-array03.c](2d-array03.c)

```c
#include <stdio.h>

#define MAXROW 3
#define MAXCOL 3

void print_2darray(int a[][MAXCOL]);

int main()
{
	int matrix[MAXROW][MAXCOL];

	int i;
	int j;
	// initialize the 2d-array.
	for (i = 0; i < MAXROW; ++i) {
		for (j = 0; j < MAXCOL; ++j) {
			matrix[i][j] = i + j;
		}
	}

	print_2darray(matrix);

	return 0;
}

void print_2darray(int a[][MAXCOL]) {
	int i;
	int j;
	for (i = 0; i < MAXROW; ++i) {
		for (j = 0; j < MAXCOL; ++j) {
			printf("%d \t", a[i][j]);
		}
		printf("\n");
	}
}
```

Para ejecutar use el comando:

```
./2d-array03
```

## Referencias teoricas

A continuación se muestran algunos apuntes de clase que ilustran algunos conceptos teoricos necesarios para comprender la lista de ejemplos adjuntos:

* **Apuntadores y arreglos** [[link]](https://udea-so.github.io/intro-c/content/CH_02-S02.html)
* **Apuntadores y arreglos multidimensionales** [[link]](https://udea-so.github.io/intro-c/content/CH_02-S03.html)
* **Arrays and Strings** [[link]](https://diveintosystems.org/book/C1-C_intro/arrays_strings.html)


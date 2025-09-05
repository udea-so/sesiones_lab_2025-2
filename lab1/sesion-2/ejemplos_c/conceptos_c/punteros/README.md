# Apuntadores

## 1. Introducción

En lenguajes como **Java** y **Python**, la gestión de memoria y las referencias a objetos se realizan de forma automática y transparente para el programador. Sin embargo, en **C**, el manejo de memoria es manual y los **apuntadores** (o *pointers*) son la herramienta fundamental para trabajar con direcciones de memoria, estructuras de datos dinámicas y comunicación entre funciones.

El objetivo de esta práctica es brindar una **primera aproximación al uso de apuntadores en C**, mediante ejemplos sencillos que permitan:

- Comprender cómo se almacenan y manipulan las direcciones de memoria.  
- Relacionar el concepto de referencias en Java y Python con el de punteros en C.  
- Desarrollar habilidades prácticas necesarias para la programación de bajo nivel en cursos de **Sistemas Operativos**, donde el control de memoria y el uso eficiente de recursos son esenciales.

Estos ejemplos son de carácter **introductorio** y constituyen la base para ejercicios más avanzados, como el manejo de estructuras dinámicas, procesos y comunicación en memoria compartida.

## 2. Requisitos Previos

Para la correcta compilación y ejecución de los ejercicios presentados, se requiere el siguiente entorno de desarrollo:
* Un sistema operativo compatible con el estándar POSIX (e.g., GNU/Linux, macOS).
* Un compilador estándar de C (se recomienda `gcc`).
* La utilidad de automatización de compilación `make`.
* Conocimiento fundamental de la interfaz de línea de comandos (CLI).

## 3. Referencia Rápida de Sintaxis y Conceptos

La siguiente tabla resume los operadores y conceptos fundamentales relacionados con el manejo de apuntadores en C. Se recomienda su consulta durante el análisis de los ejemplos.

| Concepto | Sintaxis en C | Descripción Técnica |
| :--- | :--- | :--- |
| **Declaración de Apuntador** | `tipo *nombre_apuntador;`<br>Ej: `int *ptr;` | Declara una variable (`ptr`) cuyo tipo es "apuntador a `tipo`", capaz de almacenar una dirección de memoria. |
| **Operador de Dirección (`&`)** | `&nombre_variable`<br>Ej: `ptr = &mi_variable;` | Operador unario que retorna la dirección de memoria de su operando. |
| **Operador de Indirección (`*`)**| `*nombre_apuntador`<br>Ej: `valor = *ptr;` | Operador de dereferencia. Accede al valor almacenado en la dirección de memoria a la que el apuntador referencia. |
| **Apuntador Nulo** | `ptr = NULL;` | `NULL` es una macro que se expande a una constante que representa una dirección de memoria no válida, indicando que el apuntador no referencia a un objeto. |
| **Aritmética de Apuntadores**| `ptr++;` o `ptr + n` | Operación que desplaza la dirección contenida en el apuntador en `n` veces el tamaño (`sizeof`) del tipo de dato base. |
| **Apuntadores y Arreglos** | `int arr[5];`<br>`int *ptr = arr;` | Por convención, un identificador de arreglo se evalúa, en la mayoría de los contextos, como la dirección de su primer elemento (`&arr[0]`). |
| **Operador Flecha (`->`)** | `apuntador_struct->miembro`<br>Ej: `p_est->id;` | Operador que permite el acceso a los miembros de una estructura (`struct`) o unión (`union`) a través de un apuntador a dicha estructura. Es sintácticamente equivalente a `(*p_est).id`. |
| **Punteros y funciones** |`swap(&a,&b);`| Se usan para **pasar parámetros por referencia**, modificando variables externas.  | 

> [!TIP]
> En Java y Python el concepto más cercano a un apuntador es la **referencia a objetos**, pero en C el programador tiene control directo sobre las direcciones de memoria, lo cual lo hace más poderoso y más riesgoso si no se maneja adecuadamente.


## 4. Actividad

Descargue el archivo [pointer_examples.zip](pointer_examples.zip), descomprímalo e ingrese al directorio resultante:

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

Si todo sale bien, por cada archivo fuente (`.c`) se genera un archivo ejecutable cuyo nombre será el mismo del archivo fuente sin la extensión. 

Para ejecutar los ejemplos use el nombre del archivo resultante al compilar sin tener en cuenta la extensión (`.c`). Por ejemplo, si el archivo se llama `ejemplo.c`, para ejecutar el archivo generado por el makefile use el siguiente comando:

```bash
./ejemplo
```

## 5. Ejemplos

### 5.1. Sección 1: Fundamentos de Apuntadores

Analice y ejecute la siguiente lista de ejemplos:

1. [pointers01.c](#ejemplo-1)
2. [pointers02.c](#ejemplo-2)
3. [pointers03.c](#ejemplo-3)
4. [pointers04.c](#ejemplo-4)
5. [pointers05.c](#ejemplo-5)
6. [null.c](#ejemplo-6)

**Ejemplo 1: Declaración, Inicialización y Dereferencia de Punteros**

* **Objetivo**: Comprender la sintaxis para declarar un puntero, asignarle una dirección de memoria y acceder al valor referenciado.
* **Archivo**: [pointers01.c](pointers01.c)

    ```c
    #include <stdio.h>

    int main() {
        int a = 1000;
        int b = 2000;

        int *pa = &a;
        int *pb = &b;

        // Imprimir valores de a y b
        printf("a = %d\t *pa = %d\n", a, *pa);
        printf("b = %d\t *pb = %d\n", b, *pb);

        // Imprimir direcciones de memoria
        printf("&a = %p\t pa = %p\n", &a, pa);
        printf("&b = %p\t pb = %p\n", &b, pb);

        return 0;
    }
    ```

* **Simulación**: [link](https://pythontutor.com/render.html#code=%23include%20%3Cstdio.h%3E%0A%0Aint%20main%28%29%20%7B%0A%20%20%20%20int%20a%20%3D%201000%3B%0A%20%20%20%20int%20b%20%3D%202000%3B%0A%0A%20%20%20%20int%20*pa%20%3D%20%26a%3B%0A%20%20%20%20int%20*pb%3B%0A%0A%20%20%20%20pb%20%3D%20%26b%3B%0A%0A%20%20%20%20//%20Imprimir%20valores%20de%20las%20variables%20y%20valores%20referenciados.%0A%20%20%20%20printf%28%22a%20%3D%20%25d%5Ct%20*pa%20%3D%20%25d%5Cn%22,%20a,%20*pa%29%3B%0A%20%20%20%20printf%28%22b%20%3D%20%25d%5Ct%20*pb%20%3D%20%25d%5Cn%22,%20b,%20*pb%29%3B%0A%0A%20%20%20%20//%20Imprimir%20direcciones%20de%20memoria.%0A%20%20%20%20printf%28%22%26a%20%3D%20%25p%5Ct%20pa%20%3D%20%25p%5Cn%22,%20%26a,%20pa%29%3B%0A%20%20%20%20printf%28%22%26b%20%3D%20%25p%5Ct%20pb%20%3D%20%25p%5Cn%22,%20%26b,%20pb%29%3B%0A%20%20%20%20%0A%20%20%20%20return%200%3B%0A%7D&cumulative=false&curInstr=0&heapPrimitives=nevernest&mode=display&origin=opt-frontend.js&py=c_gcc9.3.0&rawInputLstJSON=%5B%5D&textReferences=false)

* **Ejecución y Salida**:

    ```bash
    ./pointers01
    ```

    ```bash
    a = 1000   *pa = 1000
    b = 2000   *pb = 2000
    &a = 0x7ffee...   pa = 0x7ffee...
    &b = 0x7ffee...   pb = 0x7ffee...
    ```

    Se observa que el valor de una variable (`a`) es idéntico al valor obtenido al dereferenciar su apuntador (`*pa`). Análogamente, la dirección de la variable (`&a`) coincide con el valor almacenado en el apuntador (`pa`). Las direcciones de memoria específicas varían en cada ejecución.

**Ejemplo 2: Inversión de Operadores `&` y `*`**

* **Objetivo**: Demostrar que los operadores de dirección (`&`) e indirección (`*`) son inversos.

* **Archivo**: [pointers02.c](pointers02.c)

    ```c
    #include <stdio.h>

    int main() {
        int x = 15;
        printf("\n Value of x = %d", x);
        printf("\n Address of x = %p", &x);
        printf("\n Value at address %d = %d", *(&x));
        return 0;
    }
    ```

    La expresión *(&x) obtiene primero la dirección de x y subsecuentemente dereferencia dicha dirección, resultando en el valor original de x.

* **Ejecución y Salida**:

    ```bash
    ./pointers02
    ```

    La salida confirma que el valor de `x` y el de `*(&x)` son idénticos.


**Ejemplo 3: Aritmética de Apuntadores**

* **Objetivo**: Introducir el concepto de aritmética de apuntadores y su aplicación en el recorrido de arreglos.

* **Archivo**: [pointers03.c](pointers03.c)

    ```c
    #include <stdio.h>

    int main() {
        int num = 10;
        int *pnum = &num;
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

* **Ejecución y Salida**:

    ```bash
    ./pointers03
    ```

**Ejemplo 4: Uso de operadores `&` y `*`**

* **Objetivo**: Comprender el uso de los operadores dirección `&` y `*` para:
  * **Operador `*`**: Declaración variables tipo apuntador o para obtenere el valor almacenado en la dirección apuntada por el apuntador.
  * **Operador `&`**: Para obtener la dirección de una variable. 

* **Archivo**: [pointers04.c](pointers04.c)

    ```c
    #include <stdio.h>

    int main() {
        int x = 15;
        int *y;
        y = &x;
        printf("\n Value of x = %d", x);
        printf("\n Address of x = %p", &x);
        printf("\n Value of x = %d", *y);
        printf("\n Address of x = %p", y);
        printf("\n Address of y = %p", &y);
        return 0;
    }
    ```

* **Ejecución y Salida**:

    ```bash
    ./pointers04
    ```

**Ejemplo 5: Intercambio de Apuntadores**

* **Objetivo**: Demostrar cómo se pueden modificar los apuntadores para que referencien a distintas variables.

* **Archivo**: [pointers05.c](pointers05.c)

    ```c
    /* Este programa ilustra el uso de punteros para
    intercambiar el contenido de dos variables */

    #include <stdio.h>

    int main() {
        int x, y, temp;
        int *p1, *p2; /* punteros a enteros */
        printf("\n Enter two integer values: ");
        scanf("%d %d", &x, &y);
        /* Asignar las direcciones de x y y a p1 y p2 */
        p1 = &x;
        p2 = &y;
        /* Intercambiar los punteros */
        temp = *p1;
        *p1 = *p2;
        *p2 = temp;
        /* Imprimir los contenidos mediante punteros */
        printf("\n The exchanged contents are: ");
        printf(" %d & %d", *p1, *p2);
        return 0;
    }
    ```

* **Ejecución y Salida**:

    ```bash
    ./pointers05
    ```

**Ejemplo 6: Dereferencia de Apuntador Nulo**

* **Objetivo**: Ilustrar el error en tiempo de ejecución que ocurre al intentar dereferenciar un apuntador nulo.
  
* **Archivo**: [null.c](null.c)

    ```c
    #include <stdio.h>

    int main() {
        int *p = NULL;
        *p = 10; // Esto provocará un error de segmentación
        return 0;
    }
    ```

    > [!Warning]
    > Este programa genera un error de segmentación (`Segmentation Fault`) porque intenta desreferenciar un puntero nulo.

* **Ejecución y Salida**:

    ```bash
    ./null
    ```

    La ejecución de este programa no produce una salida estándar. En su lugar, el sistema operativo generará un error de "Fallo de segmentación" (`Segmentation Fault`). Este error es indicativo de un acceso ilegal a la memoria.

### 5.2. Sección 2: Apuntadores y Arreglos

**Ejemplos 7 y 8: Recorrido de Arreglos y Cadenas**

* **Objetivo**: Aplicar la aritmética de apuntadores para iterar sobre arreglos de enteros y de caracteres (cadenas).

* **Ejemplo 7**: [arrays_and_pointers01.c](arrays_and_pointers01.c)
  
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

    Para ejecutar digite el comando:

    ```bash
    ./arrays_and_pointers01
    ```

* **Ejemplo 8**: [arrays_and_pointers02.c](arrays_and_pointers02.c)

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

    Para ejecutar digite el comando:

    ```bash
    ./arrays_and_pointers02
    ```

**Ejemplos 9 y 10: Equivalencia Sintáctica y Paso de Arreglos a Funciones**

* **Objetivo**: Demostrar que la notación de subíndice (`array[i]`) es sintácticamente equivalente a la notación de apuntadores (`*(array + i)`) y entender cómo se pasan los arreglos a las funciones.
* **Análisis**: Cuando un arreglo se pasa como argumento a una función, no se copia el arreglo completo. En su lugar, se pasa una copia del apuntador a su primer elemento. Por esta razón, la declaración de un parámetro de función como `int  a[]` es tratada por el compilador de forma idéntica a `int *a`. Este mecanismo de paso por referencia es altamente eficiente.

* **Ejemplo 9**: [arrays_and_pointers03.c](arrays_and_pointers03.c)

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

    Para ejecutar digite el comando:

    ```bash
    ./arrays_and_pointers03
    ```

* **Ejemplo 10**: [arrays_and_pointers04.c](arrays_and_pointers04.c)
  
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

    Para ejecutar digite el comando:

    ```bash
    ./arrays_and_pointers04
    ```


**Ejemplo 11: Arreglo de Apuntadores**

* **Objetivo**: Implementar un arreglo de cadenas de caracteres utilizando un arreglo de apuntadores.

* **Análisis**: La declaración `char *item[]` define un arreglo. Cada elemento de este arreglo es de tipo `char *`, es decir, un apuntador a carácter. Cada apuntador se inicializa para que referencie el primer carácter de una cadena literal distinta.

* **Codigo**: [arrays_and_pointers05.c](arrays_and_pointers05.c)
    
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

    Para ejecutar digite el comando:

    ```bash
    ./arrays_and_pointers05
    ```


### 5.3. Sección 3: Apuntadores y Estructuras

**Ejemplo 12: Apuntador a una Estructura**

* **Objetivo**: Demostrar la declaración de un apuntador a una estructura y el acceso a sus datos.

* **Análisis**: La sintaxis struct student `*ps`; declara un apuntador a tipo `struct student`. Para acceder a la estructura completa a través del apuntador se usa el operador de dereferencia (`*ps`).

* **Codigo**: [structs_and_pointers01.c](structs_and_pointers01.c)

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

    Para ejecutar digite el comando:

    ```bash
    ./structs_and_pointers01
    ```

**Ejemplos 13 y 14: Acceso a Miembros con Operador Flecha (`->`)**

* **Objetivo**: Introducir el operador flecha (->) como mecanismo preferente para el acceso a miembros de una estructura a través de un apuntador.
* **Análisis**: El operador flecha (`p->miembro`) es una notación simplificada que realiza dos operaciones: primero, dereferencia el apuntador a la estructura (`p`) y, segundo, accede al miembro especificado (`miembro`). Es funcionalmente equivalente a la notación más verbosa `(*p).miembro`. El paso de estructuras a funciones mediante apuntadores es más eficiente que el paso por valor, ya que evita la copia de la estructura completa en la pila (stack).

* **Ejemplo 13**: [structs_and_pointers02.c](structs_and_pointers02.c)

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

    Para ejecutar digite el comando:

    ```bash
    ./structs_and_pointers02
    ```

* **Ejemplo 14**: [structs_and_pointers03.c](structs_and_pointers03.c)

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
    
    Para ejecutar digite el comando:

    ```bash
    ./structs_and_pointers03
    ```

## 6. Material de estudio

A continuación se muestran algunos apuntes de clase que ilustran algunos conceptos teóricos necesarios para comprender la lista de ejemplos adjuntos:
* **Apuntadores y arreglos** [[link]](https://udea-so.github.io/intro-c/content/CH_02-S02.html)
* **Apuntadores y arreglos multidimensionales** [[link]](https://udea-so.github.io/intro-c/content/CH_02-S03.html)
* **Estructuras en C** [[link]](https://udea-so.github.io/intro-c/content/CH_02-S04.html)
* **Structs** [[link]](https://diveintosystems.org/book/C2-C_depth/structs.html)


## 7. Referencias

* Fundamentals of the C Programming Language [[link]](https://skills.microchip.com/page/c-programming)  
* Fundamentals of the C Programming Language (Part I) [[link]](https://skills.microchip.com/fundamentals-of-the-c-programming-language-part-i)  
* Fundamentals of the C Programming Language (Part II) [[link]](https://skills.microchip.com/fundamentals-of-the-c-programming-language-part-ii)  
* Fundamentals of the C Programming Language (Part III) [[link]](https://skills.microchip.com/fundamentals-of-the-c-programming-language-part-iii)  


> [!Note]
> **AI Disclosure:** This document was created with the assistance of Artificial Intelligence language models. The content has been reviewed, edited, and validated by a human author to ensure accuracy and quality.

[⬆️ Subir un nivel](../)
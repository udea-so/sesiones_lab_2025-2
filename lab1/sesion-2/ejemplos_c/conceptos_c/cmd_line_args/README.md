# Argumentos por Línea de Comandos en C

## 1. Fundamentos de los Argumentos en la Línea de Comandos

### 1.1. Introducción

Una gran parte de las utilidades ejecutadas en una terminal de sistemas operativos tipo UNIX, tales como `ls`, `gcc` o `git`, emplean argumentos para modificar su comportamiento en tiempo de ejecución (e.g., `ls -l`, `gcc -o ejecutable fuente.c`). El manejo de argumentos por línea de comandos es una capacidad fundamental que permite el desarrollo de herramientas de software potentes y flexibles, capaces de recibir parámetros de entrada sin requerir interacción directa con el usuario durante su ejecución.

Analice los ejemplos presentados para entender como un programa escrito en lenguaje C recibe y procesa dichos argumentos a través de los parámetros `argc` y `argv` de la función `main`.

### 1.2. Estructura de los Parámetros `argc` y `argv`

Cuando un programa es invocado desde la terminal, el sistema operativo transfiere los argumentos especificados a la función `main` a través de dos parámetros fundamentales:

* **`int argc` (Argument Count):** Un tipo de dato entero que almacena el número total de cadenas de caracteres pasadas como argumento, incluyendo el nombre del propio programa ejecutable. Por consiguiente, su valor mínimo es siempre 1.
* **`char *argv[]` (Argument Vector):** Un vector (arreglo) de punteros a carácter, donde cada elemento apunta al inicio de una cadena de caracteres que representa un argumento individual.
    * `argv[0]` contiene el nombre con el cual fue invocado el programa.
    * `argv[1]` contiene el primer argumento explícito, y así sucesivamente hasta `argv[argc - 1]`.

A modo de ilustración, dado el siguiente comando ejecutado en la terminal:

```bash
./mi_programa parametro1 123
```

La información es recibida y estructurada por el programa de la siguiente forma:

|Parámetro| Descripción	|Valor|
|---|---|---|
|`argc`|Contador de argumentos|3|
|`argv`|Vector de argumentos|`argv[0] -> "./mi_programa"` <br> `argv[1] -> "parametro1"` <br> `argv[2] -> "123"`|

## 2. Actividad Preliminar: Compilación del Código

Para proceder con el análisis, es necesario descargar, descomprimir y compilar los archivos fuente proporcionados.
1. **Descargar y Descomprimir**: Obtenga el archivo `cmd_line_examples.zip` y extráigalo en un directorio de trabajo.

   ```bash
   unzip cmd_line_examples.zip
   ``` 

2. **Acceder al Directorio**: Navegue hacia el directorio resultante (`cmd_line_examples`).
   
    ```bash
    cd file_examples
    ```

    > [!tip] 
    Despues de acceder acceder al directorio, empleando el comando `ls`, liste los archivos que se encuentran en este y verifique que se encuentre el archivo `Makefile`
  
3. **Compilar los Ejemplos**: Utilice la utilidad `make` para compilar los archivos fuente (`.c`). Este proceso generará un archivo ejecutable por cada fuente.
   
   ```bash
   make
   ```

4. **Ejecute los ejecutables generados**: Si el proceso anterior es correcto, por cada archivo fuente (`.c`) se genera un archivo ejecutable cuyo nombre será el mismo del archivo fuente si la extención. Para esto ejecute el siguiente comando:
   
   ```bash
   ./nombreEjecutable
   ```

## 3. Análisis del Código Fuente

Se proporcionan dos ejemplos para su análisis. Ambos son funcionalmente idénticos pero ilustran una diferencia sintáctica en la declaración de `argv`.

### 3.1. Primer Ejemplo: `cmd_line_args01.c`

A continuación se muestra el contenido del archivo fuente [`cmd_line_args01.c`](cmd_line_args01.c) para facilitar su analisis:

```c
/*
Author: Adalbert Gerald Soosai Raj
URL: https://pages.cs.wisc.edu/~gerald/cs354/Spring2019/code/lecture03/cmd_line_args01.c
*/

#include <stdio.h>
#include <stdlib.h>

// Argument vector (argv) is declared as an array of pointers to characters.
int main(int argc, char *argv[])
{
    int i;

    if (argc != 4) {
        fprintf(stderr, "USAGE: %s <name> <age> <alpha>\n", argv[0]);
        exit(1);
    }
    
    for (i = 0; i < 4; ++i) {
        printf("argv[%d] = %s\n", i, argv[i]);
    }

    return 0;
}
```

### 3.2 Segundo Ejemplo y Equivalencia de Sintaxis (`char **argv`)

El segundo archivo, [`cmd_line_args02.c`](cmd_line_args02.c), presenta una única modificación en la firma de la función `main`:

```c
int main(int argc, char **argv)
```

> [!Tip]
En el contexto de un parámetro de función en C, las declaraciones char `*argv[]` y char `**argv` son funcionalmente equivalentes. La primera se interpreta como "un arreglo de punteros a carácter", mientras que la segunda se interpreta como "un puntero a un puntero a carácter" esto se vera luego con mas detalle.

## 4. Ejercicio Propuesto

Para consolidar los conceptos presentados, se propone el siguiente ejercicio práctico:
1. Crear un nuevo archivo fuente a partir de una copia de `cmd_line_args01.c`, denominado `saludo.c`.
2. Modificar el código fuente de `saludo.c` para que el programa cumpla con las siguientes especificaciones:
   * Debe esperar recibir exactamente un argumento por línea de comandos (un nombre de usuario), resultando en un `argc` de 2.
   * Debe validar que el número de argumentos sea el correcto. En caso contrario, debe mostrar un mensaje de uso apropiado.
   * Si el número de argumentos es correcto, debe imprimir un saludo personalizado en la salida estándar.

### Comportamiento esperado del ejecutable

* **Ejecución con el número correcto de argumentos**:
  
  ```bash
  ./saludo Yesus
  ```

  Salida esperada del comando anterior:

  ```bash
  Saludos, Yesus. Bienvenido al sistema.
  ```

* **Ejecución con un número incorrecto de argumentos:**
  
  ```bash
  ./saludo
  ```

  Salida esperada del comando anterior:

  ```bash
  Uso correcto: ./saludo <nombre_de_usuario>
  ```

## 5. Referencias teoricas

A continuación se muestran algunos apuntes de clase que ilustran algunos conceptos teoricos necesarios para comprender la lista de ejemplos adjuntos:

* **Command Line Arguments** [[link]](https://diveintosystems.org/book/C2-C_depth/advanced_cmd_line_args.html)

## 6. Enlaces de utilidad

* https://diveintosystems.org/
* http://cslibrary.stanford.edu/102/PointersAndMemory.pdf
* https://diveintosystems.org/book/C1-C_intro/index.html


> [!Note]
> **AI Disclosure:** This document was created with the assistance of Artificial Intelligence language models. The content has been reviewed, edited, and validated by a human author to ensure accuracy and quality.

[⬆️ Subir un nivel](../)
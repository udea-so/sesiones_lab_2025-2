# Ejemplos Introductorios de Programación en Lenguaje C - Parte 2 
Este repositorio alberga una colección de programas de ejemplo que ilustran conceptos fundamentales del lenguaje de programación C. Cada archivo está diseñado para ser compilado y ejecutado de forma independiente, sirviendo como una unidad de aprendizaje autocontenida.


Para compilar cualquiera de los ejemplos, use el `gcc` desde tu terminal. Por ejemplo, para compilar `ejemplo1.c`:

```c
gcc ejemplo1.c -o ejemplo1.out -Wall
```


## Descripción de Archivos de Código Fuente

A continuación, se presenta una breve descripción de cada archivo de ejemplo.

1. **Apuntadores y Funciones ([ejemplo1.c](ejemplo1.c))** 
   
   Este programa revisa la sintaxis y semántica de los apuntadores. Se demuestra cómo las funciones pueden recibir y retornar valores tanto directamente (paso por valor) como a través de apuntadores (simulando el paso por referencia). 

2. **Operaciones con Arreglos y Apuntadores ([ejemplo2.c](ejemplo2.c))**
   
   Este código ilustra la estrecha relación entre arreglos y apuntadores en C. Se implementan funciones para inicializar y sumar los elementos de arreglos, demostrando que un arreglo puede ser tratado como un apuntador a su primer elemento. 

3. **Paso de Argumentos por Referencia ([ejemplo3.c](ejemplo3.c))**
   
   Este ejemplo se enfoca en el paso de argumentos por referencia utilizando apuntadores. Se implementan funciones que modifican variables externas para encontrar los valores mínimo y máximo de un arreglo y otra función que retorna un apuntador al valor máximo. 

4. **Formas de Declarar Cadenas de Caracteres ([ejemplo4.c](ejemplo4.c))**
   Este programa presenta las distintas maneras de declarar e inicializar cadenas de caracteres en C, incluyendo el uso de macros, arreglos de caracteres y la asignación de memoria dinámica en el heap mediante `malloc`. 

5. **Gestión de Memoria para Arreglos ([ejemplo1.c](ejemplo5.c))**
   
   Este código demuestra la manipulación de arreglos de distintos tipos de datos (int y float), utilizando tanto memoria global como memoria asignada dinámicamente en el heap. Se implementan funciones para copiar, invertir e imprimir el contenido de dichos arreglos. 

6. **Asignación de Memoria en la Pila y el Montículo ([ejemplo6.c](ejemplo6.c))**
   
   Este ejemplo compara la asignación de memoria para un arreglo de cadenas de caracteres en la pila (stack) y en el montículo (heap). El programa se adapta para usar tanto un conjunto predefinido de cadenas como los argumentos proporcionados por la línea de comandos. 

7. **Reasignación Dinámica de Memoria ([ejemplo7.c](ejemplo7.c))**
   Este programa ilustra el uso de realloc para redimensionar un bloque de memoria asignado dinámicamente. El tamaño final del arreglo se ajusta en función de un valor numérico proporcionado como argumento en la línea de comandos. 

8. **Operaciones Básicas de Entrada y Salida con Archivos ([file-io.c](file-io.c))**
   
   Este código muestra las operaciones fundamentales de E/S de archivos. Demuestra cómo leer un archivo de texto (`foo.txt`) línea por línea y cómo escribir y leer datos en formato binario (`bar.bin`) utilizando las funciones `fopen`, `fgets`, `fwrite`, `fread` y `fclose`. 

> [!Note]
> **AI Disclosure:** This document was created with the assistance of Artificial Intelligence language models. The content has been reviewed, edited, and validated by a human author to ensure accuracy and quality.
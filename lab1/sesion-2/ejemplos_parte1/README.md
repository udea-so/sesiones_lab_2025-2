# Ejemplos Introductorios de Programación en Lenguaje C - Parte 1

Este repositorio contiene una serie de ejemplos diseñados para introducir conceptos fundamentales del lenguaje de programación C. Cada archivo `.c` se enfoca en un tema específico y está pensado para ser compilado y ejecutado de manera independiente.

Para compilar cualquiera de los ejemplos, puedes usar `gcc` desde tu terminal. Por ejemplo, para compilar `ejemplo1.c`:

```c
gcc ejemplo1.c -o ejemplo1.out -Wall
```

## Descripción de los Ejemplos

A continuación, se describe el contenido de cada archivo.

1. **Salida Estándar y de Error ([ejemplo1.c](ejemplo1.c))**
   
   Este programa es una introducción a cómo mostrar información en la consola. Demuestra el uso de la función `printf()` para la salida estándar y `fprintf(stderr, ...)` para reportar errores. Se muestran los especificadores de formato más comunes para distintos tipos de datos, como `%d` para enteros, `%c` para caracteres, `%s` para cadenas y `%f` para flotantes.
2. **Entrada de Datos ([ejemplo2.c](ejemplo2.c))**
   
   Aquí se explora cómo leer datos ingresados por el usuario. El ejemplo se centra en la función `scanf()` y sus particularidades, como el manejo de espacios en blanco. También se presentan soluciones a problemas comunes, como el uso de `scanf("%[^\n]", ...)` para leer líneas completas y la función `fgets()`, que es una alternativa más segura. Finalmente, se introduce una función `limpiar_buffer()` para manejar los caracteres residuales que pueden quedar en el búfer de entrada.

3. **Argumentos por Línea de Comandos ([ejemplo3.c](ejemplo3.c))** 
   
   Este ejemplo enseña cómo un programa en C puede recibir argumentos directamente desde la terminal al momento de su ejecución. Aprenderás a usar los parámetros `argc` (contador de argumentos) y `argv` (vector de argumentos) de la función main para crear programas más flexibles y potentes. También se muestra el uso de la función `atoi()` para convertir una cadena de texto a un número entero.

4. **Apuntadores ([ejemplo4.c](ejemplo4.c))** 
   
   Un concepto central en C. Este código introduce la idea de los apuntadores (punteros). Verás cómo declarar un apuntador, cómo asignarle la dirección de memoria de otra variable usando el operador `&` (dirección de), y cómo acceder al valor almacenado en esa dirección usando el operador `*` (desreferencia). Es un ejemplo clave para entender cómo C maneja la memoria directamente.

5. **Funciones ([ejemplo5.c](ejemplo5.c))** 
   
   Este programa demuestra la estructura básica de las funciones en C. Aprenderás a declarar el prototipo de una función, a definir su implementación y a llamarla desde la función main. El ejemplo utiliza una función simple `sumar()` para ilustrar el paso de parámetros y el retorno de un valor.
6. **Paso de Argumentos por Valor y por Referencia ([ejemplo6.c](ejemplo6.c))**
   
   Este ejemplo es crucial para entender cómo las funciones manejan sus argumentos.
   * **Paso por Valor (`swap`)**: Muestra cómo una función recibe una copia de los datos originales, por lo que cualquier modificación interna no afecta a las variables fuera de la función.
   * **Paso por Referencia (`swap2`)**: Utilizando apuntadores, se muestra cómo pasar la dirección de memoria de una variable a una función. Esto permite que la función modifique directamente el valor original de la variable.


> [!important]
> El archivo [ejemplo1_template.c](ejemplo1_template.c) sirve como una plantilla unificada que contiene el código de todos los ejemplos anteriores, pero con la mayoría de las secciones comentadas. Es útil para experimentar y probar diferentes bloques de código en un solo lugar sin tener que cambiar de archivo.

> [!Note]
> **AI Disclosure:** This document was created with the assistance of Artificial Intelligence language models. The content has been reviewed, edited, and validated by a human author to ensure accuracy and quality.
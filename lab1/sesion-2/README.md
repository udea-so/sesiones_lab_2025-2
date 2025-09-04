# Sesión 2 - Introducción al lenguaje C

**Fecha**: 05/09/2025

## Introducción

En esta sesión se abordará el estudio del lenguaje C a partir de una comparación con los conocimientos previamente adquiridos en Java (y, en algunos casos, en Python), con el fin de facilitar la identificación de elementos comunes y de aquellos que representan novedades conceptuales y técnicas. Se iniciará con la revisión de la estructura básica del lenguaje y el proceso de compilación mediante `gcc`. Posteriormente, se profundizará en los aspectos que diferencian a C, tales como la gestión manual de la memoria, el uso de punteros, la relación entre arreglos y cadenas de caracteres, así como el paso de parámetros a funciones. Finalmente, se trabajará con el manejo de archivos y el control de errores mediante códigos de retorno, destacando las buenas prácticas necesarias para prevenir fugas de memoria y fallos de segmentación. El propósito es establecer un puente entre la experiencia previa en lenguajes de más alto nivel y las particularidades de C, entendido este como un lenguaje que opera en un nivel más cercano al hardware.

## Objetivos

1. Comprender la estructura fundamental de un programa en C y el proceso de compilación y ejecución mediante el compilador `gcc`.
2. Analizar el modelo de memoria en C, diferenciando entre memoria estática, automática y dinámica, y aplicar de manera correcta las funciones `malloc`, `calloc` y `free` para la gestión de memoria en el `heap`.
2. Dominar el uso de punteros para manipular variables, arreglos y cadenas de caracteres, así como para implementar paso de parámetros que permitan modificar valores fuera del ámbito local de una función.
4. Implementar funciones en C aplicando adecuadamente el paso por valor y el paso por referencia mediante punteros.
5. Manejar archivos en C utilizando punteros a `FILE`, comprendiendo las funciones principales para apertura, escritura, lectura y cierre de archivos, tanto en modo texto como en modo binario.
6. Aplicar buenas prácticas en C orientadas a la prevención de errores comunes, tales como accesos inválidos a memoria, punteros nulos o colgantes, fugas de memoria y fallos de segmentación (segmentation faults).


## Recursos

El curso de Sistemas operativos dispone de unos apuntes de clase: **Introducción al lenguaje C** [[link]](https://udea-so.github.io/intro-c/intro.html) en el cual se encuentran la mayoria de los conceptos de este lenguaje necesarios para trabajar a lo largo de los laboratorios. 


A continuación se listan las diferentes secciones resaltando las que tiene mayor importancia para el desarrollo de la practica:
- [x] Introducción al lenguaje C [[teoria]](https://udea-so.github.io/intro-c/content/CH_02-S01.html) 
- [x] Apuntadores y arreglos [[teoria]](https://udea-so.github.io/intro-c/content/CH_02-S02.html) [[ejemplos]](ejemplos_c/conceptos_c/punteros/README.md)
- [x] Apuntadores y matrices [[teoria]](https://udea-so.github.io/intro-c/content/CH_02-S03.html) [[ejemplos]](ejemplos_c/conceptos_c/arreglos_matrices/README.md)
- [ ] Estructuras [[teoria]](https://udea-so.github.io/intro-c/content/CH_02-S04.html) [[ejemplos]](ejemplos_c/conceptos_c/estructuras/README.md)
- [x] Memoria dinámica [[teoria]](https://udea-so.github.io/intro-c/content/CH_02-S05.html) [[ejemplos]](ejemplos_c/conceptos_c/reserva_dinamica_memoria/README.md)
- [ ] Archivos [[teoria]](https://github.com/dannymrock/UdeA-SO-Lab/blob/master/lab0/lab0b/parte6/README.md) [[ejemplos]](ejemplos_c/conceptos_c/archivos/README.md)
- [x] Argumentos por línea de comandos [[ejemplos]](ejemplos_c/conceptos_c/cmd_line_args/README.md)

## Reference sheet

> 1. **C Reference Card (ANSI)** [[link]
](CRefCard.v2.2.pdf)
> 2. **The C Cheat Sheet** (Andrew Sterian) [[link]](C.CheatSheet.pdf)

<br>

> [!Note]
> **AI Disclosure:** This document was created with the assistance of Artificial Intelligence language models. The content has been reviewed, edited, and validated by a human author to ensure accuracy and quality.
# Archivos de apoyo para la codificación de un shell

Este directorio contiene ejemplos prácticos que sirven como punto de partida para el desarrollo de un shell en C. Los archivos aquí incluidos sirven para ilustrar conceptos clave relacionados con la creación y manejo de comandos de para la practica

## Ejemplos incluidos

- [`cd.c`](cd.c): Ejemplo sobre la implementación del comando `cd` para cambiar de directorio.
- [`ejemplo2.c`](ejemplo2.c): Demostración de ejecución de comandos básicos en el shell.
- [`hola.c`](hola.c): Ejemplo introductorio para mostrar la estructura mínima de un programa en C.
- [`wish.c`](wish.c): Implementación básica de un shell sencillo, inspirado en el ejemplo del libro de Remzi.

Estos ejemplos se basan en la discusión presentada en el siguiente [enlace](https://pages.cs.wisc.edu/~remzi/Classes/537/Spring2009/Discussions/discuss-02-05-09/), la cual aborda los fundamentos para construir un shell propio y entender el funcionamiento de los comandos internos y externos.


> [!important]
> Cuando se ingresa argumentos por linea de comandos en C, una de las cosas que se debe realizar es **tokenizar** la cadena de texto ingresada por el usuario como comando con el fin de separar el comando de sus argumentos antes de poderlo lanzar. Se recomienta que mire los siguentes enlaces para entender para que sirve [[link1]](https://www.educative.io/answers/splitting-a-string-using-strtok-in-c)  [[link2]](https://systems-encyclopedia.cs.illinois.edu/articles/c-strtok/)  [[link3]](https://www.geeksforgeeks.org/cpp/strtok-strtok_r-functions-c-examples/) [[link4]](https://manual.cs50.io/3/strtok)


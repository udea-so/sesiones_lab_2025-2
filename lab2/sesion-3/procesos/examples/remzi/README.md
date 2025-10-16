# Ejemplos 2 - Ejemplo del libro de Remzi

Para profundizar en el manejo de procesos en C, se recomienda consultar el capítulo **Interlude: Process API** ([enlace](https://pages.cs.wisc.edu/~remzi/OSTEP/cpu-api.pdf)) del libro de Remzi. Los ejemplos presentados aquí también se encuentran en la sección **3.2. Ejemplos libro Remzi** ([enlace](https://udea-so.github.io/udea-so/docs/laboratorio/tutoriales/procesos/#32-ejemplos-libro-remzi)).

A continuación se describen brevemente los programas incluidos:

- **Creación Básica** ([`p1.c`](p1.c)): Este programa demuestra el uso fundamental de `fork()`, donde un proceso padre crea un clon de sí mismo llamado proceso hijo. Ambos se ejecutan de forma concurrente justo después de la llamada, lo que resulta en un orden de salida no garantizado, ilustrando el no determinismo del planificador del sistema operativo.
- **Espera Sincronizada** ([`p2.c`](p2.c)): Este ejemplo introduce `wait()`, mostrando cómo un proceso padre puede pausar su ejecución para esperar a que su proceso hijo termine. Al forzar al padre a esperar, el programa logra una salida predecible y ordenada, demostrando un método simple de sincronización entre procesos.
- **Ejecución de un Nuevo Programa** ([`p3.c`](p3.c)): Aquí se combina `fork()` con `execvp()`, ilustrando el patrón clásico de un shell. El proceso hijo se transforma a sí mismo para ejecutar un programa completamente nuevo (`wc`), mientras el padre espera su finalización, mostrando cómo se lanzan comandos externos en UNIX. Este programa es equivalente a ejecutar el siguiente comando desde la terminal de linux:
  
  ```
  prompt> wc p3.c
  ```

- **Redirección de Salida** ([`p4.c`](p4.c)): Este código avanzado demuestra la potencia de la separación entre `fork()` y `exec()`. El proceso hijo manipula sus descriptores de archivo antes de transformarse, cerrando la salida estándar (pantalla) y abriendo un archivo en su lugar, lo que permite redirigir la salida de un comando sin que este lo sepa. Este programa equivale a ejecutar, en la terminal, el siguiente comando en el que se hace redireacción: 
  
  ```
  prompt> wc p4.c > p4.output
  ```

* **Implementación de Tubería** ([p5.c](p5.c)): Este programa avanzado implementa una tubería (`|`) en C para replicar el comando `cat p5.c | wc`. Utiliza `pipe()` para crear un canal de comunicación y `fork()` dos veces para generar dos procesos hijos. El primer hijo (`cat`) redirige su salida estándar a la tubería, y el segundo (`wc`) redirige su entrada estándar para leer desde la misma tubería, demostrando un mecanismo fundamental de comunicación entre procesos (IPC) para encadenar comandos.
  
  ```
  prompt> cat p5.c | wc
  ```

Estos ejemplos son fundamentales para comprender la API de procesos en sistemas operativos tipo Unix y el comportamiento de la creación y sincronización de procesos en C.

> [!TIP]
> En el siguiente [link](./slides/05.Interlude_process_api.pdf) se encuentran unas diapositivas que resumen el capitulo **Interlude: Process API** del libro de Remzi. Apoyese en estas para comprender los ejemplos.

## Compilación y ejecución

Para compilar cualquiera de los ejemplos, utiliza el siguiente comando en la terminal:

```bash
gcc nombre_del_archivo.c -o nombre_del_ejecutable
```

Por ejemplo, para compilar y ejecutar `p1.c`:

```
gcc p1.c -o p1
./p1
```

Repita el proceso para los demás archivos (`p2.c`, `p3.c`, `p4.c`) cambiando el nombre según corresponda.


## Referencias

1. https://how.dev/answers/what-is-a-pipe-in-c
2. https://tldp.org/LDP/lpg/node11.html
3. https://cs-uob.github.io/COMSM0085/
4. https://www.rozmichelle.com/pipes-forks-dups/
5. https://www.geeksforgeeks.org/c/pipe-system-call/
6. http://www.unixwiz.net/techtips/remap-pipe-fds.html
7. https://github.com/liz753/pipex?tab=readme-ov-file
8. https://cs162.org/static/hw/hw-shell/
9. https://w3.cs.jmu.edu/kirkpams/OpenCSF/Books/csf/html/Pipes.html
10. https://web.eecs.utk.edu/~jplank/plank/classes/cs360/360/notes/Dup/lecture.html


> [!Note]
> **AI Disclosure:** This document was created with the assistance of Artificial Intelligence language models. The content has been reviewed, edited, and validated by a human author to ensure accuracy and quality.
# Ejemplos 2 - Ejemplo del libro de Remzi

Para profundizar en el manejo de procesos en C, se recomienda consultar el capítulo **Interlude: Process API** ([enlace](https://pages.cs.wisc.edu/~remzi/OSTEP/cpu-api.pdf)) del libro de Remzi. Los ejemplos presentados aquí también se encuentran en la sección **3.2. Ejemplos libro Remzi** ([enlace](https://udea-so.github.io/udea-so/docs/laboratorio/tutoriales/procesos/#32-ejemplos-libro-remzi)).

A continuación se describen brevemente los programas incluidos:

- [`p1.c`](p1.c): Ilustra la creación de un proceso hijo mediante `fork()`. El programa imprime mensajes desde el proceso padre y el hijo para mostrar la bifurcación.
- [`p2.c`](p2.c): Similar a `p1.c`, pero enfatiza la ejecución concurrente de ambos procesos y cómo ambos pueden ejecutar el mismo código tras el `fork()`.
- [`p3.c`](p3.c): Introduce el uso de `wait()`, permitiendo que el proceso padre espere a que el hijo finalice antes de continuar. Esto ejemplifica la sincronización básica entre procesos.
- [`p4.c`](p4.c): Demuestra que los procesos padre e hijo poseen variables independientes, evidenciando que cada uno tiene su propio espacio de memoria después del `fork()`.

Estos ejemplos son fundamentales para comprender la API de procesos en sistemas operativos tipo Unix y el comportamiento de la creación y sincronización de procesos en C.

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




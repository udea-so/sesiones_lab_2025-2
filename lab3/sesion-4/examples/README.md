# Guía de Programación Concurrente con Pthreads

Este documento sirve como una introducción al modelo de programación concurrente utilizando la biblioteca POSIX Threads (`pthread`). Inicialemente se cubren los conceptos teóricos esenciales antes de abordar la implementación práctica.

## 1. Conceptos Fundamentales

Antes de escribir código, es crucial comprender el modelo de hilos y los desafíos que introduce.

### 1.1. ¿Qué es un Hilo (Thread)?

Un **hilo** (o *thread*) es la unidad de ejecución más pequeña que puede ser gestionada por un sistema operativo. Un proceso tradicional consta de al menos un hilo (el "hilo principal").

La diferencia clave entre un **proceso** y un **hilo** es la gestión de la memoria:
* **Procesos:** Tienen espacios de memoria completamente separados. La comunicación entre procesos (IPC) es costosa y debe ser explícita (p. ej., *pipes*, *sockets*, memoria compartida).
* **Hilos:** Múltiples hilos *dentro de un mismo proceso* comparten el mismo espacio de memoria.

### 1.2. El Modelo de Memoria Compartida

Este es el pilar de la programación con hilos. Todos los hilos dentro de un proceso comparten:
* El segmento de código (las instrucciones del programa).
* El segmento de datos (variables globales y estáticas).
* El *heap* (memoria asignada dinámicamente, p. ej., con `malloc`).

Sin embargo, cada hilo tiene su **propia pila** (*stack*). Esto significa que las variables locales de una función son privadas para el hilo que está ejecutando esa función.

**Ventaja:** La comunicación es implícita y rápida. Si un hilo escribe en una variable global, todos los demás hilos ven el cambio instantáneamente.

**Desventaja:** Este modelo introduce nuevos y complejos tipos de errores, principalmente las **condiciones de carrera**.

### 1.3. Concurrencia vs. Paralelismo

Aunque a menudo se usan indistintamente, estos conceptos son distintos:
* **Concurrencia (Concurrency):** Se refiere a la capacidad de gestionar múltiples tareas *aparentemente* al mismo tiempo. En un sistema de un solo núcleo, el SO intercala la ejecución de los hilos (conmutación de contexto) para dar la ilusión de simultaneidad. El objetivo es gestionar recursos compartidos.
* **Paralelismo (Parallelism):** Se refiere a la ejecución *realmente* simultánea de múltiples tareas. Esto solo es posible en sistemas con múltiples núcleos de procesamiento. El objetivo es acelerar un cómputo dividiendo el trabajo.


### 1.4. El Problema: Condiciones de Carrera (Race Conditions)

En programas concurrentes, varios hilos pueden intentar modificar simultáneamente un mismo recurso.
Cuando esto ocurre sin una adecuada sincronización, se pueden producir resultados inconsistentes.

Una condición de carrera ocurre cuando el resultado de un cómputo depende del orden impredecible en que los hilos completan sus operaciones sobre un recurso compartido.
Este tipo de error no se debe a una falla en la lógica del programa, sino al entrelazamiento no controlado de las instrucciones de distintos hilos durante la ejecución.

Para ilustrar este problema, observe la siguiente función:

```c
/* The thread will execute in this function */
void *counting(void *end_value) {
    int i = 0;
    int upper = *((int *)end_value);    
    for (i = 1; i <= upper; i++) {
        // --- critical section ---
        count += 1;  
        // ------------------------
    }
    pthread_exit(0);
}   
```

El problema fundamental es que una operación aparentemente simple, como `count += 1`, no es atómica. A nivel de máquina, esta instrucción se descompone en tres etapas:
1. **Lectura**: el valor actual de count se copia desde la memoria principal a un registro del procesador.
2. **Modificación**: el registro incrementa su valor localmente.
3. **Escritura**: el nuevo valor se almacena nuevamente en la dirección de memoria asociada a count.

Estas tres etapas pueden intercalarse con las operaciones de otros hilos, produciendo resultados inconsistentes. El siguiente fragmento de código en ensamblador muestra esta secuencia:

```x86asm
mov 0x8049a1c, %eax   ; cargar count en EAX
add $0x1, %eax        ; incrementar el registro
mov %eax, 0x8049a1c   ; guardar nuevo valor en memoria
```

Imagine dos hilos (H1 y H2) ejecutando `count += 1` cuando `count` vale 5:

| Paso | Hilo 1 (instrucción ejecutada) | Hilo 2 (instrucción ejecutada) | PC       | EAX   | `counter`                   |
| :--: | :----------------------------- | :----------------------------- | :------- | :---- | :-------------------------- |
|   1  | `mov 0x8049a1c, %eax`          | —                              | `mov` H1 | **5** | 5                           |
|   2  | —                              | `mov 0x8049a1c, %eax`          | `mov` H2 | **5** | 5                           |
|   3  | `add $0x1, %eax`               | —                              | `add` H1 | **6** | 5                           |
|   4  | —                              | `add $0x1, %eax`               | `add` H2 | **6** | 5                           |
|   5  | `mov %eax, 0x8049a1c`          | —                              | `mov` H1 | **6** | **6**                       |
|   6  | —                              | `mov %eax, 0x8049a1c`          | `mov` H2 | **6** | 🔴 **6 (valor incorrecto)** |


El valor esperado para `count` era `7`. Sin embargo, debido a la ejecución concurrente sin sincronización, una de las actualizaciones se perdió y el resultado final fue `6`.

Este fenómeno se conoce **como condición de carrera** (**Race condition**). Para resolverlo, debemos garantizar que la sección crítica (count += 1) se ejecute de forma atómica; es decir, que ningún otro hilo pueda interrumpirla.

La solución conceptual es la **exclusión mutua**: solo un hilo puede estar dentro de la sección crítica a la vez. La herramienta estándar de pthreads para implementar esto es el **`mutex`**.

---

## 2. API Principal de `pthread`

La biblioteca `pthreads` es el estándar POSIX para la gestión de hilos en C.

### 2.1. Creación y Gestión de Hilos

La biblioteca proporciona funciones para manejar el ciclo de vida de un hilo.

* `pthread_create()`: Lanza un nuevo hilo que ejecutará una función específica.

    ```c
    #include <pthread.h>
    
    int pthread_create(
        pthread_t *thread,          // Puntero para almacenar el ID del nuevo hilo
        const pthread_attr_t *attr, // Atributos (usar NULL para default)
        void *(*start_routine)(void *), // Función que ejecutará el hilo
        void *arg                     // Argumento para pasar a la función
    );
    ```

* `pthread_join()`: Hace que el hilo llamante (p. ej., el `main`) espere a que un hilo específico termine su ejecución. Esto es crucial para sincronizar y asegurarse de que los resultados de un hilo están listos.

    ```c
    int pthread_join(
        pthread_t thread,   // ID del hilo que se debe esperar
        void **retval       // Puntero para recibir el valor de retorno del hilo (opcional)
    );
    ```

* `pthread_exit()`: Permite que un hilo termine su ejecución de forma explícita y, opcionalmente, devuelva un valor.

    ```c
    void pthread_exit(void *retval);
    ```

### 2.2. Sincronización: Exclusión Mutua (Mutex)

Como se demostró en el problema de la **Condición de Carrera** (sección 1.4), necesitamos un mecanismo para proteger la sección crítica (`count += 1`) y asegurar que solo un hilo pueda ejecutarla a la vez.

La herramienta fundamental para lograr esto es el **`mutex`** (**MUTual EXclusion**). Un `mutex` actúa como un "candado" (o *lock*) que un hilo debe "adquirir" antes de entrar a la sección crítica y "liberar" al salir.

Si un hilo intenta adquirir un mutex que ya está "tomado" por otro hilo, el sistema operativo bloqueará (pondrá a "dormir") al hilo solicitante. Este no despertará ni continuará su ejecución hasta que el hilo que posee el candado lo libere.


* `pthread_mutex_init()`: Inicializa un objeto mutex.
    ```c
    pthread_mutex_t my_mutex;
    pthread_mutex_init(&my_mutex, NULL); // NULL para atributos por defecto
    ```

* `pthread_mutex_lock()`: Adquiere el candado. Si está tomado, el hilo se bloquea.
    ```c
    pthread_mutex_lock(&my_mutex);
    // --- INICIO DE LA SECCIÓN CRÍTICA ---
    // ... código que accede al recurso compartido ...
    ```

* `pthread_mutex_unlock()`: Libera el candado, permitiendo que otros hilos bloqueados puedan adquirirlo.
    ```c
    // --- FIN DE LA SECCIÓN CRÍTICA ---
    pthread_mutex_unlock(&my_mutex);
    ```

* `pthread_mutex_destroy()`: Libera los recursos asociados al mutex.
    ```c
    pthread_mutex_destroy(&my_mutex);
    ```

Suponiendo que se tiene un `pthread_mutex_t` llamado `my_mutex` el código que asegura exclusión mutua queda de la siguiente manera:

```c
/* The thread will execute in this function */
void *counting(void *end_value) {
    int i = 0;
    int upper = *((int *)end_value);    
    for (i = 1; i <= upper; i++) {
        pthread_mutex_lock(&my_mutex);
        // --- critical section ---
        count += 1;  
        // ------------------------
        pthread_mutex_unlock(&my_mutex);
    }
    pthread_exit(0);
}   
```


---

## 3. Casos de Estudio y Ejemplos

Los archivos de código proporcionados ilustran estos conceptos.

### 3.1. Ejemplo 1: Creación y Espera (`example1.c`)

* **Objetivo:** Demostrar el ciclo de vida básico de un hilo.
* **Descripción:** El hilo `main` crea un único hilo `runner`. El hilo `runner` calcula la suma de 1 a N (pasado como argumento) y la almacena en la variable global `sum`.
* **Punto Clave:** El `main` debe ejecutar `pthread_join()` para esperar a que `runner` termine su cálculo antes de imprimir el resultado final. Si `main` no esperara, podría imprimir `sum` antes de que el cálculo haya finalizado (probablemente imprimiría 0).

### 3.2. Ejemplo 2 (Fallido): Condición de Carrera (`example2_rc.c`)

* **Objetivo:** Demostrar el peligro de las condiciones de carrera.
* **Descripción:** Se crean múltiples hilos. Cada hilo ejecuta la función `counting`, que incrementa la variable global `count` un total de `n` veces.
* **Resultado Esperado:** `count` debería ser `num_hilos * n`.
* **Resultado Real:** `count` es casi siempre *menor* que el valor esperado.
* **Análisis:** Como se explicó en la sección 1.4, la operación `count += 1` no es atómica. Múltiples hilos leen el mismo valor de `count` *antes* de que los otros hayan escrito su incremento, llevando a "actualizaciones perdidas". Este programa demuestra un error de concurrencia clásico.

### 3.3. Ejemplo 2 (Corregido): Uso de Mutex (`example2.c`)

* **Objetivo:** Solucionar la condición de carrera de `example2_rc.c` usando exclusión mutua.
* **Descripción:** El código es idéntico a `example2_rc.c`, pero introduce un `pthread_mutex_t` y lo inicializa/destruye.
* **Solución:** La función `counting` ahora "envuelve" la sección crítica (`count += 1`) con un `lock` y un `unlock`:
    ```c
    pthread_mutex_lock(&mutex); // Initialize lock
    // ---------- Start Critical section ----------
    count += 1;
    // ---------- End Critical section ----------
    pthread_mutex_unlock(&mutex); // Release lock
    ```
* **Resultado:** El programa ahora siempre produce el resultado esperado (`num_hilos * n`).
* **Contrapartida:** La sincronización tiene un costo. Esta versión es más lenta que la versión con condición de carrera (y más lenta que una versión serial), porque los hilos deben esperar en fila (serializarse) para acceder a la sección crítica. El objetivo aquí no es la velocidad, sino la **correctitud**.

### 3.4. Ejemplo 3: Paralelismo (`suma_s.c` vs `suma_p.c`)

* **Objetivo:** Demostrar cómo el paralelismo puede acelerar un cómputo divisible.
* **`suma_s.c` (Serial):** Calcula la suma de dos vectores (`v1` y `v2`) de gran tamaño (`TAMANO`) usando un único bucle `for`. Sirve como nuestra línea base (Benchmark) midiendo el tiempo de ejecución.
* **`suma_p.c` (Paralelo):**
    * **Estrategia:** Divide el trabajo. Utiliza el número de procesadores disponibles (`sysconf(_SC_NPROCESSORS_ONLN)`) para definir el número de hilos.
    * **Implementación:** La función `sumar_porcion_vector` recibe una estructura `thread_args_t` que le indica su `id` y el número total de hilos. Con esto, calcula qué "trozo" del vector le corresponde sumar (desde `inicio` hasta `fin`).
    * **Sincronización:** Note que en este caso **no se necesita mutex**. ¿Por qué? Porque los hilos no comparten datos *mutables*. Cada hilo escribe en una porción *diferente* del `vectorSuma` (`data->vectorSuma[i] = ...`). No hay superposición de escritura, por lo tanto, no hay condición de carrera.
    * **Resultado:** `suma_p.c` (que también mide su tiempo de ejecución) debería ejecutarse significativamente más rápido que `suma_s.c` en una máquina con múltiples núcleos, demostrando el poder del paralelismo.


## Referencias

* https://notes.shichao.io/apue/ch11/#chapter-11-threads
* 
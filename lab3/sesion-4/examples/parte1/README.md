## 3. Casos de Estudio y Ejemplos

Una vez revisados los fundamentos teóricos de los hilos, el modelo de memoria compartida, las condiciones de carrera y la exclusión mutua, esta sección se enfoca en su aplicación práctica. Los siguientes ejemplos ilustran el proceso, comenzando por la creación básica de un hilo, seguido de la implementación de una condición de carrera y su eventual solución.

### 3.1. Ejemplo 1: Creación de un Hilo (Fork-Join)

Este ejemplo constituye la implementación fundamental del patrón "fork-join" (discutido en la sección 2.1).

* **Propósito del código:** El hilo principal (`main`) instancia un único hilo de trabajo (denominado `runner`). Este hilo calcula la suma de los enteros del 1 a $N$ (argumento de entrada) y almacena el resultado en la variable global compartida `sum`. El hilo principal bloquea su ejecución (`pthread_join`) hasta que el hilo trabajador finaliza, momento en el cual imprime el resultado.
* **Compilación y Ejecución:**
    ```bash
    # Compilar (enlazando la biblioteca pthread)
    gcc -o example1 example1.c -lpthread
    
    # Ejecutar con un valor (ej. 1000)
    ./example1 1000
    ```

* **Análisis de Resultados:**
    La salida del programa mostrará la suma correcta (ej. `sum = 500500`). Este ejemplo demuestra el ciclo de vida básico: `pthread_create` para la "bifurcación" (fork) de la ejecución y `pthread_join` para la "unión" (join) de los hilos.

### 3.2. Ejemplo 2 (a): La Condición de Carrera (`example2_rc.c`)

Este ejemplo está diseñado para demostrar el problema central de la concurrencia: la **condición de carrera** (explicada en la sección 1.4).

* **Propósito del código:** El programa crea un número $T$ de hilos (`-t`). Cada uno de estos hilos incrementará un contador global (`count`) $N$ veces (`-n`). La operación `count += 1` se ejecuta en la sección crítica **sin ningún mecanismo de protección**.
* **Compilación y Ejecución:**
    
    ```bash
    # Compilar
    gcc -o example2_rc example2_rc.c -lpthread
    
    # Ejecutar con 2 hilos, cada uno contando 1 millón de veces
    ./example2_rc -t 2 -n 1000000
    ```

* **Análisis de Resultados:**
    El valor esperado (`expected`) es $T \times N$ (ej. 2,000,000). No obstante, se observará que el resultado real (`real`) es **generalmente incorrecto y menor** al esperado.

    Es instructivo ejecutar el programa múltiples veces. Se constatará que el resultado `real` no solo es incorrecto, sino que **varía en cada ejecución**. Esta es la demostración empírica de una condición de carrera: el resultado depende del orden impredecible de intercalación de hilos gestionado por el planificador del SO, lo cual provoca la pérdida de actualizaciones (como se detalló en la tabla de la sección 1.4).

### 3.3. Ejemplo 2 (b): La Solución con Mutex (`example2.c`)

Este ejemplo presenta la solución al problema anterior, aplicando el concepto de **exclusión mutua** (sección 2.2).

* **Propósito del código:** La lógica es idéntica a `example2_rc.c`, con la adición de un `pthread_mutex_t mutex`. La sección crítica (`count += 1`) está ahora protegida: `pthread_mutex_lock(&mutex)` es invocado antes de la operación, y `pthread_mutex_unlock(&mutex)` es invocado después.
* **Compilación y Ejecución:**
    
    ```bash
    # Compilar
    gcc -o example2 example2.c -lpthread
    
    # Ejecutar con los mismos parámetros que antes
    ./example2 -t 2 -n 1000000
    ```

* **Análisis de Resultados:**
    En esta ocasión, el resultado `real` será **exactamente igual** al `expected` (2,000,000), independientemente del número de ejecuciones.

    Mediante el uso del "candado" (mutex), se garantiza que solo un hilo puede acceder a la sección crítica en un momento dado. Esto serializa el acceso al recurso compartido, previene la intercalación de instrucciones no controlada y asegura la **corrección** del programa.

### 3.4. Archivos de Utilidad (`common.h` y `common_threads.h`)

* `common.h`: Provee la función `GetTime()`, una utilidad para la medición de tiempos de ejecución que será empleada en laboratorios subsecuentes (ej. `suma_p.c` y `suma_s.c`).
* `common_threads.h`: Define "wrappers" (macros) para las funciones de Pthreads, tales como `Pthread_create` o `Mutex_lock`. Estas macros optimizan el código al incluir `assert()`, lo que provoca una terminación abrupta del programa si ocurre un error (p. ej., fallo en `pthread_create`). Esto facilita la detección y depuración de errores en tiempo de ejecución.

### 3.5. Resultados del Aprendizaje

Al completar esta sección práctica, usted habrá:
* Compilado y ejecutado aplicaciones multi-hilo, enlazando la biblioteca `pthread` (`-lpthread`).
* Observado empíricamente la naturaleza no determinista de una condición de carrera.
* Validado la solución de una condición de carrera mediante la aplicación de exclusión mutua (`pthread_mutex_t`) para proteger secciones críticas.

> [!Note]
> **AI Disclosure:** This document was created with the assistance of Artificial Intelligence language models. The content has been reviewed, edited, and validated by a human author to ensure accuracy and quality.
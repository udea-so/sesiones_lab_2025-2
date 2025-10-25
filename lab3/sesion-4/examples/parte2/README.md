# Paralelismo y Medición de Desempeño 

## Análisis de Speedup en la Suma de Vectores con Pthreads

## 1. Objetivos del Laboratorio

1. Comprender la diferencia fundamental entre la ejecución serial y la paralela.
2. Implementar y medir el tiempo de ejecución de un algoritmo serial ($T_s$) y su contraparte paralela ($T_p$).
3. Analizar el impacto del número de hilos en el rendimiento de una aplicación.
4. Calcular y graficar métricas de desempeño clave: **Speedup** y **Eficiencia**.

## 2. Introducción Teórica

En la computación de alto rendimiento, buscamos reducir el tiempo de ejecución de tareas complejas. Una técnica es el paralelismo, donde dividimos un problema en partes más pequeñas y las ejecutamos simultáneamente en diferentes núcleos de la CPU.

En este laboratorio, analizaremos un problema "vergonzosamente paralelo" (la suma de vectores), donde cada cálculo es independiente. Mediremos:
* **Tiempo Serial ($T_s$)**: El tiempo que tarda el mejor algoritmo secuencial.
* **Tiempo Paralelo ($T_p$)**: El tiempo que tarda el algoritmo paralelo usando $N$ hilos.

Con esto, calcularemos dos métricas:
* **Speedup (Aceleración)**: Mide cuánto más rápida es la versión paralela.
  
$$
Speedup(N) = \frac{T_s}{T_p(N)}
$$
  
  Un Speedup "ideal" sería $N$ (si usamos $N$ hilos, tarda $1/N$ del tiempo).

* **Eficiencia**: Mide qué tan bien estamos utilizando los recursos (núcleos).
  
$$
Eficiencia(N) = \frac{Speedup(N)}{N}
$$
  
  Una eficiencia ideal es 1 (o 100%).

## 3. Archivos Proporcionados

* [suma_s.c](suma_s.c): Implementación serial de la suma de vectores. Se usará para medir $T_s$.
* [suma_p.c](suma_p.c): Implementación paralela con Pthreads. Se usará para medir $T_p$.
* [common.h](common.h): Contiene la función `GetTime()` para mediciones de tiempo precisas.
* [common_threads.h](common_threads.h): Contiene "wrappers" (envolturas) de las funciones `Pthreads` que añaden verificación de errores automática usando `assert`.
* [ejemplo_suma.c](ejemplo_suma.c): Un ejemplo de referencia sobre cómo usar malloc y free para la suma de vectores.

## 4. Procedimiento del Laboratorio

### Parte 1: Medición del Tiempo Serial ($T_s$)

El primer paso es establecer nuestra línea base (baseline).

1. Para eso, abra una terminal y compile la versión serial:
   
   ```Bash
   gcc -o suma_s suma_s.c -I. -Wall
   ```

2. Ejecute el programa con un tamaño de vector grande. Es importante que elija un tamaño lo suficientemente grande para que la ejecución tarde al menos 1 o 2 segundos.
   
   ```Bash
   # Pruebe con 100 millones de elementos
   ./suma_s 100000000
   ```

3. Ejecute el programa 3 veces y anote el tiempo reportado.  Calcule el promedio de los 3 tiempos. Este será tu valor de $T_s$ para todos los cálculos de Speedup.
   
### Parte 2: Modificación y Medición del Tiempo Paralelo ($T_p$)

Ahora usaremos la versión paralela. Antes de medir, mejore el código para usar los wrappers de `common_threads.h`, que es una buena práctica de programación defensiva.
1. Modifique `suma_p.c`: Para esto realice las siguientes tareas:
   * Añada el include: `#include "common_threads.h"` (puede añadirlo justo después de common.h).
   * Reemplace la llamada `pthread_create(...)` por la macro `Pthread_create(...)`.
   * Reemplace la llamada `pthread_join(...)` por la macro `Pthread_join(...)`. (**Nota**: Observe cómo el código se ve más limpio sin la necesidad de verificar el valor de retorno de cada función `Pthread`).
2. Compile la versión paralela (recuerda enlazar la biblioteca `pthread`): 
   
   ```Bash
   gcc -o suma_p suma_p.c -I. -Wall -lpthread
   ```

3. Realice las mediciones: Ejecute el programa con el mismo tamaño de vector que uso en la Parte 1, pero variando el número de hilos. 
   * Obtenga el número de núcleos de tu máquina (lo cual puede ser realizado usando `nproc` o `lscpu` en Linux). 
   * Ejecute el programa para $N = 1, 2, 4, 8, ...$ hilos. Siga duplicando hasta llegar al menos al doble de núcleos de tu CPU (ej. si tiene 8 núcleos, pruebe $N=1, 2, 4, 8, 16$).
   
   ```Bash
   # Ejemplo de ejecuciones (usa tu propio tamaño de vector)
   ./suma_p 100000000 1
   ./suma_p 100000000 2
   ./suma_p 100000000 4
   ./suma_p 100000000 8
   ./suma_p 100000000 16
   ```

## 5. Análisis de Resultados

1. **Recolección de Datos**: Complete una tabla similar a la siguiente con las mediciones realizadas (usando tu $T_s$ promedio de la Parte 1).

   |N (Hilos)|$T_p$​ (segundos)|Speedup $(T_s​/T_p)$​|Eficiencia ($Speedup/N$)|
   |---|---|---|---|
   |1|medida|$T_s / T_p(1)$|$Speedup(1) / 1$|
   |2|medida|$T_s / T_p(2)$|$Speedup(2) / 2$|
   |4|medida|$T_s / T_p(4)$|$Speedup(4) / 4$|
   |8|medida|$T_s / T_p(8)$|$Speedup(8) / 8$|
   |16|medida|$T_s / T_p(16)$|$Speedup(16) / 16$|

2. **Graficas**: Realice dos gráficos usando una hoja de cálculo (Excel, Google Sheets) o un notebook de jupyter.
   * **Gráfico 1**: Speedup vs. Número de Hilos (N).
   * **Gráfico 2**: Eficiencia vs. Número de Hilos (N).

6. **Preguntas de Análisis (Para entregar)**

Responda a las siguientes preguntas basándote en la tabla y gráficos:
1. **Comparación $T_s$ vs. $T_p(1)$**: ¿Cómo se compara el tiempo serial ($T_s$ de `suma_s`) con el tiempo paralelo usando 1 solo hilo ($T_p(1)$ de `suma_p`)? ¿Por qué cree que $T_p(1)$ es (probablemente) más lento?
2. **Análisis de Speedup**:
   * ¿Cuál es el Speedup máximo que obtuvo? 
   * ¿Con cuántos hilos se produjo?
   * ¿Cómo se compara su Speedup máximo con el número de núcleos físicos de su CPU? 
   * El Speedup "ideal" para $N$ hilos es $N$. ¿Por qué el Speedup "real" es menor que el ideal? (Mencione al menos dos razones).
3. **Análisis de Eficiencia**:
   * ¿Qué le ocurre a la eficiencia a medida que aumenta el número de hilos?
   * ¿Por qué cree que ocurre este fenómeno?
4. **Ley de Amdahl (Análisis de Overhead)**: El tiempo $T_p$ incluye no solo el cálculo (`sumar_porcion_vector`), sino también el overhead de crear (`Pthread_create`) y esperar (`Pthread_join`) los hilos. ¿Cómo contribuye este overhead a la pérdida de eficiencia?
5. **Sobrecarga (Context Switching)**: ¿Qué observo cuando usaso un número de hilos mayor al número de núcleos de tu CPU? (Ej. 16 hilos en una CPU de 8 núcleos). ¿El rendimiento mejoró o empeoró en ese punto? ¿Por qué?

## 6. Resultados del Aprendizaje

Al final de este laboratorio aprendiste a:
* Comparar el rendimiento de una implementación serial (`suma_s.c`) frente a una implementación paralela (`suma_p.c`) que utiliza `Pthreads`.
* Establecer un tiempo base de referencia ($T_s$) midiendo la ejecución del código serial.
* Medir el tiempo de ejecución paralelo ($T_p$) para un número variable de hilos ($N$), utilizando herramientas de precisión como `GetTime()`.
* Calcular métricas fundamentales del paralelismo, como el Speedup ($T_s / T_p$) y la Eficiencia ($Speedup / N$).
* Analizar los datos obtenidos para cuantificar la ganancia de rendimiento, observar los límites de la aceleración y comprender cómo factores como el overhead (creación y sincronización de hilos) y la saturación de los núcleos impactan el desempeño.

> [!Note]
> **AI Disclosure:** This document was created with the assistance of Artificial Intelligence language models. The content has been reviewed, edited, and validated by a human author to ensure accuracy and quality.
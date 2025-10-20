# Concurrencia

## 1. Conceptos claves

### 1.1 ¿Qué es un Hilo (Thread)?
### 1.2. El Modelo de Memoria Compartida

### 1.3. API Thread

```
pthread_t thread_id;  
```

#### 1.3.1 Creación y gestion de hilos

La biblioteca `pthreads` proporciona funciones para manejar el ciclo de vida de un hilo.
* `pthread_create()`: Lanza un nuevo hilo que ejecutará una función específica.
  
  ```c
  // Create thread
  pthread_create(&thread_id, NULL, thread_function, NULL);
  ```
* `pthread_join()`: Hace que el hilo principal (o cualquier otro hilo) espere a que un hilo específico termine su ejecución. Esto es crucial para sincronizar y asegurarse de que los resultados de un hilo están listos antes de continuar.
  
  ```c
  // Wait for threads to complete
  pthread_join(thread_id, NULL);
  ```
  
* `pthread_exit()`: Permite que un hilo termine su ejecución de forma explícita.

  ```c
  // Terminate Thread
  pthread_exit(NULL);
  ```

#### 1.3.1 Sincronización

Para evitar las condiciones de carrera, se necesitan mecanismos de sincronización. El más básico y fundamental es el **mutex** (**MUTual EXclusion**).

Un **mutex** es como un **"candado"**. Antes de acceder a un recurso compartido (como una variable global), un hilo debe **"adquirir"** el candado. Mientras lo tenga, ningún otro hilo que intente adquirir el mismo candado podrá hacerlo y tendrá que esperar. Una vez que el hilo termina de usar el recurso, **"libera"** el candado para que otro pueda tomarlo.

A coninuación se muestran las funciones claves relacionadas:
* `pthread_mutex_init()`: Inicializa un mutex.
* `pthread_mutex_lock()`: Adquiere el candado. Si ya está tomado, el hilo se bloquea.
* `pthread_mutex_unlock()`: Libera el candado.
* `pthread_mutex_destroy()`: Libera los recursos del mutex.


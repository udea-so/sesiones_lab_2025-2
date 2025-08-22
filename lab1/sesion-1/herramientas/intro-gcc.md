# Introducción al compilador `gcc`

Para la práctica con tener claro los siguientes comandos del compilador **`gcc`** es suficiente:

1. Generación del ejecutable:
   
   ```
   gcc archivoFuente –o nombreEjecutable -Wall
   ```
   
2. Corriendo el ejecutable:
   
   ```
   ./nombreEjecutable
   ```

Por ejemplo, suponiendo que se tiene un archivo fuente con el siguiente llamado [`hola_mundo.c`](./code/hola_mundo.c):

```c
#include <stdio.h>

int main() {
  printf("Hola mundo\n");
  return 0;
}
```

Si deseamos crear un ejecutable llamado `hola_mundo.out`, entonces el comando para compilar es:

```
gcc hola_mundo.c –o hola_mundo.out -Wall
```

Luego, para correr el ejecutable el comando será:

```
./hola_mundo.out
```

#### Material de apoyo

> 1. **Laboratory: Tutorial** 
> 2. **Una Introducción a GCC** (MIT) [[link]](https://www.nongnu.org/gccintro-es/gccintro.es.pdf)

#### Reference sheet

> **ECE 2400 Linux, Git, C/C++ Cheat Sheet** [[link]](../summary/ece2400-cheat-sheet.pdf)
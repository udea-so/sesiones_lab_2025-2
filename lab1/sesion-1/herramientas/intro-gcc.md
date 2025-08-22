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

A continuación se muestran algunas configuraciones de compilación de gcc que pueden ser de utilidad aplicadas al ejemplo analizado:

```
gcc -o hola_mundo.out hola_mundo.c      # -o: para especificar el nombre del ejecutable
gcc -Wall hola_mundo.c                  # -Wall: da advertencias mucho mejores
gcc -g hola_mundo.c                     # -g: para habilitar la depuración con gdb
gcc -O hola_mundo.c                     # -O: para activar la optimización
```

Es posible mezclar y combinar las banderas anteriormente mencionadas (ej., `gcc -o hola_mundo.out -g -Wall hola_mundo.c`). Para el caso, usar la bandera `-Wall` proporciona muchas más advertencias sobre posibles problemas. ¡Es importante no ignorar las advertencias!.

#### Material de apoyo

> 1. **Laboratory: Tutorial**  [[link]](https://pages.cs.wisc.edu/~remzi/OSTEP/lab-tutorial.pdf)
> 2. **Una Introducción a GCC** [[link]](https://www.nongnu.org/gccintro-es/gccintro.es.pdf)

#### Reference sheet

> **ECE 2400 Linux, Git, C/C++ Cheat Sheet** [[link]](../summary/ece2400-cheat-sheet.pdf)
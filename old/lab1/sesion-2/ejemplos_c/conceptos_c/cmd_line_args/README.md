# Argumentos por linea de comandos


## Actividad

Descargue el archivo [cmd_line_examples.zip](cmd_line_examples.zip), descomprimalo e ingrese al directorio resultante:

```bash
cd file_examples
```

Una vez allí, liste los archivos en este directorio y verifique que se encuentre el archivo `Makefile`:

```bash
ls
```

Luego, compile y genere los ejecutables mediante el siguiente comando:

```bash
make
```

Si todo sale bien, por cada archivo fuente (`.c`) se genera un archivo ejecutable cuyo nombre será el mismo del archivo fuente si na extención. 

Para ejecutar los ejemplos use el nombre del archivo resultante al compilar sin tener en cuenta la extención (`.c`). Por ejemplo, si el archivo se llama `ejemplo.c`, para ejecutar el archivo generado por el makefile use el siguiente comando comando:

```bash
./ejemplo
```

## Ejemplos

Analice y ejecute la siguiente lista de ejemplos:

1. [cmd_line_args01.c](#ejemplo-1)
2. [cmd_line_args02.c](#ejemplo-2)

### Ejemplo 1

**Archivo**: [cmd_line_args01.c](cmd_line_args01.c)

```c
/*
Author: Adalbert Gerald Soosai Raj
URL: https://pages.cs.wisc.edu/~gerald/cs354/Spring2019/code/lecture03/cmd_line_args01.c
*/

#include <stdio.h>
#include <stdlib.h>

// Argument vector (argv) is declared as an array of pointers to characters.
int main(int argc, char *argv[])
{
    int i;

    if (argc != 4) {
        fprintf(stderr, "USAGE: %s <name> <age> <alpha>\n", argv[0]);
        exit(1);
    }
    
    for (i = 0; i < 4; ++i) {
        printf("argv[%d] = %s\n", i, argv[i]);
    }

    return 0;
}
```

Para ejecutar use el comando:

* **Test 1**:
  
  ```
  ./cmd_line_args01
  ```

* **Test 2**:

```
./cmd_line_args01 pepe 10 0.2
```

### Ejemplo 2

**Archivo**: [cmd_line_args02.c](cmd_line_args02.c)

```c
/*
Author: Adalbert Gerald Soosai Raj
URL: https://pages.cs.wisc.edu/~gerald/cs354/Spring2019/code/lecture03/cmd_line_args02.c
*/

#include <stdio.h>
#include <stdlib.h>

// Argument vector (argv) is declared as a pointer to a character pointer.
// In other words, argv is a pointer to a pointer to a character.
int main(int argc, char **argv)
{
    int i;

    if (argc != 4) {
        fprintf(stderr, "USAGE: %s <name> <age> <alpha>\n", argv[0]);
        exit(1);
    }
    
    for (i = 0; i < 4; ++i) {
        printf("argv[%d] = %s\n", i, argv[i]);
    }

    return 0;
}
```

Para ejecutar use el comando:

* **Test 1**:
  
  ```
  ./cmd_line_args02
  ```

* **Test 2**:

```
./cmd_line_args02 pepe 10 0.2
```

## Referencias teoricas

A continuación se muestran algunos apuntes de clase que ilustran algunos conceptos teoricos necesarios para comprender la lista de ejemplos adjuntos:

* **Command Line Arguments** [[link]](https://diveintosystems.org/book/C2-C_depth/advanced_cmd_line_args.html)

## Enlaces

* https://diveintosystems.org/
* https://docs.google.com/document/d/1YyOs7Az5JodqKscj5KiPl0ZpxAUMZ6d9EYIPxUrsGig/edit
* https://docs.google.com/document/d/1EGIRt1JSe1Dh2UclyVkEufg2ExJKUBWdaH3SYTsoNF0/edit#heading=h.sxobt3v8bjei
* https://docs.google.com/document/d/1YyOs7Az5JodqKscj5KiPl0ZpxAUMZ6d9EYIPxUrsGig/edit#heading=h.9zrjc4s0l7tx
# Archivos

## Actividad

Descargue el archivo [file_examples.zip](file_examples.zip), descomprimalo e ingrese al directorio resultante:

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

# Ejemplo

El siguiente ejemplo contiene los siguientes archivos:
* **Archivo fuente**: [file-io.c](file-io.c)
* **Archivo de texto**: [foo.txt](foo.txt)

A continuación se muestra el archivo fuente: [file-io.c](file-io.c)

```c
/*
Author: Adalbert Gerald Soosai Raj
URL: https://pages.cs.wisc.edu/~gerald/cs354/Spring2019/code/lecture05/file-io.c
*/


#include <stdio.h>

#define MAX 10

int main() {
    FILE *fp;
    char buff[MAX];

    fp = fopen("foo.txt", "r");
    
    while (fgets(buff, MAX, fp)) {
        printf("%s", buff);
    }
    fclose(fp);

    fp = fopen("bar.bin", "wb");
    int num = 0x12345678;
    fwrite(&num, sizeof(int), 1, fp);
    fclose(fp);
 
    fp = fopen("bar.bin", "rb");
    int readNum;
    fread(&readNum, sizeof(int), 1, fp);
    printf("readNum = 0x%x\n", readNum);
    fclose(fp);

    return 0;
}
```

Para ejecutar use el comando:

```
./file-io
```


## Referencias teoricas

A continuación se muestran algunos apuntes de clase que ilustran algunos conceptos teoricos necesarios para comprender la lista de ejemplos adjuntos:

* **Manejo de archivos en C**[[link]](https://github.com/dannymrock/UdeA-SO-Lab/blob/master/lab0/lab0b/parte6/README.md)
* **Input / Output in C** [[link]](https://diveintosystems.org/book/C2-C_depth/IO.html)

## Enlaces

* https://diveintosystems.org/
* https://docs.google.com/document/d/1YyOs7Az5JodqKscj5KiPl0ZpxAUMZ6d9EYIPxUrsGig/edit
* https://docs.google.com/document/d/1EGIRt1JSe1Dh2UclyVkEufg2ExJKUBWdaH3SYTsoNF0/edit#heading=h.sxobt3v8bjei
* https://docs.google.com/document/d/1YyOs7Az5JodqKscj5KiPl0ZpxAUMZ6d9EYIPxUrsGig/edit#heading=h.9zrjc4s0l7tx
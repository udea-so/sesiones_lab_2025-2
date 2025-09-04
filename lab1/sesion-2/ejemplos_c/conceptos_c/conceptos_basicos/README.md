# Conceptos Básicos en C y Java

Este directorio contiene ejemplos sencillos para ilustrar conceptos fundamentales de programación en C y Java.

## Archivos incluidos

- [`helloworld.c`](helloworld.c): Ejemplo de programa básico en C que imprime un mensaje en pantalla.
- [`cylinder.c`](cylinder.c): Cálculo del volumen de un cilindro usando variables y entrada estándar.
- [`pointers.c`](pointers.c): Ejemplo sobre el uso de punteros en C.
- [`HelloWorld.java`](HelloWorld.java): Programa básico en Java que imprime un mensaje.
- [`VolumeOfCylinder.java`](VolumeOfCylinder.java): Cálculo del volumen de un cilindro en Java.

## Conceptos cubiertos

- Estructura básica de un programa en C y Java
- Entrada y salida estándar
- Uso de variables
- Operaciones aritméticas
- Punteros (C)
- Compilación y ejecución de programas

## Compilación y ejecución

### Archivos en C

#### helloworld.c

```bash
gcc helloworld.c -o helloworld
./helloworld
```

#### cylinder.c

```bash
gcc cylinder.c -o cylinder
./cylinder
```

#### pointers.c

```bash
gcc pointers.c -o pointers
./pointers
```

> [!Important]
> Analice el funcionamiento del codigo anterior siguiendo el siguiente [link](https://pythontutor.com/render.html#code=%23include%20%3Cstdio.h%3E%0A%0Aint%20main%28%29%20%7B%0A%20%20%20%20int%20num%20%3D%2010%3B%0A%20%20%20%20int%20*%20pnum%20%3D%20%26num%3B%0A%20%20%20%20printf%28%22num%20%3D%20%25d%5Cn%22,%20num%29%3B%0A%20%20%20%20printf%28%22*pnum%20%3D%20%25d%5Cn%22,%20*pnum%29%3B%0A%20%20%20%20printf%28%22%26num%20%3D%20%25p%5Cn%22,%20%26num%29%3B%0A%20%20%20%20printf%28%22pnum%20%3D%20%25p%5Cn%22,%20pnum%29%3B%0A%20%20%20%20%2B%2Bpnum%3B%0A%20%20%20%20printf%28%22pnum%20%3D%20%25p%5Cn%22,%20pnum%29%3B%0A%20%20%20%20%0A%20%20%20%20int%20arr%5B5%5D%20%3D%20%7B10,%2020,%2030,%2040%20,50%7D%3B%0A%20%20%20%20int%20*%20parr%20%3D%20%26arr%5B0%5D%3B%0A%20%20%20%20%0A%20%20%20%20int%20i%3B%0A%20%20%20%20for%20%28i%20%3D%200%3B%20i%20%3C%205%3B%20i%2B%2B%29%20%7B%0A%20%20%20%20%20%20%20%20printf%28%22%25d%5Cn%22,%20arr%5Bi%5D%29%3B%0A%20%20%20%20%7D%0A%20%20%20%20printf%28%22%5Cn%22%29%3B%0A%20%20%20%20for%20%28i%20%3D%200%3B%20i%20%3C%205%3B%20i%2B%2B%29%20%7B%0A%20%20%20%20%20%20%20%20printf%28%22%25p%5Ct%22,%20parr%29%3B%0A%20%20%20%20%20%20%20%20printf%28%22%25d%5Cn%22,%20*parr%29%3B%0A%20%20%20%20%20%20%20%20parr%2B%2B%3B%0A%20%20%20%20%7D%0A%20%20%20%20%0A%20%20%20%20return%200%3B%0A%7D&cumulative=false&curInstr=0&heapPrimitives=nevernest&mode=display&origin=opt-frontend.js&py=c_gcc9.3.0&rawInputLstJSON=%5B%5D&textReferences=false)

### Archivos en Java

#### HelloWorld.java

```bash
javac HelloWorld.java
java HelloWorld
```

#### VolumeOfCylinder.java

```bash
javac VolumeOfCylinder.java
java VolumeOfCylinder
```

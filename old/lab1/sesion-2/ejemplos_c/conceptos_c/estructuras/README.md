# Estructuras

## Actividad

Descargue el archivo [structs_examples.zip](structs_examples.zip), descomprimalo e ingrese al directorio resultante:

```bash
cd structs_examples
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

1. [structs01.c](#ejemplo-1)
2. [structs02.c](#ejemplo-2)
3. [structs03.c](#ejemplo-3)
4. [structs04.c](#ejemplo-4)
5. [structs05.c](#ejemplo-5)
6. [structs06.c](#ejemplo-6)
7. [structs07.c](#ejemplo-7)

### Ejemplo 1

**Archivo**: [structs01.c](structs01.c)

```c
/*
Book: Programming in C
Author: Stephen G. Kochan
*/

#include <stdio.h>

int main(void) {
    struct date {
        int month;
        int day;
        int year;
    };
    struct date today;
    
    today.month = 9;
    today.day = 25;
    today.year = 2004;

    printf("Today's date is %i/%i/%.2i.\n", today.month, today.day,
           today.year);
    return 0;
}
```

Para ejecutar use el comando:

```
./structs01
```

### Ejemplo 2

**Archivo**: [structs02.c](structs02.c)

```c
/*
Book: Programming in C
Author: Stephen G. Kochan
*/

// Program to determine tomorrow's date
#include <stdio.h>

int main(void) {
    struct date {
        int month;
        int day;
        int year;
    };
    
    struct date today, tomorrow;

    const int daysPerMonth[12] = {31, 28, 31, 30, 31, 30,
                                  31, 31, 30, 31, 30, 31};
    
    printf("Enter today's date (mm dd yyyy): ");
    scanf("%i%i%i", &today.month, &today.day, &today.year);
    
    if (today.day != daysPerMonth[today.month - 1]) {
        tomorrow.day = today.day + 1;
        tomorrow.month = today.month;
        tomorrow.year = today.year;
    }
    else if (today.month == 12) { // end of year
        tomorrow.day = 1;
        tomorrow.month = 1;
        tomorrow.year = today.year + 1;
    }
    else { // end of month
        tomorrow.day = 1;
        tomorrow.month = today.month + 1;
        tomorrow.year = today.year;
    }

    printf("Tomorrow's date is %i/%i/%.2i.\n", tomorrow.month,
           tomorrow.day, tomorrow.year);
    return 0;
}
```

Para ejecutar use el comando:

```
./structs02
```

### Ejemplo 3

**Archivo**: [structs03.c](structs03.c)

```c
/*
Book: Programming in C
Author: Stephen G. Kochan
*/

// Program to determine tomorrow's date
#include <stdio.h>
#include <stdbool.h>

struct date {
    int month;
    int day;
    int year;
};

int numberOfDays(struct date);
bool isLeapYear(struct date);
struct date dateUpdate1(struct date);
struct date dateUpdate2(struct date);

int main(void) {
    struct date dateUpdate(struct date today);
    struct date thisDay, nextDay;
    printf("Enter today's date (mm dd yyyy): ");
    scanf("%i%i%i", &thisDay.month, &thisDay.day,
          &thisDay.year);
    // Get next day using dateUpdate1
    nextDay = dateUpdate1(thisDay);
    printf("Tomorrow's date is %i/%i/%.2i.\n", nextDay.month,
           nextDay.day, nextDay.year);
           
    // Get next day using dateUpdate2 (The result is te same)
    nextDay = dateUpdate2(thisDay);
    printf("Tomorrow's date is %i/%i/%.2i.\n", nextDay.month,
           nextDay.day, nextDay.year);
    return 0;
}

// Function to calculate tomorrow's date
struct date dateUpdate1(struct date today) {
    struct date tomorrow;
    int numberOfDays(struct date d);
    if (today.day != numberOfDays(today))
    {
        tomorrow.day = today.day + 1;
        tomorrow.month = today.month;
        tomorrow.year = today.year;
    }
    else if (today.month == 12)
    { // end of year
        tomorrow.day = 1;
        tomorrow.month = 1;
        tomorrow.year = today.year + 1;
    }
    else
    { // end of month
        tomorrow.day = 1;
        tomorrow.month = today.month + 1;
        tomorrow.year = today.year;
    }
    return tomorrow;
}

// Function to calculate tomorrow's date â€“ using compound literals
struct date dateUpdate2(struct date today) {
    struct date tomorrow;
    int numberOfDays(struct date d);
    if (today.day != numberOfDays(today))
        tomorrow = (struct date){today.month, today.day + 1, today.year};
    else if (today.month == 12) // end of year
        tomorrow = (struct date){1, 1, today.year + 1};
    else // end of month
        tomorrow = (struct date){today.month + 1, 1, today.year};
    return tomorrow;
}

// Function to find the number of days in a month
int numberOfDays(struct date d) {
    int days;
    bool isLeapYear(struct date d);
    const int daysPerMonth[12] =
        {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (isLeapYear(d) == true && d.month == 2)
        days = 29;
    else
        days = daysPerMonth[d.month - 1];
    return days;
}

// Function to determine if it's a leap year
bool isLeapYear(struct date d) {
    bool leapYearFlag;
    if ((d.year % 4 == 0 && d.year % 100 != 0) ||
        d.year % 400 == 0)
        leapYearFlag = true; // It's a leap year
    else
        leapYearFlag = false; // Not a leap year
    return leapYearFlag;
}
```

Para ejecutar use el comando:

```
./structs03
```


### Ejemplo 4

**Archivo**: [structs04.c](structs04.c)

```c
/*
Book: Programming in C
Author: Stephen G. Kochan
*/

// Program to update the time by one second

#include <stdio.h>
struct time {
    int hour;
    int minutes;
    int seconds;
};

struct time timeUpdate(struct time);

int main(void) {
    struct time timeUpdate(struct time now);
    struct time currentTime, nextTime;
    printf("Enter the time (hh:mm:ss): ");
    scanf("%i:%i:%i", &currentTime.hour,
          &currentTime.minutes, &currentTime.seconds);
    nextTime = timeUpdate(currentTime);
    printf("Updated time is %.2i:%.2i:%.2i\n", nextTime.hour,
           nextTime.minutes, nextTime.seconds);
    return 0;
}

// Function to update the time by one second
struct time timeUpdate(struct time now) {
    ++now.seconds;
    if (now.seconds == 60) { // next minute
        now.seconds = 0;
        ++now.minutes;
        if (now.minutes == 60) { // next hour
            now.minutes = 0;
            ++now.hour;
            if (now.hour == 24) // midnight
                now.hour = 0;
        }
    }
    return now;
}
```

Para ejecutar use el comando:

```
./structs04
```

### Ejemplo 5

**Archivo**: [structs05.c](structs05.c)

```c
/*
Book: Programming in C
Author: Stephen G. Kochan
*/

// Program to illustrate arrays of structures
#include <stdio.h>

struct time {
    int hour;
    int minutes;
    int seconds;
};

struct time timeUpdate(struct time);

int main(void) {
    struct time timeUpdate(struct time now);
    struct time testTimes[5] =
        {{11, 59, 59}, {12, 0, 0}, {1, 29, 59}, {23, 59, 59}, {19, 12, 27}};
    int i;
    for (i = 0; i < 5; ++i) {
        printf("Time is %.2i:%.2i:%.2i", testTimes[i].hour,
               testTimes[i].minutes, testTimes[i].seconds);
        testTimes[i] = timeUpdate(testTimes[i]);
        printf(" ...one second later it's %.2i:%.2i:%.2i\n",
               testTimes[i].hour, testTimes[i].minutes, testTimes[i].seconds);
    }
    return 0;
}

// Function to update the time by one second
struct time timeUpdate(struct time now) {
    ++now.seconds;
    if (now.seconds == 60) { // next minute
        now.seconds = 0;
        ++now.minutes;
        if (now.minutes == 60) { // next hour
            now.minutes = 0;
            ++now.hour;
            if (now.hour == 24) { // midnight
                now.hour = 0;
            }
        }
    }
    return now;
}
```

Para ejecutar use el comando:

```
./structs05
```

### Ejemplo 6

**Archivo**: [structs06.c](structs06.c)

```c
/*
Book: Programming in C
Author: Stephen G. Kochan
*/

// Program to illustrate structures and arrays

#include <stdio.h>

int main(void)
{
    int i;
    struct month
    {
        int numberOfDays;
        char name[3];
    };

    const struct month months[12] = {
                                        {31, {'J', 'a', 'n'}}, 
                                        {28, {'F', 'e', 'b'}}, 
                                        {31, {'M', 'a', 'r'}}, 
                                        {30, {'A', 'p', 'r'}}, 
                                        {31, {'M', 'a', 'y'}}, 
                                        {30, {'J', 'u', 'n'}}, 
                                        {31, {'J', 'u', 'l'}}, 
                                        {31, {'A', 'u', 'g'}}, 
                                        {30, {'S', 'e', 'p'}}, 
                                        {31, {'O', 'c', 't'}}, 
                                        {30, {'N', 'o', 'v'}}, 
                                        {31, {'D', 'e', 'c'}}
                                    };

    printf("Month Number of Days\n");
    printf("----- --------------\n");

    for (i = 0; i < 12; ++i) {
        printf(" %c%c%c %i\n",
               months[i].name[0], months[i].name[1],
               months[i].name[2], months[i].numberOfDays);
        }
    return 0;
}
```

Para ejecutar use el comando:

```
./structs06
```

### Ejemplo 7

**Archivo**: [structs07.c](structs07.c)

```c
/*
Book: Advanced Topics in C
Author: Noel Kalicharan
URL: https://github.com/Apress/adv-topics-in-c/blob/master/P21SortSearchStruct.c
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>

#define MaxStudents 100
#define MaxNameLength 30
#define MaxNameBuffer MaxNameLength+1

typedef struct {
	char name[MaxNameBuffer];
	int age;
	char gender;
} Student;

void printStudent(Student);
int getData(FILE *, Student []);
int search(char [], Student [], int);
void sort(Student [], int);
void getString(FILE *, char []) ;
char readChar(FILE *);

int main() {
	Student pupil[MaxStudents];
	char aName[MaxNameBuffer];

	FILE * in = fopen("input.txt", "r");
	if (in == NULL) {
		printf("Error opening file: %s.\n", strerror(errno));
		exit(1);
	}

	int numStudents = getData(in, pupil);
	if (numStudents == 0) {
		printf("No data supplied for students");
		exit(1);
	}

  printf("\n");
  for (int h = 0; h < numStudents; h++) printStudent(pupil[h]);
	printf("\n");

	getString(in, aName);
	while (strcmp(aName, "END") != 0) {
		int ans = search(aName, pupil, numStudents);
		if (ans == -1) printf("%s not found\n", aName);
		else printf("%s found at location %d\n", aName, ans);
		getString(in, aName);
	}

	sort(pupil, numStudents);
	printf("\n");
  for (int h = 0; h < numStudents; h++) printStudent(pupil[h]);
} //end main

void printStudent(Student t) {
	printf("Name: %s Age: %d Gender: %c\n", t.name, t.age, t.gender);
} //end printStudent

int getData(FILE *in, Student list[]) {
	char temp[MaxNameBuffer];
	void getString(FILE *, char[]);
	char readChar(FILE *);

  int n = 0;
  getString(in, temp);
	while (n < MaxStudents && strcmp(temp, "END") != 0) {
		strcpy(list[n].name, temp);
		fscanf(in, "%d", &list[n].age);
		list[n].gender = readChar(in);
		n++;
		getString(in, temp);
	}
	return n;
} //end getData

int search(char key[], Student list[], int n) {
//search for key in list[0] to list[n-1]
//if found, return the location; if not found, return -1
	for (int h = 0; h < n; h++)
		if (strcmp(key, list[h].name) == 0) return h;
	return -1;
} //end search

void sort(Student list[], int n) {
//sort list[0] to list[n-1] by name using an insertion sort
	for (int h = 1; h < n; h++) {
		Student temp = list[h];
		int k = h - 1;
		while (k >= 0 && strcmp(temp.name, list[k].name) < 0) {
			list[k + 1] = list[k];
			k = k - 1;
		}
    list[k + 1] = temp;
	} //end for
} //end sort

void getString(FILE * in, char str[]) {
//stores, in str, the next string within delimiters
// the first non-whitespace character is the delimiter
// the string is read from the file 'in'

	char ch, delim;
	int n = 0;
	str[0] = '\0';
	// read over white space
	while (isspace(ch = getc(in))) ; //empty while body
	if (ch == EOF) return;

	delim = ch;
	while (((ch = getc(in)) != delim) && (ch != EOF))
		str[n++] = ch;
	str[n] = '\0';
} // end getString

char readChar(FILE * in) {
	char ch;
	while (isspace(ch = getc(in))) ; //empty while body
	return ch;
} //end readChar
```

Para ejecutar use el comando:

```
./structs07
```

## Referencias teoricas

A continuación se muestran algunos apuntes de clase que ilustran algunos conceptos teoricos necesarios para comprender la lista de ejemplos adjuntos:

* **Estructuras** [[link]](https://udea-so.github.io/intro-c/content/CH_02-S04.html)
* **Structs** [[link]](https://diveintosystems.org/book/C2-C_depth/structs.html)

## Enlaces

* https://www.educative.io/blog/advanced-c-programming-concepts-for-developers
* https://github.com/Apress/adv-topics-in-c
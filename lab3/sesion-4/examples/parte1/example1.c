#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>


/*
To compute the sum of the integers from 1 to n using a separate thread.

To compile:
    gcc -o example1 example1.c -lpthread
To run:
    ./example1 100
 */
volatile int sum; /* this data is shared by the thread(s) */

void *runner(void *param); /* threads call this function */

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr,"usage: %s <integer value>\n", argv[0]);
        exit(1);
    }
    pthread_t tid; /* the thread identifier */
    pthread_attr_t attr; /* set of thread attributes */
    /* set the default attributes of the thread */
    pthread_attr_init(&attr);
    /* create the thread */
    pthread_create(&tid, &attr, runner, argv[1]);
    /* wait for the thread to exit */
    pthread_join(tid,NULL);
    printf("sum = %d\n",sum);
    return 0;
}

/* The thread will execute in this function */
void *runner(void *param) {
    int i, upper = atoi(param);
    sum = 0;
    for (i = 1; i <= upper; i++)
    sum += i;
    pthread_exit(0);
}
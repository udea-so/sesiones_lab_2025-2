#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> // To use getopt() function
#include <pthread.h>
#include <assert.h>
#include <sys/time.h>

#define DEBUG 1

/*
To count to a given number using multiple threads, with command-line options.

To compile:
    gcc -o example2_rc example2_rc.c -lpthread
To run:
    ./example2_rc -t 1 -n 1000
 */
volatile int count; /* this data is shared by the thread(s) */

void *counting(void *end_value);         /* threads call this function */
void print_usage(const char *prog_name); /* Function to print usage information */

int main(int argc, char *argv[]) {
    count = 0;
    int opt;
    int num_threads = 0;  // Threads to store the argument of -t
    int n = 0;                  // Variable to store the argument of -n
    while ((opt = getopt(argc, argv, "t:n:h")) != -1) {
        switch (opt) {
            case 't':
                // 'optarg' is a global variable set by getopt() to point to the option argument
                num_threads = atoi(optarg); // Convert the argument to an integer
                break;
            case 'n':
                n = atoi(optarg); // Convert the argument to an integer
                break;
            case 'h':
                print_usage(argv[0]);
                return 0; // Terminate the program after showing help
            case '?':
                // getopt() prints an error message by itself
                // when it encounters an unknown option or a missing argument.
                // The '?' is activated in those cases.
                print_usage(argv[0]);
                return 1; // Terminate with an error code
            default:
                // This case should not occur with our option string.
                abort();
        }
    }
    // --- Argument Verification ---
    if (num_threads == 0) {
        fprintf(stderr, "Error: The -t option is mandatory.\n");
        print_usage(argv[0]);
        return 1; // Terminate with an error code
    }
    if (n == 0) {
        fprintf(stderr, "Error: The -n option is mandatory.\n");
        print_usage(argv[0]);
        return 1; // Terminate with an error code
    }   
    // --- Program Logic ---

    pthread_t tid[num_threads]; // Thread identifier
    // Create threads
    for (int i = 0; i < num_threads; i++) {        
        pthread_create(&tid[i], NULL, counting, (void *)&n);
    }
    // Wait for threads to finish
    for (int i = 0; i < num_threads; i++) {
        pthread_join(tid[i], NULL);
    }
    printf("Counter:\n -> real = %d \n -> expected = %d\n", count, num_threads * n);
    return 0;    
}

/* The thread will execute in this function */
void *counting(void *end_value) {
    #ifdef DEBUG
    printf("Thread started with count = %d\n", count);
    #endif
    int i = 0;
    int upper = *((int *)end_value);    
    for (i = 1; i <= upper; i++) {
        count += 1;
    }
    #ifdef DEBUG
    printf("Thread finished with count = %d\n", count);
    #endif
    pthread_exit(0);
}   

void print_usage(const char *prog_name) {
    fprintf(stderr, "Usage: %s -t <num_threads> [-n <value>] [-v] [-h]\n", prog_name);
    fprintf(stderr, "  -t <num_threads> Number of threads to create (mandatory).\n");
    fprintf(stderr, "  -n <value>      The upper limit for the sum (mandatory).\n");
    fprintf(stderr, "  -v               Enable verbose mode.\n");
    fprintf(stderr, "  -h               Show this help message.\n");
}

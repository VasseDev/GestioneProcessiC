#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

void printPrimeNumbers(int start, int end) {
    int i, j, isPrime;
    for (i = start; i < end; i++) {
        isPrime = 1;
        for (j = 2; j < i; j++) {
            if (i % j == 0) {
                isPrime = 0;
            }
        }
        if (isPrime) {
            printf("%d\n", i);
        }
    }
}

int main(int argc, char **argv) {
    clock_t begin = clock();
    int x, i, pid, status, numForks;
    printf("Insert a number: ");
    scanf("%d", &x);
    numForks = x / 25;
    for (i = 0; i < numForks; i++) {
        pid = fork();
        if (pid == 0) {
            int start = i * 25 + 2;
            int end = start + 24;
            printPrimeNumbers(start, end);
            exit(0);
        }
    }
    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("Tempo di esecuzione: %lf", time_spent);
    return 0;
}
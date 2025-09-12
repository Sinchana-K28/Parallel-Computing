#include <stdio.h>
#include <omp.h>
#include <time.h>
long int ser_fib(long int n) {
    if (n < 2) return n;
    return ser_fib(n - 1) + ser_fib(n - 2);
}
long int fib(long int n) {
    if (n < 2) return n;
    long int x, y;

    #pragma omp task shared(x)
    x = fib(n - 1);

    #pragma omp task shared(y)
    y = fib(n - 2);

    #pragma omp taskwait
    return x + y;
}
int main() {
    long int n, result;
    double cpu_time;
    clock_t start, end;

    printf("Enter the value of n: ");
    scanf("%ld", &n);
    start = clock();
    #pragma omp parallel
    {
        #pragma omp single
        result = fib(n);
    }
    end = clock();
    cpu_time = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Parallel Fibonacci(%ld) = %ld\n", n, result);
    printf("Time used in parallel mode = %f seconds\n", cpu_time);
    start = clock();
    result = ser_fib(n);
    end = clock();
    cpu_time = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Sequential Fibonacci(%ld) = %ld\n", n, result);
    printf("Time used in sequential mode = %f seconds\n", cpu_time);
    return 0;
}

//gcc p3.c : to compile
// ./a.out : to run


/*output
Enter the value of n: 32
Parallel Fibonacci(32) = 2178309
Time used in parallel mode = 0.027859 seconds
Sequential Fibonacci(32) = 2178309
Time used in sequential mode = 0.015691 seconds
*/












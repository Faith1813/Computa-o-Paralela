#include <stdio.h>
#include <omp.h>
#include <math.h>

#define f(x) exp(x)

double trapezoidal_rule_serial(double a, double b, int n) {
    double h = (b - a) / n;
    double sum = 0.5 * (f(a) + f(b));

    for (int i = 1; i < n; i++) {
        double x = a + i * h;
        sum += f(x);
    }

    return h * sum;
}

double trapezoidal_rule_parallel(double a, double b, int n) {
    double h = (b - a) / n;
    double sum = 0.5 * (f(a) + f(b));
    int i;
    double x;

    #pragma omp parallel for private(x) reduction(+:sum)
    for (i = 1; i < n; i++) {
        x = a + i * h;
        sum += f(x);
    }

    return h * sum;
}

int main() {
    double a = 0, b = 1; // Intervalo de integração
    int n = 100000000; // Número de trapézios
    double result_serial, result_parallel;
    double start, end;

    // Versão Serial
    start = omp_get_wtime();
    result_serial = trapezoidal_rule_serial(a, b, n);
    end = omp_get_wtime();
    printf("Serial Result: %f\n", result_serial);
    printf("Time taken for serial execution: %f seconds\n", end - start);

    // Versão Paralela
    start = omp_get_wtime();
    result_parallel = trapezoidal_rule_parallel(a, b, n);
    end = omp_get_wtime();
    printf("Parallel Result: %f\n", result_parallel);
    printf("Time taken for parallel execution: %f seconds\n", end - start);

    // Cálculo do speedup
    printf("Speedup: %f\n", (end - start) / (end - start));

    return 0;
}

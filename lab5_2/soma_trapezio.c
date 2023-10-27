#include <stdio.h>
#include <omp.h>

#define N 100

float f(float x) {
    return x * x;
}

int main() {
    float a = 0.0, b = 1.0;
    int n = N;
    float h = (b - a) / n;
    float integral;
    int i;
    int num_threads;

    integral = (f(a) + f(b)) / 2.0;
    
    printf("Digite o número de threads a ser usado: ");
    scanf("%d", &num_threads);
    omp_set_num_threads(num_threads);

    double start_time, end_time;
    start_time = omp_get_wtime();

    #pragma omp parallel for reduction(+:integral)
    for (i = 1; i < n; i++) {
        integral += f(a + i * h);
    }
    integral *= h;

    end_time = omp_get_wtime();

    printf("Valor da integral: %f\n", integral);
    printf("Tempo de execução: %f segundos\n", end_time - start_time);
    printf("Número de threads: %d\n", omp_get_max_threads());

    // Speedup calculation
    double sequential_time = 10.2; // Tempo de execução sequencial para 1 thread
    double parallel_time = end_time - start_time;
    double speedup = sequential_time / parallel_time;
    printf("Speedup: %f\n", speedup);

    return 0;
}


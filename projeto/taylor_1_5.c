#include <stdio.h>
#include <math.h>
#include <omp.h>

// Função que calcula parte da série de Taylor
double calculateSeries(int start, int end, int n, double x) {
    double result = 0.0;
    double factorial = 1.0;

    for (int i = start; i <= end; i++) {
        factorial *= i;
        result += pow(x, i) / factorial;
    }

    return result;
}

int main() {
    int n;
    double x = 1.0;
    double approximation = 1.0;
    double start_time, end_time, cpu_time_used;

    printf("Digite a quantidade de termos da série de Taylor: ");
    scanf("%d", &n);

    start_time = omp_get_wtime();

    const int num_threads = 2; // Defina o número de threads desejado
    double partial_approximations[num_threads]; // Array para armazenar aproximações parciais

    #pragma omp parallel num_threads(num_threads)
    {
        int thread_id = omp_get_thread_num();
        int start = 1 + thread_id * (n / num_threads);
        int end = (thread_id + 1) * (n / num_threads);
        partial_approximations[thread_id] = calculateSeries(start, end, n, x);
    }

    // Combinar aproximações parciais em uma única aproximação
    for (int i = 0; i < num_threads; i++) {
        approximation += partial_approximations[i];
    }

    end_time = omp_get_wtime();
    cpu_time_used = end_time - start_time;

    printf("Aproximação de e: %.15lf\n", approximation);
    printf("Tempo gasto: %.5e segundos\n", cpu_time_used);

    // Cálculo do speedup
    const double serial_time = cpu_time_used;
    const int num_threads_serial = 1; // Número de threads para execução serial
    const double parallel_time = cpu_time_used / num_threads;
    const double speedup = serial_time / parallel_time;

    printf("Speedup: %.2lf\n", speedup);

    return 0;
}

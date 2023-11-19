#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#define MAX_THREADS 2

// Função para calcular o fatorial de um número
unsigned long long calcularFatorial(int n) {
    unsigned long long fatorial = 1;

    if (n < 0) {
        printf("O fatorial não está definido para números negativos.\n");
        return 0;
    }

    for (int i = 1; i <= n; ++i) {
        fatorial *= i;
    }

    return fatorial;
}

int main() {
    int precisao;
    double resultado = 0.0;

    // Solicita ao usuário fornecer a precisão desejada
    printf("Digite a precisão desejada (um número inteiro): ");
    scanf("%d", &precisao);

    double inicio = omp_get_wtime(); // Marca o início do cálculo

    #pragma omp parallel num_threads(MAX_THREADS) reduction(+:resultado)
    {
        int num_threads = omp_get_num_threads();
        int thread_id = omp_get_thread_num();
        int inicio = (thread_id * precisao) / num_threads;
        int fim = ((thread_id + 1) * precisao) / num_threads - 1;

        // Cada thread calcula uma parte da série de Taylor para e com precisão até n
        for (int i = inicio; i <= fim; ++i) {
            resultado += 1.0 / calcularFatorial(i);
        }
    }

    double fim = omp_get_wtime(); // Marca o fim do cálculo

    // Calcula o tempo total de execução
    double tempo = fim - inicio;

    // Exibe o resultado e o tempo de execução
    printf("O número de Euler (e) com precisão até %d é: %lf\n", precisao, resultado);
    printf("Tempo de execução: %lf segundos\n", tempo);

    // Calcula o speedup em relação à versão sequencial
    double tempo_sequencial = tempo * MAX_THREADS;
    double speedup = tempo_sequencial / tempo;
    printf("Speedup: %lf\n", speedup);

    return 0;
}

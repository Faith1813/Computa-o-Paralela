#include <stdio.h>
#include <omp.h>

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

double calcularEuler(int n) {
    double euler = 0.0;

    for (int i = 0; i <= n; ++i) {
        euler += 1.0 / calcularFatorial(i);
    }

    return euler;
}

int main() {
    int precisao;
    double inicio, fim;

    printf("Digite a precisão desejada (um número inteiro): ");
    scanf("%d", &precisao);

    inicio = omp_get_wtime();

    double resultado = calcularEuler(precisao);

    fim = omp_get_wtime();

    printf("O número de Euler (e) com precisão até %d é: %lf\n", precisao, resultado);
    printf("Tempo de execução: %lf segundos\n", fim - inicio);

    return 0;
}

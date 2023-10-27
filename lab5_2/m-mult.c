#include <stdio.h>
#include <omp.h>

int main() {
    int i, j, k;
    int num_threads;

    // Entrada do usuário para o número de linhas e colunas
    int rowsA, colsA, rowsB, colsB;
    printf("Digite o número de linhas da matriz A: ");
    scanf("%d", &rowsA);
    printf("Digite o número de colunas da matriz A: ");
    scanf("%d", &colsA);
    printf("Digite o número de linhas da matriz B: ");
    scanf("%d", &rowsB);
    printf("Digite o número de colunas da matriz B: ");
    scanf("%d", &colsB);

    // Verifica se a multiplicação de matrizes é possível
    if (colsA != rowsB) {
        printf("Erro: O número de colunas da matriz A deve ser igual ao número de linhas da matriz B.\n");
        return 1;
    }

    // Entrada do usuário para as matrizes
    int A[rowsA][colsA];
    int B[rowsB][colsB];

    printf("Digite os elementos da matriz A: \n");
    for (i = 0; i < rowsA; i++) {
        for (j = 0; j < colsA; j++) {
            printf("A[%d][%d]: ", i, j);
            scanf("%d", &A[i][j]);
        }
    }

    printf("Digite os elementos da matriz B: \n");
    for (i = 0; i < rowsB; i++) {
        for (j = 0; j < colsB; j++) {
            printf("B[%d][%d]: ", i, j);
            scanf("%d", &B[i][j]);
        }
    }

    // Resultado da matriz C
    int C[rowsA][colsB];

    printf("Digite o número de threads a ser usado: ");
    scanf("%d", &num_threads);
    omp_set_num_threads(num_threads);

    double start_time, end_time;
    start_time = omp_get_wtime();

    // Multiplicação de matrizes
    #pragma omp parallel for private(j, k)
    for (i = 0; i < rowsA; i++) {
        for (j = 0; j < colsB; j++) {
            int sum = 0;
            for (k = 0; k < colsA; k++) {
                sum += A[i][k] * B[k][j];
            }
            C[i][j] = sum;
        }
    }

    end_time = omp_get_wtime();

    // Imprimindo a matriz resultante C
    printf("Matriz Resultante C: \n");
    for (i = 0; i < rowsA; i++) {
        for (j = 0; j < colsB; j++) {
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }

    printf("Tempo de execução: %f segundos\n", end_time - start_time);
    printf("Número de threads: %d\n", omp_get_max_threads());

    // Cálculo do Speedup
    double sequential_time = 15.0; // Tempo de execução sequencial para 1 thread
    double parallel_time = end_time - start_time;
    double speedup = sequential_time / parallel_time;
    printf("Speedup: %f\n", speedup);

    return 0;
}

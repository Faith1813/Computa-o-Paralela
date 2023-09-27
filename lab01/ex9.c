#include <stdio.h>
#include <stdlib.h> // Para a função abs

// Função para substituir os números negativos pelo seu módulo na matriz
void substituirNegativosPorModulo(int matriz[][10], int linhas, int colunas) {
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            if (matriz[i][j] < 0) {
                matriz[i][j] = abs(matriz[i][j]);
            }
        }
    }
}

int main() {
    int matriz[10][10]; // Tamanho máximo da matriz é 10x10
    int linhas, colunas;

    // Solicita o número de linhas e colunas da matriz
    printf("Digite o número de linhas da matriz (até 10): ");
    scanf("%d", &linhas);

    printf("Digite o número de colunas da matriz (até 10): ");
    scanf("%d", &colunas);

    // Solicita os elementos da matriz
    printf("Digite os elementos da matriz:\n");
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            scanf("%d", &matriz[i][j]);
        }
    }

    // Imprime a matriz original
    printf("Matriz original:\n");
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            printf("%d\t", matriz[i][j]);
        }
        printf("\n");
    }

    // Chama a função para substituir os números negativos pelo módulo
    substituirNegativosPorModulo(matriz, linhas, colunas);

    // Imprime a matriz após a substituição
    printf("Matriz após a substituição de negativos pelo módulo:\n");
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            printf("%d\t", matriz[i][j]);
        }
        printf("\n");
    }

    return 0;
}

#include <stdio.h>

// Função para calcular a matriz transposta
void calcularTransposta(int matriz[][10], int linhas, int colunas, int transposta[][10]) {
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            transposta[j][i] = matriz[i][j];
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

    int transposta[10][10];

    // Chama a função para calcular a matriz transposta
    calcularTransposta(matriz, linhas, colunas, transposta);

    // Imprime a matriz transposta
    printf("Matriz transposta:\n");
    for (int i = 0; i < colunas; i++) {
        for (int j = 0; j < linhas; j++) {
            printf("%d\t", transposta[i][j]);
        }
        printf("\n");
    }

    return 0;
}

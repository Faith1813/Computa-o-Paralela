#include <stdio.h>

// Função para somar os elementos das linhas L1 e L2 e colocar o resultado em L2
void somarLinhas(int matriz[][10], int colunas, int L1, int L2) {
    for (int j = 0; j < colunas; j++) {
        matriz[L2][j] += matriz[L1][j];
    }
}

// Função para multiplicar os elementos das linhas L1 e L2 e colocar o resultado em L2
void multiplicarLinhas(int matriz[][10], int colunas, int L1, int L2) {
    for (int j = 0; j < colunas; j++) {
        matriz[L2][j] *= matriz[L1][j];
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

    int L1, L2;
    printf("Digite o número da linha L1 e L2 para realizar a operação:\n");
    scanf("%d %d", &L1, &L2);

    if (L1 >= 0 && L1 < linhas && L2 >= 0 && L2 < linhas) {
        // Opção para somar as linhas L1 e L2
        somarLinhas(matriz, colunas, L1, L2);

        // Imprime a matriz após a soma
        printf("Matriz após a soma das linhas L%d e L%d:\n", L1, L2);
        for (int i = 0; i < linhas; i++) {
            for (int j = 0; j < colunas; j++) {
                printf("%d\t", matriz[i][j]);
            }
            printf("\n");
        }

        // Opção para multiplicar as linhas L1 e L2
        multiplicarLinhas(matriz, colunas, L1, L2);

        // Imprime a matriz após a multiplicação
        printf("Matriz após a multiplicação das linhas L%d e L%d:\n", L1, L2);
        for (int i = 0; i < linhas; i++) {
            for (int j = 0; j < colunas; j++) {
                printf("%d\t", matriz[i][j]);
            }
            printf("\n");
        }
    } else {
        printf("Índices de linha inválidos.\n");
    }

    return 0;
}

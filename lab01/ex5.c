#include <stdio.h>

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

    int escolha;
    printf("Escolha uma operação:\n");
    printf("1. Multiplicar uma linha por um número\n");
    printf("2. Multiplicar uma coluna por um número\n");
    scanf("%d", &escolha);

    int indice;
    printf("Digite o índice da linha ou coluna: ");
    scanf("%d", &indice);

    int numero;
    printf("Digite o número pelo qual deseja multiplicar: ");
    scanf("%d", &numero);

    // Realiza a multiplicação conforme a escolha do usuário
    if (escolha == 1 && indice >= 0 && indice < linhas) {
        // Multiplica uma linha
        for (int j = 0; j < colunas; j++) {
            matriz[indice][j] *= numero;
        }
    } else if (escolha == 2 && indice >= 0 && indice < colunas) {
        // Multiplica uma coluna
        for (int i = 0; i < linhas; i++) {
            matriz[i][indice] *= numero;
        }
    } else {
        printf("Opção inválida ou índice fora dos limites.\n");
        return 1;
    }

    // Imprime a matriz após a operação
    printf("Matriz após a operação:\n");
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            printf("%d\t", matriz[i][j]);
        }
        printf("\n");
    }

    return 0;
}

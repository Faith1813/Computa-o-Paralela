#include <stdio.h>

// Função para multiplicar uma linha de uma matriz por um número
void multiplicarLinha(int matriz[][10], int colunas, int linha, int numero) {
    for (int j = 0; j < colunas; j++) {
        matriz[linha][j] *= numero;
    }
}

// Função para multiplicar uma coluna de uma matriz por um número
void multiplicarColuna(int matriz[][10], int linhas, int coluna, int numero) {
    for (int i = 0; i < linhas; i++) {
        matriz[i][coluna] *= numero;
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

    int escolha;
    printf("Escolha uma operação:\n");
    printf("1. Multiplicar uma linha por um número\n");
    printf("2. Multiplicar uma coluna por um número\n");
    scanf("%d", &escolha);

    int indice, numero;
    printf("Digite o índice da linha ou coluna: ");
    scanf("%d", &indice);

    printf("Digite o número pelo qual deseja multiplicar: ");
    scanf("%d", &numero);

    // Realiza a multiplicação conforme a escolha do usuário
    if (escolha == 1 && indice >= 0 && indice < linhas) {
        // Multiplica uma linha
        multiplicarLinha(matriz, colunas, indice, numero);
    } else if (escolha == 2 && indice >= 0 && indice < colunas) {
        // Multiplica uma coluna
        multiplicarColuna(matriz, linhas, indice, numero);
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

#include <stdio.h>

int main() {
    int n;
    printf("Digite a ordem da matriz quadrada: ");
    scanf("%d", &n);

    int matriz[n][n];

    // Lê os elementos da matriz
    printf("Digite os elementos da matriz:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matriz[i][j]);
        }
    }

    int menorValor = matriz[0][0];
    int linhaMenorValor = 0;

    // Encontra o menor valor e a linha correspondente
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (matriz[i][j] < menorValor) {
                menorValor = matriz[i][j];
                linhaMenorValor = i;
            }
        }
    }

    // Imprime a linha com o menor valor
    printf("A linha com o menor valor (%d) é a linha %d.\n", menorValor, linhaMenorValor + 1);

    return 0;
}

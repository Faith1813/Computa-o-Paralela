#include <stdio.h>

int main() {
    int max;

    // Solicita ao usuário o número máximo (deve ser ímpar)
    do {
        printf("Digite o número máximo (deve ser ímpar): ");
        scanf("%d", &max);
    } while (max % 2 == 0); // Continua pedindo até que um número ímpar seja fornecido

    int i, j, k;

    // Loop para imprimir as linhas
    for (i = 1; i <= max; i++) {
        // Imprime os espaços iniciais
        for (j = 1; j < i; j++) {
            printf("   ");
        }

        // Imprime os números
        k = i;
        for (j = i; j <= max; j++) {
            printf("%2d ", k++);
        }

        printf("\n");
    }

    return 0;
}

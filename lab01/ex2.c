#include <stdio.h>

int main() {
    float N1, N2, N3, ME, MA;
    char conceito;

    printf("Digite a primeira nota: ");
    scanf("%f", &N1);

    printf("Digite a segunda nota: ");
    scanf("%f", &N2);

    printf("Digite a terceira nota: ");
    scanf("%f", &N3);

    printf("Digite a média dos exercícios: ");
    scanf("%f", &ME);

    MA = (N1 + N2 * 2 + N3 * 3 + ME) / 7.0;

    if (MA >= 9.0) {
        conceito = 'A';
    } else if (MA >= 7.5) {
        conceito = 'B';
    } else if (MA >= 6.0) {
        conceito = 'C';
    } else if (MA >= 4.0) {
        conceito = 'D';
    } else {
        conceito = 'E';
    }

    printf("Média de Aproveitamento: %.2f\n", MA);
    printf("Conceito: %c\n", conceito);

    return 0;
}

#include <stdio.h>
#include <string.h>

int main() {
    char nome1[100], nome2[100];

    printf("Digite o primeiro nome: ");
    scanf("%s", nome1);

    printf("Digite o segundo nome: ");
    scanf("%s", nome2);

    int resultado = strcmp(nome1, nome2);

    if (resultado < 0) {
        printf("Em ordem alfabética: %s, %s\n", nome1, nome2);
    } else if (resultado > 0) {
        printf("Em ordem alfabética: %s, %s\n", nome2, nome1);
    } else {
        printf("Os nomes são iguais.\n");
    }

    return 0;
}

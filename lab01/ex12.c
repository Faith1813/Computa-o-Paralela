#include <stdio.h>
#include <string.h>

// Função para encontrar a posição de um caractere em uma string
int encontrarCaractere(const char *string, char caractere) {
    int tamanho = strlen(string);
    for (int i = 0; i < tamanho; i++) {
        if (string[i] == caractere) {
            return i; // Retorna a posição do caractere
        }
    }
    return -1; // Retorna -1 se o caractere não for encontrado
}

int main() {
    char texto[100];
    char caractere;

    printf("Digite uma string: ");
    scanf("%s", texto);

    printf("Digite o caractere que deseja encontrar: ");
    scanf(" %c", &caractere); // O espaço antes do %c consome o caractere de quebra de linha

    int posicao = encontrarCaractere(texto, caractere);

    if (posicao != -1) {
        printf("O caractere '%c' foi encontrado na posição %d da string.\n", caractere, posicao);
    } else {
        printf("O caractere '%c' não foi encontrado na string.\n", caractere);
    }

    return 0;
}

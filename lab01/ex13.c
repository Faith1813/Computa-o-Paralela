#include <stdio.h>
#include <string.h>

// Função para remover um caractere de uma string dada a posição
void removerCaractere(char *str, int posicao) {
    int tamanho = strlen(str);

    if (posicao >= 0 && posicao < tamanho) {
        for (int i = posicao; i < tamanho - 1; i++) {
            str[i] = str[i + 1]; // Move os caracteres à direita da posição para a esquerda
        }

        str[tamanho - 1] = '\0'; // Define o novo final da string
    }
}

int main() {
    char texto[100];
    int posicao;

    printf("Digite uma string: ");
    scanf("%s", texto);

    printf("Digite a posição do caractere que deseja remover (0 até %d): ", strlen(texto) - 1);
    scanf("%d", &posicao);

    removerCaractere(texto, posicao);

    printf("String após a remoção do caractere: %s\n", texto);

    return 0;
}

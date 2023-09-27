#include <stdio.h>
#include <string.h>

// Função para inserir um caractere em uma string dada a posição
void inserirCaractere(char *str, int posicao, char caractere) {
    int tamanho = strlen(str);

    if (posicao >= 0 && posicao <= tamanho) {
        // Desloca os caracteres à direita da posição para criar espaço para o novo caractere
        for (int i = tamanho; i >= posicao; i--) {
            str[i + 1] = str[i];
        }

        str[posicao] = caractere; // Insere o caractere na posição especificada
    }
}

int main() {
    char texto[100];
    int posicao;
    char caractere;

    printf("Digite uma string: ");
    scanf("%s", texto);

    printf("Digite a posição onde deseja inserir o caractere (0 até %d): ", strlen(texto));
    scanf("%d", &posicao);

    printf("Digite o caractere que deseja inserir: ");
    scanf(" %c", &caractere);

    inserirCaractere(texto, posicao, caractere);

    printf("String após a inserção do caractere: %s\n", texto);

    return 0;
}

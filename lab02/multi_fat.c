#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_THREADS 4 // Número máximo de threads a serem usadas

// Estrutura para passar argumentos para as threads
struct ThreadData {
    int start;
    int end;
    int result;
};

// Função que cada thread executará para calcular parte do fatorial
void *calculateFactorial(void *arg) {
    struct ThreadData *data = (struct ThreadData *)arg;
    int result = 1;

    for (int i = data->start; i <= data->end; i++) {
        result *= i;
    }

    data->result = result;
    pthread_exit(NULL);
}

int main() {
    int num;
    printf("Enter the number: ");
    scanf("%d", &num);

    int totalThreads = (num < MAX_THREADS) ? num : MAX_THREADS;
    pthread_t threads[MAX_THREADS];
    struct ThreadData threadData[MAX_THREADS];

    int chunkSize = num / totalThreads;
    int remainder = num % totalThreads;

    // Criando e iniciando as threads
    for (int i = 0; i < totalThreads; i++) {
        threadData[i].start = i * chunkSize + 1;
        threadData[i].end = (i == totalThreads - 1) ? (i + 1) * chunkSize + remainder : (i + 1) * chunkSize;
        pthread_create(&threads[i], NULL, calculateFactorial, &threadData[i]);
    }

    // Esperando que as threads terminem
    for (int i = 0; i < totalThreads; i++) {
        pthread_join(threads[i], NULL);
    }

    // Calculando o fatorial total a partir dos resultados das threads
    int factorial = 1;
    for (int i = 0; i < totalThreads; i++) {
        factorial *= threadData[i].result;
    }

    printf("The factorial of %d is %d\n", num, factorial);

    return 0;
}

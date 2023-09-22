#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h> // Para medição de tempo

#define N 4 // Tamanho da matriz e vetor
#define NUM_THREADS 2

int matriz[N][N] = {{1, 2, 3, 4},
                    {5, 6, 7, 8},
                    {9, 10, 11, 12},
                    {13, 14, 15, 16}};

int vetor[N] = {1, 2, 3, 4};

int resultado[N];

typedef struct {
    int thread_id;
    int start_row;
    int end_row;
} ThreadArgs;

void matrizVetorSerial() {
    for (int i = 0; i < N; i++) {
        resultado[i] = 0;
        for (int j = 0; j < N; j++) {
            resultado[i] += matriz[i][j] * vetor[j];
        }
    }
}

void *matrizVetorParalelo(void *arg) {
    ThreadArgs *args = (ThreadArgs *)arg;
    int start_row = args->start_row;
    int end_row = args->end_row;

    for (int i = start_row; i < end_row; i++) {
        resultado[i] = 0;
        for (int j = 0; j < N; j++) {
            resultado[i] += matriz[i][j] * vetor[j];
        }
    }

    pthread_exit(NULL);
}

int main() {
    pthread_t threads[NUM_THREADS];
    ThreadArgs thread_args[NUM_THREADS];
    struct timespec start_time, end_time;

    // Medição do tempo para o modo serial
    clock_gettime(CLOCK_MONOTONIC, &start_time);
    matrizVetorSerial();
    clock_gettime(CLOCK_MONOTONIC, &end_time);

    double serial_time = (end_time.tv_sec - start_time.tv_sec) +
                         (end_time.tv_nsec - start_time.tv_nsec) / 1e9;

    printf("Modo Serial: ");
    for (int i = 0; i < N; i++) {
        printf("%d ", resultado[i]);
    }
    printf("Tempo: %f segundos\n", serial_time);

    // Medição do tempo para o modo paralelo
    clock_gettime(CLOCK_MONOTONIC, &start_time);
    for (int i = 0; i < NUM_THREADS; i++) {
        thread_args[i].thread_id = i;
        thread_args[i].start_row = i * (N / NUM_THREADS);
        thread_args[i].end_row = (i + 1) * (N / NUM_THREADS);
        pthread_create(&threads[i], NULL, matrizVetorParalelo, &thread_args[i]);
    }

    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }
    
    clock_gettime(CLOCK_MONOTONIC, &end_time);
    
    double parallel_time = (end_time.tv_sec - start_time.tv_sec) +
                           (end_time.tv_nsec - start_time.tv_nsec) / 1e9;

    printf("Modo Paralelo: ");
    for (int i = 0; i < N; i++) {
        printf("%d ", resultado[i]);
    }
    printf("Tempo: %f segundos\n", parallel_time);

    // Calculando speedup
    double speedup = serial_time / parallel_time;
    printf("Speedup: %f\n", speedup);

    return 0;
}

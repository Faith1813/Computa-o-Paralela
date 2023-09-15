#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>

int main() {
    int shmid;
    key_t key = ftok("shared_memory_key", 65); // Crie uma chave única
    int *shared_variable; // Variável compartilhada

    // Crie a memória compartilhada
    shmid = shmget(key, sizeof(int), IPC_CREAT | 0666);
    if (shmid == -1) {
        perror("shmget");
        exit(1);
    }

    // Anexe a memória compartilhada ao processo
    shared_variable = (int *)shmat(shmid, NULL, 0);
    if (*shared_variable == -1) {
        perror("shmat");
        exit(1);
    }

    // Valor inicial
    *shared_variable = 1;
    printf("Valor inicial da variável compartilhada: %d\n", *shared_variable);

    // Crie um processo filho
    pid_t pid = fork();

    if (pid == -1) {
        perror("fork");
        exit(1);
    }

    if (pid == 0) { // Processo filho
        // Realize uma operação (adição)
        *shared_variable += 2;
        printf("Processo filho: Valor modificado da variável compartilhada: %d\n", *shared_variable);

        // Libere a memória compartilhada
        shmdt(shared_variable);

        // Termine o processo filho
        exit(0);
    } else { // Processo pai
        // Espere pelo processo filho
        wait(NULL);

        // Realize outra operação (multiplicação)
        *shared_variable *= 4;
        printf("Processo pai: Valor modificado da variável compartilhada: %d\n", *shared_variable);

        // Libere a memória compartilhada
        shmdt(shared_variable);

        // Remova a memória compartilhada
        shmctl(shmid, IPC_RMID, NULL);
    }

    return 0;
}

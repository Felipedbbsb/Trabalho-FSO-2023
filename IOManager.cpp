#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
#include <string>
#include <random>

// Estrutura que gerencia operações de E/S (Entrada/Saída)
struct IOManager {
    // Nomes dos dispositivos de E/S
    const char* deviceNames[6] = {"Scanner", "Impressora 1", "Impressora 2", "Modem", "Dispositivo SATA 1", "Dispositivo SATA 2"};
    
    // Flag para indicar se um dispositivo está em uso (1) ou não (0)
    int inUse[6] = {0, 0, 0, 0, 0, 0};
    
    // Semáforo para controlar o acesso concorrente aos dispositivos de E/S
    sem_t ioSemaphore;

    // Construtor da estrutura
    IOManager() {
        sem_init(&ioSemaphore, 0, 1);  // Inicializa o semáforo com 1 
    }

    // Método para solicitar o uso de um dispositivo de E/S
    void requestIO(int deviceId, int processID) {
        sem_wait(&ioSemaphore); // Aguarda até que o semáforo esteja disponível

        printf("Processo (%d) solicita %s\n", processID, deviceNames[deviceId]);

        // Simula uso do dispositivo
        while (inUse[deviceId]) {
            sem_post(&ioSemaphore); // Libera o semáforo
            sleep(3);  // 3 segundos 
            sem_wait(&ioSemaphore); // Aguarda  o semáforo 
        }

        inUse[deviceId] = 1; // Marca o dispositivo como em uso
        printf("Processo (%d) utiliza %s\n", processID, deviceNames[deviceId]);

        sem_post(&ioSemaphore); // Libera o semáforo
    }

    // Método para liberar o dispositivo de E/S após o uso
    void releaseIO(int deviceId, int processID) {
        sem_wait(&ioSemaphore); // Aguarda  o semáforo 

        inUse[deviceId] = 0; // Marca o dispositivo como não em uso
        printf("Processo (%d) libera %s\n",  processID, deviceNames[deviceId]);

        sem_post(&ioSemaphore); // Libera o semáforo
    }
};




// Função executada por cada thread/processo
void* processFunction(void* arg) {
    IOManager* ioManager = static_cast<IOManager*>(arg);

    int processId; // ID do processo atual

    // Adicionando Process ID
    {
        static int currentProcessId = 0;
        processId = ++currentProcessId;
    }

    // Exemplo: definindo deviceID como 0 (Scanner)
    int deviceID = 0;

    // Realiza operações de E/S utilizando a estrutura IOManager
    ioManager->requestIO(deviceID, processId);
    ioManager->releaseIO(deviceID, processId);

    // Similarmente, solicite e libere outros recursos de E/S conforme necessário e solicitado
    
    pthread_exit(NULL);
}




int main(int argc, char **argv) {
    const int numProcesses = 3; // Número de processos/threads

    IOManager ioManager; // Instância da estrutura IOManager

    pthread_t threads[numProcesses]; // Vetor para armazenar IDs das threads

    // Criação das threads/processos
    for (int i = 0; i < numProcesses; ++i) {
        pthread_create(&threads[i], NULL, processFunction, &ioManager);
    }

    // Aguarda o término de todas as threads
    for (int i = 0; i < numProcesses; ++i) {
        pthread_join(threads[i], NULL);
    }

    // Destrói o semáforo
    sem_destroy(&ioManager.ioSemaphore);

    return 0;
}

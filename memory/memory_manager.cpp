#include "memory.cpp"

class MemoryManager {

  Memory memoria; // 1MB = tamanho do bloco;

  MemoryManager() : memoria(1) {}

  void alloc(Process p) {
    bool result = memoria.alloc(p);

    if(!result) {
      // escrever mensagem de erro
    }
  }

  void free(Process p) {
    memoria.free(p);
  }

};

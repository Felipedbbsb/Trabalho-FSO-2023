#include <vector>
#include "../process/process.cpp"

class Memory {

  // representando a memoria
  std::vector<bool> memoria;
  int tamanho_bloco;

  // inicializando
  Memory(int tam_bloco) : 
    tamanho_bloco(tam_bloco), 
    memoria(1024, 0) {}

  int first_fit(Process p) {
    int inicio = 0, limite = 64;
    if(p.prioridade) {
      inicio = 64;
      limite = 1024;
    }
   for(int idx = inicio; idx + p.tamanho_bloco_memoria < limite; idx++) {
      bool can = true;
      for(int tenta = idx; can && tenta < idx+tamanho_bloco_memoria; tenta++) {
        if(memoria[tenta]) can = false;
      }

      if(can) {
        return idx;
      }
    }
    return -1;
  }

  // aqui dentro ja faz a busca 
  bool alloc(Process& p) {
    p.primeiro_bloco_memoria = first_fit(p);

    if(~p.primeiro_bloco_memoria) {
      for(int i = p.primeiro_bloco_memoria; i < p.primeiro_bloco_memoria + p.tamanho_bloco_memoria; i++)
        memoria[i] = true;
      return true;
    }
    return false; // deu ruim;
  }

  void free(Process p) {
    for(int libera = p.primeiro_bloco_memoria; libera < p.primeiro_bloco_memoria + p.tamanho_bloco_memoria; libera++)
      memoria[libera] = false;
  }
};

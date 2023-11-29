#pragma once
#include "../process/process.h"

struct Memory {

  // representando a memoria
  std::vector<bool> memoria;
  int tamanho_bloco;

  // inicializando
  Memory(int tam_bloco);

  // encontra o primeiro bloco livre para o processo
  int first_fit(Process p);

  // aloca a memoria 
  bool alloc(Process& p);

  // libera a memoria
  void free(Process p);
};

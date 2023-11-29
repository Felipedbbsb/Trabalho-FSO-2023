#pragma once
#include <queue>

struct ProcessManager {
  
  std::vector<Process> processos_tabela, processos_terminados,
    processos_bloqueados;
  std::queue<Process> fila_processos;
  MemoryManager gerenciador_memoria;
  //FileManager gerenciador_arquivo;
  Process processador_atual;
  // real time thread ?
  // user thread ? 

};
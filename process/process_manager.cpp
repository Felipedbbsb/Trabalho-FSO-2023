#include <vector>
#include <queue>
#include "process.cpp"

class ProcessManager {
  
  std::vector<Process> lista_processos, processos_terminados,
    processos_bloqueados;
  std::queue<Process> fila_processos;
  MemoryManager gerenciador_memoria;
  FileManager gerenciador_arquivo;
  Processador processador_atual;
  // real time thread ?
  // user thread ? 

};

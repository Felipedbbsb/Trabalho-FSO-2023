#include "../need.h"

struct Process {

  int pid;
  int tempo_criacao;
  int tempo_cpu = 0; // comeca com 0 tempo de cpu
  int tempo_ocioso = 0;
  // waiting time = cur_time - creation_time - cpu_time;

  int prioridade;

  int primeiro_bloco_memoria;
  int tamanho_bloco_memoria;

  Process(int pid, int prioridade) : 
  pid(pid), prioridade(prioridade) {
    auto p1 = std::chrono::system_clock::now();
    tempo_criacao = 
      std::chrono::
      duration_cast<std::chrono::seconds>
      (p1.time_since_epoch()).count();
  }

};

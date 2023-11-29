#pragma once

struct Process {
  int pid;
  int tempo_criacao;
  int tempo_cpu = 0;
  int tempo_ocioso = 0;
  int prioridade;
  int primeiro_bloco_memoria;
  int tamanho_bloco_memoria;

  Process(int pid, int prioridade);
};
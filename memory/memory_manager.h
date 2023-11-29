#pragma once

struct MemoryManager {

  Memory memoria; // 1MB = tamanho do bloco;
  MemoryManager();
  
  void alloc(Process p);
  void free(Process p);
};

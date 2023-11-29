#include <vector>
#include "File.h"

#ifndef TRABALHO_FSO_2023_FILE_DISK_H_
#define TRABALHO_FSO_2023_FILE_DISK_H_

/**
 * Representa o disco, contendo informações sobre ele e seus arquivos.
 */
class Disk
{
 public:
	unsigned int GetBlockAmount();
	unsigned int GetOccupiedSegments();
	File* GetFile(char n);

	void SetBlockAmount(unsigned int n);
	void SetOccupiedSegments(unsigned int n);
	void SetFile(char n, File f);

	void AddFile(File* f);
	void RemoveFile(File* f);
 private:
	std::vector<File*> files;
	unsigned int block_amount;
	unsigned int occupied_segments;
};

#endif //TRABALHO_FSO_2023_FILE_DISK_H_

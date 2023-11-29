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
	unsigned int GetBlockAmount() const;
	unsigned int GetOccupiedSegments() const;

	void SetBlockAmount(unsigned int n);
	void SetOccupiedSegments(unsigned int n);

	void AddFile(File f);
	void RemoveFile(char n);
	File GetFile(char n);
 private:
	std::vector<File> files;
	unsigned int block_amount;
	unsigned int occupied_segments;
};

#endif //TRABALHO_FSO_2023_FILE_DISK_H_

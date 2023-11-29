#ifndef TRABALHO_FSO_2023_FILE_FILE_H_
#define TRABALHO_FSO_2023_FILE_FILE_H_

/**
 * Representa um arquivo.
 */
class File
{
 public:
	char GetName();
	unsigned int GetFirstBlock();
	unsigned int GetBlockCount();

	void SetName(char c);
	void SetFirstBlock(unsigned int n);
	void SetBlockCount(unsigned int n);
 private:
	char name;
	unsigned int first_block;
	unsigned int block_count;
};

#endif //TRABALHO_FSO_2023_FILE_FILE_H_

#include "File.h"

File::File(char n, unsigned int fb, unsigned int bc)
{
	name = n;
	first_block = fb;
	block_count = bc;
}

char File::GetName()
{
	return name;
}

unsigned int File::GetFirstBlock()
{
	return first_block;
}

unsigned int File::GetBlockCount()
{
	return block_count;
}

void File::SetName(char c)
{
	name = c;
}

void File::SetFirstBlock(unsigned int n)
{
	first_block = n;
}

void File::SetBlockCount(unsigned int n)
{
	block_count = n;
}

void File::Open()
{
	if (!is_open) {
		is_open = true;
	} else {
		// Mensagem de erro
	}
}

void File::Close()
{
	if (is_open) {
		is_open = false;
	} else {
		// Mensagem de erro
	}
}

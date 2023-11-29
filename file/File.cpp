#include "File.h"

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

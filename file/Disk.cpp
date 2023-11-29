#include "Disk.h"
#include <algorithm>

unsigned int Disk::GetBlockAmount() const
{
	return block_amount;
}

unsigned int Disk::GetOccupiedSegments() const
{
	return occupied_segments;
}

void Disk::SetBlockAmount(unsigned int n)
{
	block_amount = n;
}

void Disk::SetOccupiedSegments(unsigned int n)
{
	occupied_segments = n;
}

void Disk::AddFile(File f)
{
	File file = f;
	file.SetFirstBlock(occupied_segments);

	files.push_back(file);
	occupied_segments += file.GetBlockCount();
}

void Disk::RemoveFile(char n)
{
	// TODO
}

File Disk::GetFile(char n)
{
	File file;

	for (auto f : files)
	{
		if (f.GetName() == n)
		{
			file = f;
			break;
		}
	}
	return file;
}
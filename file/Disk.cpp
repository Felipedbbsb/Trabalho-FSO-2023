#include "Disk.h"

unsigned int Disk::GetBlockAmount()
{
	return block_amount;
}

unsigned int Disk::GetOccupiedSegments()
{
	return occupied_segments;
}

File* Disk::GetFile(char n)
{
	File* file;

	for (auto f : files)
	{
		if (f->GetName() == n)
		{
			file = f;
			break;
		}
	}
	return file;
}

void Disk::SetBlockAmount(unsigned int n)
{
	block_amount = n;
}

void Disk::SetOccupiedSegments(unsigned int n)
{
	occupied_segments = n;
}

void Disk::SetFile(char n, File f)
{
	for (auto file : files)
	{
		if (file->GetName() == n)
		{
			*file = f;
			break;
		}
	}
}

void Disk::AddFile(File* f)
{
	files.push_back(f);
	occupied_segments += f->GetBlockCount();
}

void Disk::RemoveFile(File* f)
{
	occupied_segments -= f->GetBlockCount();
}

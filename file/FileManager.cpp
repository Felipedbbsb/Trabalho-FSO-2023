#include <sstream>
#include "FileManager.h"

/**
 * Popula o disco com as linhas de entrada
 * @param lines - linhas do arquivo de entrada
 */
void FileManager::PopulateDisk(const std::vector<std::string>& lines)
{
	unsigned int block_amount = std::stoul(lines[0]);
	unsigned int occupied_segments = std::stoul(lines[1]);

	disk.SetBlockAmount(block_amount);
	disk.SetOccupiedSegments(occupied_segments);

	for (int i = 2; i < occupied_segments + 2; i++)
	{
		std::string line = lines[i];
		std::istringstream stream(line);
		std::vector<std::string> tokens;
		std::string token;

		while (std::getline(stream, token, ' '))
		{
			tokens.push_back(token);
		}
		char name = tokens[0].front();

		tokens[1].pop_back();

		unsigned int first_block = std::stoul(tokens[1]);
		unsigned int block_count = std::stoul(tokens[2]);

		auto file = new File(name, first_block, block_count);

		disk.AddFile(file);
	}
}

void FileManager::OpenFile(char name)
{
	auto file = disk.GetFile(name);
	file->Open();
}

void FileManager::CloseFile(char name)
{
	auto file = disk.GetFile(name);
	file->Close();
}

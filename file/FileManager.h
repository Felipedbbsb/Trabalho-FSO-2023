#ifndef TRABALHO_FSO_2023_FILE_FILEMANAGER_H_
#define TRABALHO_FSO_2023_FILE_FILEMANAGER_H_

#include <string>
#include "Disk.h"

class FileManager
{
 public:
	void PopulateDisk(const std::vector<std::string>& lines);
	void OpenFile(char name);
	void CloseFile(char name);
 private:
	Disk disk;
};

#endif //TRABALHO_FSO_2023_FILE_FILEMANAGER_H_

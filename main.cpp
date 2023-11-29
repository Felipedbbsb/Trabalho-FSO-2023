#include <fstream>
#include <vector>
#include "IOManager.cpp"
#include "need.h"

std::vector<std::string> read_lines(const std::string& path)
{
	std::vector<std::string> lines;
	std::string line;
	std::ifstream file(path);

	if (file.fail())
	{
		// Incluir mensagem de erro
		abort();
	}
	while (std::getline(file, line))
	{
		lines.push_back(line);
	}
	file.close();

	return lines;
}

int main(int argc, char* argv[])
{
	// TODO: abrir as instancias dos gerenciadores
	// TODO: fazer tipo um kernel ?
	if (argc != 3)
	{
		// Incluir mensagem de erro
		abort();
	}
	// Caminho dos arquivos de entrada
	std::string processes_path = argv[1];
	std::string files_path = argv[2];

	// Linhas dos caminhos de entrada
	std::vector<std::string> processes = read_lines(processes_path);
	std::vector<std::string> files = read_lines(files_path);

	FileManager fileManager;

	// TODO: erro ao executar esse arquivo quando deveria funcionar
	//	fileManager.PopulateDisk(files);
}

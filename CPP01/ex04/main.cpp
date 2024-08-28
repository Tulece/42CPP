#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

void replaceAll(std::string& line, const std::string& s1, const std::string& s2) {
	size_t pos = 0;
	while ((pos = line.find(s1, pos)) != std::string::npos) {
		line.erase(pos, s1.length());
		line.insert(pos, s2);
		pos += s2.length();
	}
}

int main(int argc, char* argv[]) {
	// Vérification des arguments
	if (argc != 4) {
		std::cerr << "Usage: " << argv[0] << " <filename> <s1> <s2>" << std::endl;
		return 1;
	}

	std::string filename = argv[1];
	std::string s1 = argv[2];
	std::string s2 = argv[3];

	// Vérification si s1 ou s2 ne sont pas vides
	if (s1.empty()) {
		std::cerr << "Error: s1 cannot be empty" << std::endl;
		return 1;
	}

	if (s2.empty()) {
		std::cerr << "Error: s2 cannot be empty" << std::endl;
		return 1;
	}

	// Ouverture du fichier en lecture
	std::ifstream inputFile(filename.c_str());
	if (!inputFile.is_open()) {
		std::cerr << "Error: Could not open file " << filename << std::endl;
		return 1;
	}

	// Création du fichier de sortie
	filename += ".replace";
	std::ofstream outputFile(filename.c_str());
	if (!outputFile.is_open()) {
		std::cerr << "Error: Could not create output file " << filename << ".replace" << std::endl;
		inputFile.close();
		return 1;
	}

	// Lecture et remplacement ligne par ligne
	std::string line;
	while (std::getline(inputFile, line)) {
		replaceAll(line, s1, s2);
		outputFile << line << std::endl;
	}

	// Fermeture des fichiers
	inputFile.close();
	outputFile.close();

	return 0;
}

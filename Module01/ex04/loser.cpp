#include "loser.hpp"

void replaceAndWrite(const std::string &original_file, const std::string &copied_file, const std::string &s1, const std::string &s2)
{
	std::ifstream inFile(original_file);
	if (!inFile)
	{
		std::cerr << "Error opening input file: " << original_file << std::endl;
	}
	std::ofstream outFile(copied_file);
    if (!outFile) {
        std::cerr << "Error creating output file: " << copied_file << std::endl;
        return;
    }
	std::string line;
    while (std::getline(inFile, line)) {
        std::string newLine; // Nowy ciąg znaków po zamianie
        size_t pos = 0;

        while (true) {
            // Znajdź kolejne wystąpienie `s1` w linii
            size_t foundPos = line.find(s1, pos);

            if (foundPos == std::string::npos) {
                // Jeśli brak wystąpienia, dodaj resztę linii i przerwij pętlę
                newLine += line.substr(pos);
                break;
            }

            // Dodaj część przed znalezionym `s1` oraz `s2` zamiast `s1`
            newLine += line.substr(pos, foundPos - pos); // Tekst przed `s1`
            newLine += s2;                              // Zastąpienie `s1` przez `s2`

            // Zaktualizuj pozycję na miejsce za `s1`
            pos = foundPos + s1.length();
        }

        outFile << newLine << "\n"; // Zapisz nową linię do pliku wyjściowego
    }

    inFile.close();
    outFile.close();
}
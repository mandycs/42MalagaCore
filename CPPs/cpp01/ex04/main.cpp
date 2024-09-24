#include <iostream>
#include <fstream>
#include <string>

std::string replaceOccurrences(const std::string& line, const std::string& s1, const std::string& s2) {
    std::string newLine = line;
    size_t pos = 0;

    while ((pos = newLine.find(s1, pos)) != std::string::npos) {
        newLine.replace(pos, s1.length(), s2);
        pos += s2.length();
    }

    return newLine;
}

int main(int argc, char** argv) {
    if (argc != 4) {
        std::cerr << "Usage: " << argv[0] << " <filename> <s1> <s2>" << std::endl;
        return 1;
    }

    std::string filename = argv[1];
    std::string s1 = argv[2];
    std::string s2 = argv[3];

    if (s1.empty() || s2.empty()) {
        std::cerr << "Error: s1 and s2 must not be empty" << std::endl;
        return 1;
    }

    std::ifstream inputFile(filename.c_str());  // Modificación aquí
    if (!inputFile.is_open()) {
        std::cerr << "Error: Could not open file " << filename << std::endl;
        return 1;
    }

    std::ofstream outputFile((filename + ".replace").c_str());  // Modificación aquí
    if (!outputFile.is_open()) {
        std::cerr << "Error: Could not create output file " << filename << ".replace" << std::endl;
        inputFile.close();
        return 1;
    }

    std::string line;
    while (std::getline(inputFile, line)) {
        outputFile << replaceOccurrences(line, s1, s2) << std::endl;
    }

    inputFile.close();
    outputFile.close();

    return 0;
}

#include <fstream>
#include <iostream>
#include <string>

int summarizeFile(std::string path) {
    std::ifstream file(path);

    if (!file.is_open()) {
        std::cerr << "Error: could not open " << path << '\n';
        return 2;
    }

    std::string line;
    int matches = 0;

    while (std::getline(file, line)) {
        if (line.find("Failed password") != std::string::npos) {
            matches += 1;
        }
    }

    std::cout << "Matching lines: " << matches << '\n';
    return 0;
}

int main(int argc, char** argv) {
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <file>\n";
        return 1;
    }

    return summarizeFile(argv[1]);
}

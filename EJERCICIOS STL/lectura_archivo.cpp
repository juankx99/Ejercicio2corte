#include <iostream>
#include <fstream>
#include <set>
#include <string>
#include <sstream>
#include <algorithm>
#include <cctype>

// Función que limpia una palabra: 
//  - elimina caracteres no alfabéticos al inicio y al final
//  - convierte todo a minúsculas
std::string cleanWord(const std::string& raw) {
    size_t start = 0, end = raw.size();
    // buscar primer carácter alfabético
    while (start < end && !std::isalpha(static_cast<unsigned char>(raw[start]))) {
        ++start;
    }
    // buscar último carácter alfabético
    while (end > start && !std::isalpha(static_cast<unsigned char>(raw[end-1]))) {
        --end;
    }
    std::string w = raw.substr(start, end - start);
    // pasar a minúsculas
    std::transform(w.begin(), w.end(), w.begin(),
                   [](unsigned char c){ return std::tolower(c); });
    return w;
}

// Lee el archivo línea a línea, extrae palabras y las mete en un set
std::set<std::string> readWordsIntoSet(const std::string& filename) {
    std::set<std::string> words;
    std::ifstream in(filename);
    if (!in) {
        throw std::runtime_error("No se pudo abrir el archivo: " + filename);
    }

    std::string line;
    while (std::getline(in, line)) {
        std::istringstream iss(line);
        std::string raw;
        while (iss >> raw) {
            std::string w = cleanWord(raw);
            if (!w.empty()) {
                words.insert(w);
            }
        }
    }

    return words;
}

int main() {
    try {
        const std::string filename = "sampleFile.txt";
        auto palabras = readWordsIntoSet(filename);

        std::cout << "Palabras extraídas (ordenadas y sin duplicados):\n";
        for (const auto& w : palabras) {
            std::cout << w << "\n";
        }
    }
    catch (const std::exception& ex) {
        std::cerr << "Error: " << ex.what() << "\n";
        return 1;
    }
    return 0;
}

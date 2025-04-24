#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <sstream>
#include <algorithm>
#include <cctype>

// Limpia un token:
//  - recortando caracteres no alfabéticos al inicio/final
//  - pasando el resto a minúsculas
std::string cleanWord(const std::string& raw) {
    size_t start = 0, end = raw.size();
    while (start < end && !std::isalpha(static_cast<unsigned char>(raw[start]))) ++start;
    while (end > start && !std::isalpha(static_cast<unsigned char>(raw[end-1]))) --end;
    std::string w = raw.substr(start, end - start);
    std::transform(w.begin(), w.end(), w.begin(),
                   [](unsigned char c){ return std::tolower(c); });
    return w;
}

int main() {
    const std::string filename = "sampleFile.txt";
    std::ifstream file(filename);
    if (!file) {
        std::cerr << "No se pudo abrir " << filename << "\n";
        return 1;
    }

    std::map<std::string,int> freq;
    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string token;
        while (iss >> token) {
            std::string w = cleanWord(token);
            if (!w.empty()) {
                ++freq[w];
            }
        }
    }

    // Mostrar resultados (orden alfabético por clave)
    std::cout << "Frecuencia de palabras:\n";
    for (const auto& [palabra, cuenta] : freq) {
        std::cout << palabra << " → " << cuenta << "\n";
    }

    return 0;
}

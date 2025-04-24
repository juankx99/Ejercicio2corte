#include <iostream>
#include <vector>
#include <string>
#include <algorithm>  // std::sort

int main() {
    std::vector<std::pair<int, std::string>> datos = {
        {5, "manzana"},
        {2, "banana"},
        {8, "naranja"},
        {1, "uva"},
        {7, "pera"}
    };

    // Ordenamos con un lambda que compara .first de forma descendente
    std::sort(
        datos.begin(), datos.end(),
        [](const auto& a, const auto& b) {
            return a.first > b.first;  // true si a debe ir antes que b
        }
    );

    // Mostramos el vector ya ordenado
    std::cout << "Datos ordenados (descendente por número):\n";
    for (const auto& [num, fruta] : datos) {
        std::cout << num << " → " << fruta << "\n";
    }

    return 0;
}

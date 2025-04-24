#include <iostream>
#include <vector>
#include <algorithm>  // std::find_if
#include <optional>   // std::optional (requiere C++17)

std::optional<int> findFirstEven(const std::vector<int>& nums) {
    // find_if recorre desde begin() hasta end() y aplica el predicado
    auto it = std::find_if(nums.begin(), nums.end(),
                           [](int n){ return n % 2 == 0; });
    if (it != nums.end()) {
        return *it;  // devolvemos el primer par encontrado
    } else {
        return std::nullopt;  // no hay ningún número par
    }
}

int main() {
    std::vector<int> numeros = {7, 13, 9, 8, 15, 6, 21};

    auto resultado = findFirstEven(numeros);
    if (resultado) {
        std::cout << "El primer número par es: " << *resultado << "\n";
    } else {
        std::cout << "No se encontró ningún número par.\n";
    }

    return 0;
}

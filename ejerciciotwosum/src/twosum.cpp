#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
        // Función que busca dos números en el vector que sumen el valor 'target'
        vector<int> twoSum(vector<int>& nums, int target) { 
            vector<int> result; // Vector para almacenar los índices de los números encontrados
            // Recorremos el vector con dos bucles anidados para encontrar dos números que sumen 'target'
            for (int i = 0; i < nums.size(); i++) {
                for (int j = i +1; j < nums.size(); j++) 
                {
                    if (nums[i]+ nums[j] == target) // Si la suma de dos números es igual al objetivo
                    {
                        //Guardamos indices de cada número en el vector result
                        result.push_back(i);
                        result.push_back(j);
                        return result;
                    }
                }
            }
            return{};
        }   
 };
 int main() {
    //Se utiliza la clase, poniendo un ejemplo de uso
    Solution solution;
    vector<int> nums = {3,3};
    int target = 6;

    vector<int> result = solution.twoSum(nums, target);
    // Se imprime el resultado
    if (!result.empty()) {
        cout << "Índices encontrados: " << result[0] << ", " << result[1] << endl;
    } else {
        cout << "No se encontraron dos números que sumen " << target << endl;
    }

    return 0;
}
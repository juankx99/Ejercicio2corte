#include <iostream>
#include <string>
using namespace std;

class Solution {
    public:
        string addStrings(string num1, string num2) {
            string result = ""; //variable para almacenar el resultado
            int carry = 0; // variable para almaacenar acarreo
            int i = num1.size() - 1; // índice para recorrer num1
            int j = num2.size() - 1; // índice para recorrer num2
            // Mientras haya números en num1 o num2 o haya acarreo
            while (i >= 0 || j >= 0 || carry) {
                // Sumamos los números de num1 y num2 y el acarreo
                int sum = 0;
                if (i >= 0) {
                    sum += num1[i] - '0';
                    i--;
                }
                if (j >= 0) {
                    sum += num2[j] - '0';
                    j--;
                }
                sum += carry;
                // Si la suma es mayor o igual a 10
                if (sum >= 10) {
                    carry = 1; // Hay acarreo
                    sum -= 10; // El resultado es el último dígito
                } else {
                    carry = 0; // No hay acarreo
                }
                // Añadimos el resultado a la cadena
                result = to_string(sum) + result;
            }
            return result;
            
        }
    };
int main() {
    //Se utiliza la clase, poniendo un ejemplo de uso
    Solution solution;
    string num1 = "123";
    string num2 = "456";
    string result = solution.addStrings(num1, num2);
    // Se imprime el resultado
    cout << "Resultado de la suma: " << result << endl;
    return 0;
}
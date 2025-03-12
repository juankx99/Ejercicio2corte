#include <iostream>
using namespace std;

// Callback functions for different operations
int add(int a, int b) { return a + b; }
int multiply(int a, int b) { return a * b; }
int subtract(int a, int b) { return a - b; }

// Function that performs an operation using a callback
void performOperation(int (*callback)(int, int), int x, int y) {
    cout << "The result of the operation is: " << callback(x, y) << endl;
}

int main(int argc, char* argv[]) {
    if (argc != 4) {
        cout << "Uso: " << argv[0] << " num1 operador num2" << endl;
        return 1;
    }

    int num1 = atoi(argv[1]); // Convertir argumento a entero
    int num2 = atoi(argv[3]); // Convertir argumento a entero
    char op = argv[2][0];     // Tomar el primer carácter del operador

    int (*operation)(int, int) = nullptr;
    switch (op) {
        case '+': operation = add; break;
        case '-': operation = subtract; break;
        case '*': operation = multiply; break;
        default: cout << "Operador no válido." << endl; return 1;
    }

    performOperation(operation, num1, num2);
    return 0;
}
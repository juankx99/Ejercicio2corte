#include <iostream>
using namespace std;

// Función de callback para sumar dos números
int add(int a, int b) { return a + b; }
// Función de callback para multiplicar dos números
int multiply(int a, int b) { return a * b; }
// Función de callback para restar dos números
int subtract(int a, int b) { return a - b; }

// Función que realiza una operación usando una función de callback
void performOperation(int (*callback)(int, int), int x, int y) {
    // Imprime el resultado de la operación llamando a la función de callback
    cout << "The result of the operation is: " << callback(x, y) << endl;
}

int main(int argc, char* argv[]) {
    // Verifica que el número de argumentos sea el correcto
    if (argc != 4) {
        // Muestra el uso correcto del programa si los argumentos son incorrectos
        cout << "Uso: " << argv[0] << " num1 operador num2" << endl;
        return 1;
    }
    // Convierte los argumentos a enteros
    int num1 = atoi(argv[1]); // Convertir argumento a entero
    int num2 = atoi(argv[3]); // Convertir argumento a entero
    char op = argv[2][0];     // Tomar el primer carácter del operador
    // Puntero a función para la operación
    int (*operation)(int, int) = nullptr;
    // Selecciona la operación basada en el operador proporcionado
    switch (op) {
        case '+': operation = add; break;// Asigna la función de suma
        case '-': operation = subtract; break;// Asigna la función de resta
        case '*': operation = multiply; break;// Asigna la función de multiplicación
        default: cout << "Operador no válido." << endl; return 1; // Muestra un mensaje de error si el operador no es válido
    }
    // Realiza la operación usando la función de callback seleccionada
    performOperation(operation, num1, num2);
    return 0;
}
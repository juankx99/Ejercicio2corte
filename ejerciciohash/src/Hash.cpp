/**
 * @file Hash.cpp
 * @brief Implementación de una estructura de datos tipo HashSet.
 */

#include <iostream>
using namespace std;

/**
 * @class MyHashSet
 * @brief Clase que implementa un HashSet utilizando un array booleano.
 */
class MyHashSet {
private:
    static const int SIZE = 1000001; /**< Tamaño del array hash. */
    bool hash[SIZE]; /**< Array booleano que representa el HashSet. */

public:
    /**
     * @brief Constructor de la clase MyHashSet.
     * Inicializa todos los valores del array hash a false.
     */
    MyHashSet() {
        for (int i = 0; i < SIZE; ++i) {
            hash[i] = false;
        }
    }

    /**
     * @brief Agrega un elemento al HashSet.
     * @param key Clave del elemento a agregar.
     */
    void add(int key) {
        hash[key] = true;
    }

    /**
     * @brief Elimina un elemento del HashSet.
     * @param key Clave del elemento a eliminar.
     */
    void remove(int key) {
        hash[key] = false;
    }

    /**
     * @brief Verifica si un elemento está en el HashSet.
     * @param key Clave del elemento a verificar.
     * @return true si el elemento está en el HashSet, false en caso contrario.
     */
    bool contains(int key) {
        return hash[key];
    }
};

/**
 * @brief Función principal para probar la clase MyHashSet.
 * @return 0 si la ejecución es exitosa.
 */
int main() {
    MyHashSet myHashSet;

    myHashSet.add(1);              // set = [1]
    myHashSet.add(2);              // set = [1, 2]
    cout << boolalpha << myHashSet.contains(1) << endl;  // true
    cout << boolalpha << myHashSet.contains(3) << endl;  // false
    myHashSet.add(2);              // set = [1, 2]
    cout << boolalpha << myHashSet.contains(2) << endl;  // true
    myHashSet.remove(2);           // set = [1]
    cout << boolalpha << myHashSet.contains(2) << endl;  // false

    return 0;
}
#include "point2d.h"
#include <cmath>
#include <iostream>

// Constructores
// Constructor por defecto que inicializa las coordenadas x e y a 0.0
Point2d::Point2d() : x(0.0), y(0.0) {}

// Constructor que inicializa las coordenadas con valores dados
Point2d::Point2d(double x, double y) : x(x), y(y) {}

// Constructor de copia que inicializa un objeto con los valores de otro objeto Point2d
Point2d::Point2d(const Point2d& other) : x(other.x), y(other.y) {}

// Getters
// Devuelve el valor de la coordenada x
double Point2d::getX() const {
    return x;
}

// Devuelve el valor de la coordenada y
double Point2d::getY() const {
    return y;
}

// Setters
// Establece el valor de la coordenada x
void Point2d::setX(double x) {
    this->x = x;
}

// Establece el valor de la coordenada y
void Point2d::setY(double y) {
    this->y = y;
}

// Operadores sobrecargados
// Suma las coordenadas de dos puntos y devuelve un nuevo Point2d
Point2d Point2d::operator+(const Point2d& other) const {
    return Point2d(x + other.x, y + other.y);
}

// Resta las coordenadas de dos puntos y devuelve un nuevo Point2d
Point2d Point2d::operator-(const Point2d& other) const {
    return Point2d(x - other.x, y - other.y);
}

// Multiplica las coordenadas del punto por un escalar y devuelve un nuevo Point2d
Point2d Point2d::operator*(double scalar) const {
    return Point2d(x * scalar, y * scalar);
}

// Divide las coordenadas del punto por un escalar y devuelve un nuevo Point2d
// Si el escalar es 0, muestra un error y devuelve un punto en el origen
Point2d Point2d::operator/(double scalar) const {
    if (scalar != 0) {
        return Point2d(x / scalar, y / scalar);
    } else {
        std::cerr << "Error: No se puede dividir por 0." << std::endl;
        return Point2d(0, 0);
    }
}

// Operador de asignación que copia los valores de otro Point2d
Point2d& Point2d::operator=(const Point2d& other) {
    if (this != &other) { // Evita la autoasignación
        x = other.x;
        y = other.y;
    }
    return *this;
}

// Métodos adicionales
// Calcula la distancia entre este punto y otro punto
double Point2d::distanceto(const Point2d& other) const {
    return std::sqrt(std::pow(x - other.x, 2) + std::pow(y - other.y, 2));
}

// Calcula la distancia desde este punto al origen (0, 0)
double Point2d::distanceToOrigin() const {
    return std::sqrt(x * x + y * y);
}

// Calcula el punto medio entre este punto y otro punto
Point2d Point2d::midpoint(const Point2d& other) const {
    return Point2d((x + other.x) / 2.0, (y + other.y) / 2.0);
}

// Calcula el vector unitario (normalizado) de este punto
// Si el vector tiene longitud 0, muestra un error y devuelve un punto en el origen
Point2d Point2d::unitvector() const {
    double length = distanceToOrigin();
    if (length != 0) {
        return Point2d(x / length, y / length);
    } else {
        std::cerr << "Error: no se puede normalizar un vector de 0." << std::endl;
        return Point2d(0, 0);
    }
}
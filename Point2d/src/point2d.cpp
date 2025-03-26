#include "point2d.h"
#include <cmath>
#include <iostream>
//constructores
Point2d::Point2d() : x(0.0), y(0.0) {}
Point2d::Point2d(double x, double y) : x(x), y(y) {}
Point2d::Point2d(const Point2d& other) : x(other.x), y(other.y) {}
//getters
double Point2d::getX() const {
    return x;
}
double Point2d::getY() const {
    return y;
}
//setters
void Point2d::setX(double x) {
    this->x = x;
}
void Point2d::setY(double y) {
    this->y = y;
}
//operadores sobrecargados
Point2d Point2d::operator+(const Point2d& other) const {
    return Point2d(x + other.x, y + other.y);
}
Point2d Point2d::operator-(const Point2d& other) const {
    return Point2d(x - other.x, y - other.y);
}
Point2d Point2d::operator*(double scalar) const {
    return Point2d(x * scalar, y * scalar);
}
Point2d Point2d::operator/(double scalar) const {
    if (scalar != 0) {
        return Point2d(x / scalar, y / scalar);
    } else {
        std::cerr << "Error: No se puede dividir por 0." << std::endl;
        return Point2d(0, 0); // Return a default point or handle the error as needed
    }
}
Point2d& Point2d::operator=(const Point2d& other) {
    if (this != &other) {
        x = other.x;
        y = other.y;
    }
    return *this;
}
//metodos adicionales
double Point2d::distanceto(const Point2d& other) const {
    return std::sqrt(std::pow(x - other.x, 2) + std::pow(y - other.y, 2));
}
double Point2d::distanceToOrigin() const {
    return std::sqrt(x * x + y * y);
}
Point2d Point2d::midpoint(const Point2d& other) const {
    return Point2d((x + other.x) / 2.0, (y + other.y) / 2.0);
}   
Point2d Point2d::unitvector() const {
    double length = distanceToOrigin();
    if (length != 0) {
        return Point2d(x / length, y / length);
    } else {
        std::cerr << "Error: no se puede normalizar un vector de 0." << std::endl;
        return Point2d(0, 0);
    }
}
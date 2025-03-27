#ifndef POINT2D_H
#define POINT2D_H

#include <cmath> // Para funciones matemáticas como sqrt

// Clase que representa un punto en un plano 2D
class Point2d {
    private:
        double x; // Coordenada X del punto
        double y; // Coordenada Y del punto

    public:
        // Constructor por defecto
        Point2d();

        // Constructor que inicializa el punto con coordenadas específicas
        Point2d(double x, double y);

        // Constructor de copia
        Point2d(const Point2d& other);

        // Getters: Métodos para obtener las coordenadas del punto
        double getX() const; // Devuelve la coordenada X
        double getY() const; // Devuelve la coordenada Y

        // Setters: Métodos para modificar las coordenadas del punto
        void setX(double x); // Establece la coordenada X
        void setY(double y); // Establece la coordenada Y

        // Sobrecarga de operadores para operaciones entre puntos
        Point2d operator+(const Point2d& other) const; // Suma de puntos
        Point2d operator-(const Point2d& other) const; // Resta de puntos
        Point2d operator*(double scalar) const;        // Multiplicación por un escalar
        Point2d operator/(double scalar) const;        // División por un escalar
        Point2d& operator=(const Point2d& other);      // Asignación entre puntos

        // Métodos adicionales
        double distanceto(const Point2d& other) const; // Calcula la distancia a otro punto
        double distanceToOrigin() const;              // Calcula la distancia al origen (0, 0)
        Point2d midpoint(const Point2d& other) const; // Calcula el punto medio entre dos puntos
        Point2d unitvector() const;                   // Devuelve el vector unitario del punto
};

#endif // POINT2D_H


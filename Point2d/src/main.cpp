#include "point2d.h"
#include <iostream>
int main(){
    // Crear un objeto Point2d
    Point2d p1(3.0, 4.0);
    Point2d p2(1.0, 2.0);

    // Mostrar las coordenadas del punto
    std::cout << "Punto 1: (" << p1.getX() << ", " << p1.getY() << ")" << std::endl;
    std::cout << "Punto 2: (" << p2.getX() << ", " << p2.getY() << ")" << std::endl;

    // Sumar dos puntos
    Point2d p3 = p1 + p2;
    std::cout << "Suma de P1 y P2: (" << p3.getX() << ", " << p3.getY() << ")" << std::endl;

    // Restar dos puntos
    Point2d p4 = p1 - p2;
    std::cout << "Resta de P1 y P2: (" << p4.getX() << ", " << p4.getY() << ")" << std::endl;

    // Multiplicar un punto por un escalar
    Point2d p5 = p1 * 2.0;
    std::cout << "Multiplicación de P1 por 2: (" << p5.getX() << ", " << p5.getY() << ")" << std::endl;

    // Dividir un punto por un escalar
    Point2d p6 = p1 / 2.0;
    std::cout << "División de P1 por 2: (" << p6.getX() << ", " << p6.getY() << ")" << std::endl;

    // Calcular la distancia entre dos puntos
    double distance = p1.distanceto(p2);
    std::cout << "Distancia entre P1 y P2: " << distance << std::endl;

    // Calcular la distancia de un punto al origen
    double distanceToOrigin = p1.distanceToOrigin();
    std::cout << "Distancia de P1 al origen: " << distanceToOrigin << std::endl;

    // Calcular el punto medio entre dos puntos
    Point2d midpoint = p1.midpoint(p2);
    std::cout << "Punto medio entre P1 y P2: (" 
              << midpoint.getX() 
              << ", " 
              << midpoint.getY() 
              << ")" 
              << std::endl;
    // Calcular el vector unitario de un punto
    Point2d unitVector = p1.unitvector();
    std::cout << "Vector unitario de P1: (" 
              << unitVector.getX() 
              << ", " 
              << unitVector.getY() 
              << ")" 
              << std::endl;

    return 0;
}
#ifndef POINT2D_H
#define POINT2D_H
#include <cmath>
class Point2d {
    private:
        double x;
        double y;
    public:
    // Constructor
        Point2d();
        Point2d(double x, double y);
        Point2d(const Point2d& other);
    //getters
        double getX() const;
        double getY() const;
    //setters
        void setX(double x);
        void setY(double y);
    //operadores sobrecargados
        Point2d operator+(const Point2d& other) const;
        Point2d operator-(const Point2d& other) const;
        Point2d operator*(double scalar) const;
        Point2d operator/(double scalar) const;
        Point2d& operator=(const Point2d& other);
    //metodos adicionales
    double distanceto(const Point2d& other) const;
    double distanceToOrigin() const;
    Point2d midpoint(const Point2d& other) const;
    Point2d unitvector() const;
};

#endif // POINT2D_H


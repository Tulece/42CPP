#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point {
private:
	Fixed const _x;
	Fixed const _y;

public:
	Point();  // Constructeur par défaut
	Point(const float x, const float y);  // Constructeur avec coordonnées flottantes
	Point(const Point &other);  // Constructeur de recopie
	Point& operator=(const Point &other);  // Surcharge de l'opérateur d'affectation
	~Point();  // Destructeur

	Fixed getX() const;  // Récupère la coordonnée x
	Fixed getY() const;  // Récupère la coordonnée y
};

#endif

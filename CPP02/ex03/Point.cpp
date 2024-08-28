#include "Point.hpp"

// Constructeur par défaut
Point::Point() : _x(0), _y(0) {}

// Constructeur avec coordonnées flottantes
Point::Point(const float x, const float y) : _x(x), _y(y) {}

// Constructeur de recopie
Point::Point(const Point &other) : _x(other._x), _y(other._y) {}

// Surcharge de l'opérateur d'affectation
Point& Point::operator=(const Point &other) {
    // Les membres `_x` et `_y` sont constants, donc ils ne peuvent pas être réassignés.
    // Une affectation comme celle-ci n'a pas de sens pour cette classe.
    // On pourrait simplement faire un retour de l'objet courant.
    if (this == &other) {
        return *this;
    }
    // Pas d'affectation possible pour les attributs constants.
    return *this;
}

// Destructeur
Point::~Point() {}

// Récupère la coordonnée x
Fixed Point::getX() const {
    return this->_x;
}

// Récupère la coordonnée y
Fixed Point::getY() const {
    return this->_y;
}

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>  // Pour utiliser roundf

class Fixed {
private:
	int _fixedPointValue;
	static const int _fractionalBits = 8;

public:
	Fixed();  // Constructeur par défaut
	Fixed(const int value);  // Constructeur pour les entiers
	Fixed(const float value);  // Constructeur pour les flottants
	Fixed(const Fixed &other);  // Constructeur de recopie
	Fixed& operator=(const Fixed &other);  // Surcharge de l'opérateur d'affectation
	~Fixed();  // Destructeur

	int getRawBits(void) const;
	void setRawBits(int const raw);

	float toFloat(void) const;  // Convertir en flottant
	int toInt(void) const;  // Convertir en entier
};

// Surcharge de l’opérateur d’insertion <<
std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif

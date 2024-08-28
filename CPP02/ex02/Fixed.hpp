#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

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

	float toFloat(void) const;
	int toInt(void) const;

	// Surcharges des opérateurs de comparaison
	bool operator>(const Fixed &other) const;
	bool operator<(const Fixed &other) const;
	bool operator>=(const Fixed &other) const;
	bool operator<=(const Fixed &other) const;
	bool operator==(const Fixed &other) const;
	bool operator!=(const Fixed &other) const;

	// Surcharges des opérateurs arithmétiques
	Fixed operator+(const Fixed &other) const;
	Fixed operator-(const Fixed &other) const;
	Fixed operator*(const Fixed &other) const;
	Fixed operator/(const Fixed &other) const;

	// Surcharges des opérateurs d'incrémentation et de décrémentation
	Fixed& operator++();  // Pré-incrémentation
	Fixed operator++(int);  // Post-incrémentation
	Fixed& operator--();  // Pré-décrémentation
	Fixed operator--(int);  // Post-décrémentation

	// Fonctions membres statiques
	static Fixed& min(Fixed &a, Fixed &b);
	static const Fixed& min(const Fixed &a, const Fixed &b);
	static Fixed& max(Fixed &a, Fixed &b);
	static const Fixed& max(const Fixed &a, const Fixed &b);
};

// Surcharge de l’opérateur d’insertion <<
std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif

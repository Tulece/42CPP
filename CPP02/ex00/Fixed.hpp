#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed {
private:
	int _fixedPointValue; // Stocke la valeur du nombre en virgule fixe
	static const int _fractionalBits = 8; // Nombre de bits pour la partie fractionnaire

public:
	Fixed();  // Constructeur par défaut
	Fixed(const Fixed &other);  // Constructeur de recopie
	Fixed& operator=(const Fixed &other);  // Surcharge de l'opérateur d'affectation
	~Fixed();  // Destructeur

	int getRawBits(void) const;  // Récupère la valeur brute
	void setRawBits(int const raw);  // Initialise la valeur brute
};

#endif

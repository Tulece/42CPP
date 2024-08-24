#include "Fixed.hpp"

// Constructeur par défaut
Fixed::Fixed() : _fixedPointValue(0) {
	std::cout << "Default constructor called" << std::endl;
}

// Constructeur pour les entiers
Fixed::Fixed(const int value) {
	std::cout << "Int constructor called" << std::endl;
	this->_fixedPointValue = value << _fractionalBits;
}

// Constructeur pour les flottants
Fixed::Fixed(const float value) {
	std::cout << "Float constructor called" << std::endl;
	this->_fixedPointValue = roundf(value * (1 << _fractionalBits));
}

// Constructeur de recopie
Fixed::Fixed(const Fixed &other) {
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

// Surcharge de l'opérateur d'affectation
Fixed& Fixed::operator=(const Fixed &other) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other) {
		this->_fixedPointValue = other.getRawBits();
	}
	return *this;
}

// Destructeur
Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

// Récupérer la valeur brute
int Fixed::getRawBits(void) const {
	return this->_fixedPointValue;
}

// Initialiser la valeur brute
void Fixed::setRawBits(int const raw) {
	this->_fixedPointValue = raw;
}

// Convertir en flottant
float Fixed::toFloat(void) const {
	return static_cast<float>(this->_fixedPointValue) / (1 << _fractionalBits);
}

// Convertir en entier
int Fixed::toInt(void) const {
	return this->_fixedPointValue >> _fractionalBits;
}

// Surcharge de l'opérateur d'insertion <<
std::ostream &operator<<(std::ostream &out, const Fixed &fixed) {
	out << fixed.toFloat();
	return out;
}

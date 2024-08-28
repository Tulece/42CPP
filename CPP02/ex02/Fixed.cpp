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

// Destructeur
Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

// Surcharge de l'opérateur d'affectation
Fixed& Fixed::operator=(const Fixed &other) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other) {
		this->_fixedPointValue = other.getRawBits();
	}
	return *this;
}

// Implémentation des opérateurs arithmétiques
Fixed Fixed::operator+(const Fixed &other) const {
	Fixed result;
	result.setRawBits(this->_fixedPointValue + other.getRawBits());
	return result;
}

Fixed Fixed::operator-(const Fixed &other) const {
	Fixed result;
	result.setRawBits(this->_fixedPointValue - other.getRawBits());
	return result;
}

Fixed Fixed::operator*(const Fixed &other) const {
	Fixed result;
	result.setRawBits((this->_fixedPointValue * other.getRawBits()) >> _fractionalBits);
	return result;
}

Fixed Fixed::operator/(const Fixed &other) const {
	if (other.getRawBits() == 0) {
		std::cerr << "Error: Division by zero" << std::endl;
		return Fixed();
	}
	Fixed result;
	result.setRawBits((this->_fixedPointValue << _fractionalBits) / other.getRawBits());
	return result;
}

// Surcharge des opérateurs de comparaison
bool Fixed::operator>(const Fixed &other) const {
	return this->_fixedPointValue > other._fixedPointValue;
}

bool Fixed::operator<(const Fixed &other) const {
	return this->_fixedPointValue < other._fixedPointValue;
}

bool Fixed::operator>=(const Fixed &other) const {
	return this->_fixedPointValue >= other._fixedPointValue;
}

bool Fixed::operator<=(const Fixed &other) const {
	return this->_fixedPointValue <= other._fixedPointValue;
}

bool Fixed::operator==(const Fixed &other) const {
	return this->_fixedPointValue == other._fixedPointValue;
}

bool Fixed::operator!=(const Fixed &other) const {
	return this->_fixedPointValue != other._fixedPointValue;
}

// Surcharges des opérateurs d'incrémentation
Fixed& Fixed::operator++() {  // Pré-incrémentation
	this->_fixedPointValue++;
	return *this;
}

Fixed Fixed::operator++(int) {  // Post-incrémentation
	Fixed temp(*this);
	this->_fixedPointValue++;
	return temp;
}

Fixed& Fixed::operator--() {  // Pré-décrémentation
	this->_fixedPointValue--;
	return *this;
}

Fixed Fixed::operator--(int) {  // Post-décrémentation
	Fixed temp(*this);
	this->_fixedPointValue--;
	return temp;
}

// Fonctions membres statiques min et max
Fixed& Fixed::min(Fixed &a, Fixed &b) {
	return (a < b) ? a : b;
}

const Fixed& Fixed::min(const Fixed &a, const Fixed &b) {
	return (a < b) ? a : b;
}

Fixed& Fixed::max(Fixed &a, Fixed &b) {
	return (a > b) ? a : b;
}

const Fixed& Fixed::max(const Fixed &a, const Fixed &b) {
	return (a > b) ? a : b;
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

// Surcharge de l’opérateur d’insertion <<
std::ostream &operator<<(std::ostream &out, const Fixed &fixed) {
	out << fixed.toFloat();
	return out;
}

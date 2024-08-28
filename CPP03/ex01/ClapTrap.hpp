#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <string>
#include <iostream>

class ClapTrap {
protected: // Permet l'accès aux classes dérivées
	std::string name;
	int hitPoints;
	int energyPoints;
	int attackDamage;

public:
	// Constructor
	ClapTrap(const std::string& name);

	// Destructor
	~ClapTrap();

	// Copy constructor
	ClapTrap(const ClapTrap& other);

	// Assignment operator
	ClapTrap& operator=(const ClapTrap& other);

	// Member functions
	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
};

#endif

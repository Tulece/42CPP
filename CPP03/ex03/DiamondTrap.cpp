#include "DiamondTrap.hpp"
#include <iostream>

// Constructor
DiamondTrap::DiamondTrap(const std::string& name)
	: ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name), name(name) {
	this->hitPoints = FragTrap::hitPoints;           // 100 points de vie de FragTrap
	this->energyPoints = ScavTrap::getSavedEnergyPoints();  // 50 points d'énergie de ScavTrap
	this->attackDamage = FragTrap::attackDamage;     // 30 points de dégâts de FragTrap

	std::cout << "DiamondTrap " << this->name << " created with "
			  << this->hitPoints << " hit points, "
			  << this->energyPoints << " energy points, and "
			  << this->attackDamage << " attack damage." << std::endl;
}

// Destructor
DiamondTrap::~DiamondTrap() {
	std::cout << "DiamondTrap " << this->name << " destroyed." << std::endl;
}

// attack function
void DiamondTrap::attack(const std::string& target) {
	ScavTrap::attack(target);  // Utilise ScavTrap::attack() avec le nom sans suffixe
}

// whoAmI function
void DiamondTrap::whoAmI() {
	std::cout << "I am " << this->name << " and my ClapTrap name is " << ClapTrap::name << std::endl;
}

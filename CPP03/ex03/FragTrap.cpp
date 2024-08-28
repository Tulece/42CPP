// FragTrap.cpp

#include "FragTrap.hpp"

FragTrap::FragTrap(const std::string& name)
	: ClapTrap(name) { // Appel du constructeur de ClapTrap
	hitPoints = 100;
	energyPoints = 100;
	attackDamage = 30;
	std::cout << "FragTrap " << name << " created." << std::endl;
}

FragTrap::~FragTrap() {
	std::cout << "FragTrap " << name << " destroyed." << std::endl;
}

void FragTrap::attack(const std::string& target) {
	if (hitPoints <= 0) {
		std::cout << "FragTrap " << name << " cannot attack because it has no hit points left!" << std::endl;
		return;
	}

	if (energyPoints > 0) {
		std::cout << "FragTrap " << name << " powerfully attacks " << target << ", causing " << attackDamage << " points of damage!" << std::endl;
		energyPoints--;
	} else {
		std::cout << "FragTrap " << name << " has no energy left to attack!" << std::endl;
	}
}

void FragTrap::highFivesGuys(void) {
	std::cout << "FragTrap " << name << " requests a positive high five!" << std::endl;
}

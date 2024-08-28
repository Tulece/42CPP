#include "ClapTrap.hpp"

ClapTrap::ClapTrap(const std::string& name)
	: name(name), hitPoints(10), energyPoints(10), attackDamage(0) {
	std::cout << "ClapTrap " << name << " created." << std::endl;
}

ClapTrap::~ClapTrap() {
	std::cout << "ClapTrap " << name << " destroyed." << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other)
	: name(other.name), hitPoints(other.hitPoints), energyPoints(other.energyPoints), attackDamage(other.attackDamage) {
	std::cout << "ClapTrap " << other.name << " copied." << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other) {
	if (this != &other) {
		name = other.name;
		hitPoints = other.hitPoints;
		energyPoints = other.energyPoints;
		attackDamage = other.attackDamage;
	}
	std::cout << "ClapTrap " << other.name << " assigned." << std::endl;
	return *this;
}

void ClapTrap::attack(const std::string& target) {
	if (hitPoints <= 0) {
		std::cout << "ClapTrap " << name << " cannot attack because it has no hit points left!" << std::endl;
		return;
	}

	if (energyPoints > 0) {
		std::cout << "ClapTrap " << name << " attacks " << target << ", causing " << attackDamage << " points of damage!" << std::endl;
		energyPoints--;
	} else {
		std::cout << "ClapTrap " << name << " has no energy left to attack!" << std::endl;
	}
}

void ClapTrap::takeDamage(unsigned int amount) {
	if (hitPoints <= 0) {
		std::cout << "ClapTrap " << name << " is already destroyed!" << std::endl;
		return;
	}

	hitPoints -= amount;
	if (hitPoints < 0) {
		hitPoints = 0;
	}
	std::cout << "ClapTrap " << name << " takes " << amount << " points of damage, remaining hit points: " << hitPoints << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (hitPoints <= 0) {
		std::cout << "ClapTrap " << name << " cannot be repaired because it is destroyed!" << std::endl;
		return;
	}

	if (energyPoints > 0) {
		hitPoints += amount;
		std::cout << "ClapTrap " << name << " repairs itself, gaining " << amount << " hit points, total hit points: " << hitPoints << std::endl;
		energyPoints--;
	} else {
		std::cout << "ClapTrap " << name << " has no energy left to repair itself!" << std::endl;
	}
}

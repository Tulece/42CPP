#include "ScavTrap.hpp"

int ScavTrap::savedEnergyPoints = 50; // Initialisation de la variable statique

ScavTrap::ScavTrap(const std::string& name)
    : ClapTrap(name) { // Appel du constructeur de ClapTrap
    hitPoints = 100;
    energyPoints = 50;  // Assignation de la valeur par défaut
    attackDamage = 20;
    savedEnergyPoints = energyPoints; // Sauvegarde de la valeur d'energyPoints
    std::cout << "ScavTrap " << name << " created." << std::endl;
}

ScavTrap::~ScavTrap() {
    std::cout << "ScavTrap " << name << " destroyed." << std::endl;
}

void ScavTrap::attack(const std::string& target) {
    if (this->hitPoints <= 0) {
        std::cout << "ScavTrap " << this->name << " cannot attack because it has no hit points left!" << std::endl;
        return;
    }

    if (this->energyPoints > 0) {
        std::cout << "ScavTrap " << this->name << " ferociously attacks " << target
                  << ", causing " << this->attackDamage << " points of damage!" << std::endl;
        this->energyPoints--;
    } else {
        std::cout << "ScavTrap " << this->name << " has no energy left to attack!" << std::endl;
    }
}

void ScavTrap::guardGate() {
    std::cout << "ScavTrap " << name << " is now in Gate keeper mode." << std::endl;
}

int ScavTrap::getSavedEnergyPoints() {
    return savedEnergyPoints;
}

void ScavTrap::setSavedEnergyPoints(int points) {
    savedEnergyPoints = points;
}

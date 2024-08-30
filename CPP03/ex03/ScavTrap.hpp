#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap {
public:
    // Constructor
    ScavTrap(const std::string& name);

    // Destructor
    ~ScavTrap();

    // Member functions
    void attack(const std::string& target);
    void guardGate();

    // Static function to get and set ScavTrap's energy points
    static int getSavedEnergyPoints();
    static void setSavedEnergyPoints(int points);

private:
    static int savedEnergyPoints; // Static variable to store ScavTrap's energy points
};

#endif

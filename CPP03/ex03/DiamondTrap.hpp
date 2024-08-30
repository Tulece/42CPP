#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap {
private:
    std::string name; // Nom propre à DiamondTrap

public:
    // Constructor
    DiamondTrap(const std::string& name);

    // Destructor
    ~DiamondTrap();

    // Member functions
    void whoAmI();
    void attack(const std::string& target);
};

#endif

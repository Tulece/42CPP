// DiamondTrap.hpp

#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap {
private:
	std::string name; // Conflit de nom intentionnel avec ClapTrap
public:
	// Constructor
	DiamondTrap(const std::string& name);

	// Destructor
	~DiamondTrap();

	void whoAmI();
	using ScavTrap::attack; // Prendre l'attaque de ScavTrap, comme spécifié
};

#endif

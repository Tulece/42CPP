// ScavTrap.hpp

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
};

#endif

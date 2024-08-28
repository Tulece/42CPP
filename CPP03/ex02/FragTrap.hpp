#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap {
public:
	// Constructor
	FragTrap(const std::string& name);

	// Destructor
	~FragTrap();

	// Member functions
	void attack(const std::string& target);
	void highFivesGuys();
};

#endif

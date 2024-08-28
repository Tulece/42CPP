// main.cpp

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main() {
	ClapTrap clap("CL4P-TP");

	clap.attack("target");
	clap.takeDamage(3);
	clap.beRepaired(5);

	ScavTrap scav("SC4V-TP");

	scav.attack("target");
	scav.takeDamage(30);
	scav.beRepaired(20);
	scav.guardGate();

	FragTrap frag("FR4G-TP");

	frag.attack("target");
	frag.takeDamage(50);
	frag.beRepaired(50);
	frag.highFivesGuys();

	DiamondTrap diamond("DI4M-TP");

	diamond.attack("target");
	diamond.takeDamage(30);
	diamond.beRepaired(20);
	diamond.whoAmI();

	return 0;
}

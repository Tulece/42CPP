#include "ClapTrap.hpp"

int main() {
	ClapTrap clap("CL4P-TP");

	clap.attack("target");
	clap.takeDamage(3);
	clap.beRepaired(5);

	clap.takeDamage(10);
	clap.attack("target");
	clap.beRepaired(5);

	return 0;
}

#include "Zombie.hpp"

int main() {
	int N = 5;
	Zombie* horde = zombieHorde(N, "HordeZombie");

	for (int i = 0; i < N; ++i) {
		horde[i].announce();
	}

	// Libération de la mémoire
	delete[] horde;

	return 0;
}

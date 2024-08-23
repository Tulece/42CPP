#include "Zombie.hpp"

int main() {
	// Créer un zombie sur la pile
	randomChump("StackZombie");

	// Créer un zombie sur le tas
	Zombie* heapZombie = newZombie("HeapZombie");
	heapZombie->announce();

	// Libérer la mémoire allouée pour le zombie sur le tas
	delete heapZombie;

	return 0;
}

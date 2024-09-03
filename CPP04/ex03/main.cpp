#include "Character.hpp"
#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include <iostream>

// Codes couleurs ANSI pour la sortie console
#define RESET   "\033[0m"
#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */
#define YELLOW  "\033[33m"      /* Yellow */
#define BLUE    "\033[34m"      /* Blue */
#define MAGENTA "\033[35m"      /* Magenta */
#define CYAN    "\033[36m"      /* Cyan */
#define WHITE   "\033[37m"      /* White */

int main() {
    std::cout << YELLOW << "Creating MateriaSource..." << RESET << std::endl;
    IMateriaSource* src = new MateriaSource();

    std::cout << YELLOW << "Learning new Materias (Ice, Cure)..." << RESET << std::endl;
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());

    std::cout << YELLOW << "Creating Character 'me'..." << RESET << std::endl;
    ICharacter* me = new Character("me");

    AMateria* tmp;
    std::cout << YELLOW << "Creating and equipping Materia 'ice'..." << RESET << std::endl;
    tmp = src->createMateria("ice");
    me->equip(tmp);

    std::cout << YELLOW << "Creating and equipping Materia 'cure'..." << RESET << std::endl;
    tmp = src->createMateria("cure");
    me->equip(tmp);

    std::cout << YELLOW << "Creating Character 'bob'..." << RESET << std::endl;
    ICharacter* bob = new Character("bob");

    std::cout << CYAN << "Using Materia at index 0 on 'bob'..." << RESET << std::endl;
    me->use(0, *bob); // Should print: * shoots an ice bolt at bob *

    std::cout << CYAN << "Using Materia at index 1 on 'bob'..." << RESET << std::endl;
    me->use(1, *bob); // Should print: * heals bob's wounds *

    // Additional tests
    std::cout << YELLOW << "Unequipping Materia at index 0..." << RESET << std::endl;
    me->unequip(0);

    std::cout << YELLOW << "Attempting to use unequipped Materia at index 0..." << RESET << std::endl;
    me->use(0, *bob); // Should do nothing

    std::cout << YELLOW << "Re-equipping Materia 'ice'..." << RESET << std::endl;
    tmp = src->createMateria("ice");
    me->equip(tmp);

    std::cout << CYAN << "Using re-equipped Materia at index 0 on 'bob'..." << RESET << std::endl;
    me->use(0, *bob); // Should print: * shoots an ice bolt at bob *

    // Clean up
    std::cout << YELLOW << "Cleaning up resources..." << RESET << std::endl;

    delete bob;
    delete me;
    delete src;

    std::cout << GREEN << "All resources cleaned up successfully!" << RESET << std::endl;

    return 0;
}

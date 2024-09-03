#include "Cat.hpp"

Cat::Cat() {
	try {
		brain = new Brain();
		type = "Cat";
		std::cout << "Cat constructor called" << std::endl;
	} catch (const std::bad_alloc& e) {
		std::cerr << "Failed to allocate memory for Cat's Brain: " << e.what() << std::endl;
		brain = NULL;
	}
}

Cat::Cat(const Cat& other) : Animal(other), brain(new Brain(*other.brain)) {
	std::cout << "Cat copy constructor called" << std::endl;
}

Cat& Cat::operator=(const Cat& other) {
	std::cout << "Cat assignment operator called" << std::endl;
	if (this != &other) {
		Animal::operator=(other);
		delete brain;
		brain = new Brain(*other.brain);
	}
	return *this;
}

Cat::~Cat() {
	delete brain;
	std::cout << "Cat destructor called" << std::endl;
}

void Cat::makeSound() const {
	std::cout << "Meow!" << std::endl;
}

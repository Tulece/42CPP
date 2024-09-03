#include "Harl.hpp"

void Harl::debug() {
	std::cout << "[ DEBUG ]" << std::endl;
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
}

void Harl::info() {
	std::cout << "[ INFO ]" << std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void Harl::warning() {
	std::cout << "[ WARNING ]" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::error() {
	std::cout << "[ ERROR ]" << std::endl;
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void Harl::complain(std::string level) {
	void (Harl::*funcPtr)() = NULL;

	if (level == "DEBUG")
		funcPtr = &Harl::debug;
	else if (level == "INFO")
		funcPtr = &Harl::info;
	else if (level == "WARNING")
		funcPtr = &Harl::warning;
	else if (level == "ERROR")
		funcPtr = &Harl::error;

	if (funcPtr)
		(this->*funcPtr)();
	else
		std::cerr << "Invalid level: " << level << std::endl;
}

void Harl::filter(std::string level) {
	int levelIndex;

	if (level == "DEBUG")
		levelIndex = 0;
	else if (level == "INFO")
		levelIndex = 1;
	else if (level == "WARNING")
		levelIndex = 2;
	else if (level == "ERROR")
		levelIndex = 3;
	else {
		std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
		return;
	}

	switch (levelIndex) {
		case 0:
			debug();
		case 1:
			info();
		case 2:
			warning();
		case 3:
			error();
			break;
		default:
			std::cerr << "Unknown error occurred in switch statement." << std::endl;
	}
}

#include "Harl.hpp"

void Harl::debug() {
	std::cout << "DEBUG: I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
}

void Harl::info() {
	std::cout << "INFO: I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void Harl::warning() {
	std::cout << "WARNING: I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::error() {
	std::cout << "ERROR: This is unacceptable! I want to speak to the manager now." << std::endl;
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

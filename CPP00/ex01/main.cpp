#include "PhoneBook.hpp"
#include <iostream>

int main() {
	PhoneBook phoneBook;
	std::string command;

	while (true) {
		std::cout << "Enter a command (ADD, SEARCH, EXIT): ";
		if (!std::getline(std::cin, command)) {
			std::cout << "\nEOF detected. Exiting program." << std::endl;
			break;
		}

		if (command == "ADD") {
			Contact contact;
			std::string firstName, lastName, nickname, phoneNumber, darkestSecret;

			do {
				std::cout << "First Name: ";
				if (!std::getline(std::cin, firstName)) {
					std::cout << "\nEOF detected. Exiting program." << std::endl;
					return 0;
				}
			} while (firstName.empty());

			do {
				std::cout << "Last Name: ";
				if (!std::getline(std::cin, lastName)) {
					std::cout << "\nEOF detected. Exiting program." << std::endl;
					return 0;
				}
			} while (lastName.empty());

			do {
				std::cout << "Nickname: ";
				if (!std::getline(std::cin, nickname)) {
					std::cout << "\nEOF detected. Exiting program." << std::endl;
					return 0;
				}
			} while (nickname.empty());

			do {
				std::cout << "Phone Number: ";
				if (!std::getline(std::cin, phoneNumber)) {
					std::cout << "\nEOF detected. Exiting program." << std::endl;
					return 0;
				}
			} while (phoneNumber.empty());

			do {
				std::cout << "Darkest Secret: ";
				if (!std::getline(std::cin, darkestSecret)) {
					std::cout << "\nEOF detected. Exiting program." << std::endl;
					return 0;
				}
			} while (darkestSecret.empty());

			contact.setDetails(firstName, lastName, nickname, phoneNumber, darkestSecret);
			phoneBook.addContact(contact);
		} else if (command == "SEARCH") {
			phoneBook.searchContact();
		} else if (command == "EXIT") {
			break;
		} else if (!command.empty()) {
			std::cout << "Unknown command!" << std::endl;
		}

		// Pour s'assurer que EOF n'a pas été atteint lors d'une lecture
		if (std::cin.eof()) {
			std::cout << "\nEOF detected. Exiting program." << std::endl;
			break;
		}
	}

	return 0;
}


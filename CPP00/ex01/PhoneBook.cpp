#include "PhoneBook.hpp"
#include <iostream>
#include <limits>

PhoneBook::PhoneBook() : oldestContactIndex(0), contactCount(0) {}

void PhoneBook::addContact(const Contact& contact) {
	if (contactCount < 8) {
		contacts[contactCount] = contact;
		contactCount++;
	} else {
		contacts[oldestContactIndex] = contact;
		oldestContactIndex = (oldestContactIndex + 1) % 8;
	}
}

void PhoneBook::printContacts() const {
	std::cout << "| Index | First Name | Last Name  | Nickname  |" << std::endl;
	for (int i = 0; i < contactCount; ++i) {
		contacts[i].printSummary(i + 1);
	}
}

void PhoneBook::searchContact() const {
	printContacts();

	if (contactCount == 0) {
		std::cout << "No contacts available to search." << std::endl;
		return;
	}

	std::cout << "Enter index to view details (1-" << contactCount << "): ";
	int index;

	// Vérification de l'entrée utilisateur
	while (!(std::cin >> index) || std::cin.peek() != '\n' || index < 1 || index > contactCount) {
		std::cout << "Invalid index. Please enter a number between 1 and " << contactCount << ": ";
		std::cin.clear(); // Effacer les erreurs
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}

	// Afficher les détails du contact sélectionné
	contacts[index - 1].printDetails();
}

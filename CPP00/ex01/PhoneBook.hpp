#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook {
public:
	PhoneBook();
	void addContact(const Contact& contact);
	void printContacts() const;
	void searchContact() const;

private:
	Contact contacts[8];
	int oldestContactIndex;
	int contactCount;
};

#endif

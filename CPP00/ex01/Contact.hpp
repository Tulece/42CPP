#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

class Contact {
public:
	Contact();
	void setDetails(const std::string& firstName, const std::string& lastName, const std::string& nickname, const std::string& phoneNumber, const std::string& darkestSecret);
	void printSummary(int index) const;
	void printDetails() const;

private:
	std::string firstName;
	std::string lastName;
	std::string nickname;
	std::string phoneNumber;
	std::string darkestSecret;
};

#endif

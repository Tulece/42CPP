// Warlock.hpp

#ifndef WARLOCK_HPP
#define WARLOCK_HPP

#include <string>
#include <iostream>

class Warlock {
private:
	std::string _name;
	std::string _title;

	// Private constructors to prevent copying
	Warlock();
	Warlock(Warlock const &);
	Warlock & operator=(Warlock const &);

public:
	Warlock(std::string const & name, std::string const & title);
	~Warlock();

	std::string const & getName() const;
	std::string const & getTitle() const;
	void setTitle(std::string const & title);

	void introduce() const;
};

#endif

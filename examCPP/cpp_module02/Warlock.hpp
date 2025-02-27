#pragma once

#include <string>
#include <iostream>
#include <map>

#include "ASpell.hpp"
#include "ATarget.hpp"
#include "SpellBook.hpp"

class ASpell;
class ATarget;

class Warlock {
private:
	std::string _name;
	std::string _title;

	SpellBook SpellBook;
	Warlock(Warlock const &);
	Warlock & operator=(Warlock const &);

public:
	Warlock(std::string const & name, std::string const & title);
	~Warlock();

	std::string const & getName() const;
	std::string const & getTitle() const;

	void setTitle(std::string const & title);

	void introduce() const;

	void learnSpell(ASpell* spell);
	void forgetSpell(std::string spellName);
	void launchSpell(std::string spellName, ATarget const & target);
};

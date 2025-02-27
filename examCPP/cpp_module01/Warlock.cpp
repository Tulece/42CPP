#include "Warlock.hpp"

Warlock::Warlock(std::string const & name, std::string const & title) : _name(name), _title(title) {
	std::cout << _name << ": This looks like another boring day." << std::endl;
}

Warlock::~Warlock() {
	std::cout << _name << ": My job here is done!" << std::endl;
}

std::string const & Warlock::getName() const {
	return _name;
}

std::string const & Warlock::getTitle() const {
	return _title;
}

void Warlock::setTitle(std::string const & title) {
	_title = title;
}

void Warlock::introduce() const {
	std::cout << _name << ": I am " << _name << ", " << _title << "!" << std::endl;
}

void Warlock::learnSpell(ASpell* spell) {
	if (spell) {
		if (_SpellBook.find(spell->getName()) == _SpellBook.end())
			_SpellBook[spell->getName()] = spell->clone();
	}
}

void Warlock::forgetSpell(std::string spellName) {
	if (_SpellBook.find(spellName) != _SpellBook.end())
		_SpellBook.erase(_SpellBook.find(spellName));
}

void Warlock::launchSpell(std::string spellName, ATarget const & target) {
	if (_SpellBook.find(spellName) != _SpellBook.end())
		_SpellBook[spellName]->launch(target);
}

#include "SpellBook.hpp"

SpellBook::SpellBook() {}

SpellBook::~SpellBook() {}

void SpellBook::learnSpell(ASpell* spell) {
	if (spell) {
		if (_SpellBook.find(spell->getName()) == _SpellBook.end())
			_SpellBook[spell->getName()] = spell->clone();
	}
}

void SpellBook::forgetSpell(std::string const & spellName) {
	if (_SpellBook.find(spellName) != _SpellBook.end())
		_SpellBook.erase(_SpellBook.find(spellName));
}

ASpell* SpellBook::createSpell(std::string const & spellName) {
	ASpell* spell = NULL;
	if (_SpellBook.count(spellName))
		spell = _SpellBook.find(spellName)->second->clone();
	return spell;
}

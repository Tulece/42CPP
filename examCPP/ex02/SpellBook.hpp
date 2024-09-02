// SpellBook.hpp

#ifndef SPELLBOOK_HPP
#define SPELLBOOK_HPP

#include <string>
#include <map>
#include "ASpell.hpp"

class SpellBook {
private:
    std::map<std::string, ASpell*> spells;

    SpellBook(SpellBook const &);
    SpellBook & operator=(SpellBook const &);

public:
    SpellBook();
    ~SpellBook();

    void learnSpell(ASpell* spell);
    void forgetSpell(std::string const & spellName);
    ASpell* createSpell(std::string const & spellName);
};

#endif

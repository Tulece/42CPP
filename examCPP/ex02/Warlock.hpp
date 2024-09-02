// Warlock.hpp

#ifndef WARLOCK_HPP
#define WARLOCK_HPP

#include <string>
#include <iostream>
#include "SpellBook.hpp"

class Warlock {
private:
    std::string name;
    std::string title;
    SpellBook spellBook;

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

    void learnSpell(ASpell* spell);
    void forgetSpell(std::string const & spellName);
    void launchSpell(std::string const & spellName, ATarget const & target);
};

#endif

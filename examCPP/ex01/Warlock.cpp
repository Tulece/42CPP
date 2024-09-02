// Warlock.cpp

#include "Warlock.hpp"

Warlock::Warlock(std::string const & name, std::string const & title)
    : name(name), title(title) {
    std::cout << name << ": This looks like another boring day." << std::endl;
}

Warlock::~Warlock() {
    std::cout << name << ": My job here is done!" << std::endl;
    for (std::map<std::string, ASpell*>::iterator it = spells.begin(); it != spells.end(); ++it) {
        delete it->second;
    }
}

std::string const & Warlock::getName() const {
    return name;
}

std::string const & Warlock::getTitle() const {
    return title;
}

void Warlock::setTitle(std::string const & title) {
    this->title = title;
}

void Warlock::introduce() const {
    std::cout << name << ": I am " << name << ", " << title << "!" << std::endl;
}

void Warlock::learnSpell(ASpell* spell) {
    if (spell)
        spells[spell->getName()] = spell->clone();
}

void Warlock::forgetSpell(std::string const & spellName) {
    std::map<std::string, ASpell*>::iterator it = spells.find(spellName);
    if (it != spells.end()) {
        delete it->second;
        spells.erase(it);
    }
}

void Warlock::launchSpell(std::string const & spellName, ATarget const & target) {
    std::map<std::string, ASpell*>::iterator it = spells.find(spellName);
    if (it != spells.end())
        it->second->launch(target);
}

#include "ASpell.hpp"

ASpell::ASpell(std::string const & name, std::string const & effects) : name(name), effects(effects) {}

ASpell::~ASpell() {}

ASpell::ASpell(ASpell const & ref) {
	*this = ref;
}

ASpell & ASpell::operator=(ASpell const & ref) {
	if (this != &ref) {
		name = ref.getName();
		effects = ref.getEffects();
	}
	return *this;
}

std::string const & ASpell::getName() const {
	return name;
}

std::string const & ASpell::getEffects() const {
	return effects;
}

void ASpell::launch(ATarget const & target) const {
	target.getHitBySpell(*this);
}

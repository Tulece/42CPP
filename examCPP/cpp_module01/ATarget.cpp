#include "ATarget.hpp"

ATarget::ATarget(std::string const & type) : type(type) {}

ATarget::~ATarget() {}

ATarget::ATarget(ATarget const & ref) {
	*this = ref;
}

ATarget & ATarget::operator=(ATarget const & ref) {
	if (this != &ref) {
		type = ref.getType();
	}
	return *this;
}

std::string const & ATarget::getType() const {
	return type;
}

void ATarget::getHitBySpell(ASpell const & spell) const {
	std::cout << type << " has been " << spell.getEffects() << "!" << std::endl;
}

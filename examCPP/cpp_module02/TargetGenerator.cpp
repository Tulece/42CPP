#include "TargetGenerator.hpp"

TargetGenerator::TargetGenerator() {}

TargetGenerator::~TargetGenerator() {}

void TargetGenerator::learnTargetType(ATarget* spell) {
	if (spell) {
		if (_TargetGenerator.find(spell->getType()) == _TargetGenerator.end())
			_TargetGenerator[spell->getType()] = spell->clone();
	}
}

void TargetGenerator::forgetTargetType(std::string const & spellName) {
	if (_TargetGenerator.find(spellName) != _TargetGenerator.end())
		_TargetGenerator.erase(_TargetGenerator.find(spellName));
}

ATarget* TargetGenerator::createTarget(std::string const & spellName) {
	ATarget* spell = NULL;
	if (_TargetGenerator.count(spellName))
		spell = _TargetGenerator.find(spellName)->second->clone();
	return spell;
}

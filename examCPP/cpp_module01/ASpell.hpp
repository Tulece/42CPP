#pragma once

#include <string>
#include <iostream>

#include "ATarget.hpp"

class ATarget;

class ASpell {
private:
	std::string name;
	std::string effects;

public:
	ASpell(std::string const & name, std::string const & effects);
	virtual ~ASpell();
	ASpell(ASpell const & ref);
	ASpell & operator=(ASpell const & ref);

	std::string const & getName() const;
	std::string const & getEffects() const;

	virtual ASpell* clone() const = 0;

	void launch(ATarget const & target) const;
};

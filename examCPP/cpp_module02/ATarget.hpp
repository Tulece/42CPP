#pragma once

#include <string>
#include <iostream>

#include "ASpell.hpp"

class ASpell;

class ATarget {
private:
	std::string type;

public:
	ATarget(std::string const & type);
	virtual ~ATarget();
	ATarget(ATarget const & ref);
	ATarget & operator=(ATarget const & ref);

	std::string const & getType() const;

	virtual ATarget* clone() const = 0;

	void getHitBySpell(ASpell const & spell) const;
};

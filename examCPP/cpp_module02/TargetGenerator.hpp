#pragma once

#include <string>
#include <iostream>
#include <map>

#include "ATarget.hpp"

class TargetGenerator {
private:
	std::map<std::string, ATarget*> _TargetGenerator;
	TargetGenerator(TargetGenerator const &);
	TargetGenerator & operator=(TargetGenerator const &);
public:
	TargetGenerator();
	~TargetGenerator();

	void learnTargetType(ATarget* spell);
	void forgetTargetType(std::string const & spellName);
	ATarget* createTarget(std::string const & spellName);
};

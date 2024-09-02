// Character.hpp

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"
#include "AMateria.hpp"
#include <string>

class Character : public ICharacter {
private:
	std::string _name;
	AMateria* _inventory[4];

public:
	Character(std::string const & name);
	Character(Character const & other);
	virtual ~Character();

	Character & operator=(Character const & other);

	std::string const & getName() const;
	void equip(AMateria* m);
	void unequip(int idx);
	void use(int idx, ICharacter& target);
};

#endif

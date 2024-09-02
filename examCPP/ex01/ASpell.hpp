// ASpell.hpp

#ifndef ASPELL_HPP
#define ASPELL_HPP

#include <string>
#include "ATarget.hpp" // Inclusion pour la méthode launch()

class ATarget; // Forward declaration pour éviter les dépendances circulaires

class ASpell {
protected:
	std::string name;
	std::string effects;

public:
	ASpell(std::string const & name, std::string const & effects);
	virtual ~ASpell();

	std::string const & getName() const;
	std::string const & getEffects() const;

	virtual ASpell* clone() const = 0;

	void launch(ATarget const & target) const;
};

#endif

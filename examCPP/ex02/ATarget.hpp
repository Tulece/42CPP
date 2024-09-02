// ATarget.hpp

#ifndef ATARGET_HPP
#define ATARGET_HPP

#include <string>
#include "ASpell.hpp" // Inclusion pour la méthode getHitBySpell()

class ASpell; // Forward declaration

class ATarget {
protected:
    std::string type;

public:
    ATarget(std::string const & type);
    virtual ~ATarget();

    std::string const & getType() const;

    virtual ATarget* clone() const = 0;

    void getHitBySpell(ASpell const & spell) const;
};

#endif

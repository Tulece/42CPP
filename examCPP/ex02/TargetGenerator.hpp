// TargetGenerator.hpp

#ifndef TARGETGENERATOR_HPP
#define TARGETGENERATOR_HPP

#include <string>
#include <map>
#include "ATarget.hpp"

class TargetGenerator {
private:
    std::map<std::string, ATarget*> targets;

    TargetGenerator(TargetGenerator const &);
    TargetGenerator & operator=(TargetGenerator const &);

public:
    TargetGenerator();
    ~TargetGenerator();

    void learnTargetType(ATarget* target);
    void forgetTargetType(std::string const & targetType);
    ATarget* createTarget(std::string const & targetType);
};

#endif

#ifndef _ENIGMA_REFLECTOR
#define _ENIGMA_REFLECTOR

#include <string>

#include "constants.h"

class Reflector
{
private:
    std::string wiring;

public:
    Reflector(std::string wiring);
    char transform(char in);
};

#endif
#ifndef _ENIGMA_MACHINE
#define _ENIGMA_MACHINE

#include <list>
#include <string>
#include "reflector.h"
#include "rotor.h"

class Enigma
{
private:
    Reflector *reflector;
    std::list<Rotor *> rotors;
    char encrypt(const char &c);

public:
    Enigma(Reflector *reflector, std::list<Rotor *> rotors);
    std::string encrypt(std::string plaintext);
};

#endif
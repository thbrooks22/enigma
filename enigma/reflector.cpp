#include <algorithm>
#include <iterator>
#include <string>

#include "constants.h"
#include "reflector.h"

class Reflector
{
private:
    std::string wiring;

public:
    Reflector(std::string wiring)
    {
        this->wiring = wiring;
    };

    char transform(char in)
    {
        return this->wiring[ALPH.find(in)];
    };
};
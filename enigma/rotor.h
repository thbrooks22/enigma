#ifndef _ENIGMA_ROTOR
#define _ENIGMA_ROTOR

#include <string>

#include "constants.h"

struct RotorCipherState
{
    char in;
    bool must_turn;
};

class Rotor
{
private:
    std::string wiring;
    char start, notch;
    uint8_t position;
    void turn();

public:
    Rotor(std::string wiring, char start, char notch);
    void step_left(RotorCipherState *state);
    char step_right(char in);
};

#endif
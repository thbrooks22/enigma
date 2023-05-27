#include <string>

#include "constants.h"
#include "rotor.h"

class Rotor
{
private:
    std::string wiring;
    char start, notch;
    uint8_t position;

    void turn()
    {
        position = (position + 1) % ALPH_SIZE;
    }

public:
    Rotor(std::string wiring, char start, char notch)
    {
        this->wiring = wiring;
        this->start = start, this->notch = notch;
        this->position = ALPH.find(start);
    };

    void step_left(RotorCipherState *state)
    {
        if (state->must_turn)
        {
            this->turn();
        }

        if (this->wiring[position] == this->notch)
        {
            this->turn();
            state->must_turn = true;
        }
        else
        {
            state->must_turn = false;
        }

        uint8_t mapped_index = (position + ALPH.find(state->in)) % ALPH_SIZE;
        state->in = this->wiring[mapped_index];
    };

    char step_right(char in)
    {
        return ALPH[this->wiring.find(in)];
    };
};
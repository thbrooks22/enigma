#include <list>
#include <string>

#include "enigma.h"
#include "reflector.h"
#include "rotor.h"

class Enigma
{
private:
    Reflector *reflector;
    std::list<Rotor *> rotors;

    char encrypt(const char &c)
    {
        RotorCipherState *state;
        state->in = c;
        state->must_turn = true;

        std::list<Rotor *>::reverse_iterator rev;
        for (rev = this->rotors.rbegin(); rev != this->rotors.rend(); rev++)
        {
            (*rev)->step_left(state);
        }

        char out = this->reflector->transform(state->in);

        std::list<Rotor *>::iterator it;
        for (it = this->rotors.begin(); it != this->rotors.end(); it++)
        {
            out = (*it)->step_right(out);
        }

        return out;
    };

public:
    Enigma(Reflector *reflector, std::list<Rotor *> rotors)
    {
        this->reflector = reflector;
        this->rotors = rotors;
    };

    std::string encrypt(std::string plaintext)
    {
        std::string ciphertext = "";
        for (const char &c : plaintext)
        {
            ciphertext += this->encrypt(c);
        }

        return ciphertext;
    };
};
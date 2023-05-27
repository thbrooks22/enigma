#include <iostream>
#include <list>
#include <string>

#include "enigma/enigma.h"
#include "enigma/reflector.h"
#include "enigma/rotor.h"

Rotor *ROTOR_I = new Rotor("EKMFLGDQVZNTOWYHXUSPAIBRCJ", 'F', 'B');
Rotor *ROTOR_II = new Rotor("AJDKSIRUXBLHWTMCQGZNPYFVOE", 'O', 'A');
Rotor *ROTOR_III = new Rotor("BDFHJLCPRTXVZNYEIWGAKMUSQO", 'O', 'R');
std::list<Rotor *> ROTORS{ROTOR_I, ROTOR_II, ROTOR_III};

Reflector *REFLECTOR = new Reflector("YRUHQSLDPXNGOKMIEBFZCWVJAT");

int main()
{
    Enigma *enigma = new Enigma(REFLECTOR, ROTORS);
    std::string user_input;

    while (true)
    {
        std::cout << "\nEnter text to encrypt: ";
        std::cin >> user_input;
        std::cout << "\nEncrypted text is: " << enigma->encrypt(user_input);
    }
}
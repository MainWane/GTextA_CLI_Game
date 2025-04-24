// GTextA Utility.h indeholder funktioner til at håndtere brugerinput.

#pragma once
#include <iostream> // For std::cout
#include <string> // For std::string
#include <algorithm> // For tidsforsinkelse
#include <cctype> // For at konvertere til lowercase

// Function to get a valid name from the user
inline std::string getValidName() {
    std::string navn;

    while (true) {
        std::getline(std::cin, navn); // Input name

        // Check if the name is only whitespace
        bool kunMellemrum = std::all_of(navn.begin(), navn.end(), [](unsigned char c) { return std::isspace(c); });

        if (navn.empty() || kunMellemrum) {
            skrivLangsomt ("Navnet kan ikke være tomt eller kun mellemrum. Det' ik' Gangsta. Prøv igen OG: ");
        } else if (navn.length() > 20) {
            std::cout << "Navnet er for langt. Det ik' Gangsta nok. Indtast et kortere navn, max 20 tegn, OG: ";
        } else {
            break;
        }
    }

    return navn;
}
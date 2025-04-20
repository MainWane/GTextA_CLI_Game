// GTextA Utility.h

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
            std::cout << "Navnet kan ikke være tomt eller kun mellemrum. Det' ik' Gangsta. Prøv igen: ";
        } else if (navn.length() > 50) {
            std::cout << "Navnet er for langt. Slet ikke Gangsta. Indtast et kortere navn (maks 50 tegn): ";
        } else {
            break;
        }
    }

    return navn;
}
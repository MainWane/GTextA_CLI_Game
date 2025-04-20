#pragma once
#include <iostream> // For at bruge std::cout
#include <string> // For at bruge std::string
#include <chrono> // For tidsforsinkelse
#include <thread> // For std::this_thread::sleep_for
#include <algorithm>    // For std::transform
#include <cctype> // For at konvertere til lowercase


// ANSI-escape codes for farver
#define RESET "\033[0m"       // Nulstil farver
#define RED "\033[31m"        // Rød tekst
#define GREEN "\033[32m"      // Grøn tekst
#define YELLOW "\033[33m"     // Gul tekst
#define BOLD "\033[1m"        // Fed tekst

using namespace std; 

// Skrivemaskine effekt funktion
inline void skrivLangsomt(string tekst, int hastighed = 40) {
    for (char c : tekst) {
        std::cout << c << std::flush;
        this_thread::sleep_for(chrono::milliseconds(hastighed));
    }
    std::cout << "\n";
}

// Dramatisk skrivemaskine effekt funktion
inline void skrivLangsommere(string tekst, int hastighed = 90) {
    for (char c : tekst) {
        std::cout << c << flush;
        this_thread::sleep_for(chrono::milliseconds(hastighed));
    }
    std::cout << "\n";
}

// Wasted funktion med effekt
inline void WASTED() {
    std::cout << "\n";
    skrivLangsommere(std::string(BOLD) + RED + "WASTED" + RESET);
    std::cout << "\n";
    skrivLangsommere(std::string(BOLD) + YELLOW + "Game Over" + RESET);
}

// Busted funktion med effekt
inline void BUSTED() {
    std::cout << "\n";
    skrivLangsommere(std::string(BOLD) + RED + "BUSTED" + RESET);
    std::cout << "\n";
    skrivLangsommere(std::string(BOLD) + YELLOW + "Game Over" + RESET);
}


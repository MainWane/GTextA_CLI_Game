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
void skrivLangsomt(string tekst, int hastighed = 50) {
    for (char c : tekst) {
        std::cout << c << std::flush;
        this_thread::sleep_for(chrono::milliseconds(hastighed));
    }
    std::cout << std::endl;
}

// Dramatisk skrivemaskine effekt funktion
void skrivLangsommere(string tekst, int hastighed = 100) {
    for (char c : tekst) {
        std::cout << c << flush;
        this_thread::sleep_for(chrono::milliseconds(hastighed));
    }
    std::cout << endl;
}

// Wasted funktion med effekt
void WASTED() {
    std::cout << endl;
    skrivLangsommere(std::string(BOLD) + RED + "WASTED" + RESET);
    std::cout << endl;
    skrivLangsommere(std::string(BOLD) + YELLOW + "Game Over" + RESET);
}

// Busted funktion med effekt
void BUSTED() {
    std::cout << endl;
    skrivLangsommere(std::string(BOLD) + RED + "BUSTED" + RESET);
    std::cout << endl;
    skrivLangsommere(std::string(BOLD) + YELLOW + "Game Over" + RESET);
}


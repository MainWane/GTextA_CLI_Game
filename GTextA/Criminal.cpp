// Criminal Class Header File
#include <string>
#include <iostream> // For std::cout
#include "../include/Criminal.h"
#include "../include/Style.h" // Include the Style header file

// Member functions
    void Criminal::takeDamage(int damage) { // Function to take damage
        health -= damage;
        if (health < 0) health = 0; // Ensure health doesn't go below 0
    }
    void Criminal::heal(int amount) { // Function to heal
        health += amount;
        if (health > maxHealth) health = maxHealth; // Ensure health doesn't exceed maxHealth
    }
    void Criminal::arm() { bevæbnet = true; } // Function to arm the criminal
    void Criminal::disarm() { bevæbnet = false; } // Function to disarm the criminal
    
    // Nyttefunktioner
    void Criminal::printStats() const { // Viser stats 
        std::cout << name <<  " har " << GREEN << health << " Health " << RESET << "og " << RED << power << " Power." << RESET << std::endl;
    }
    bool Criminal::erDød() const { 
        return health <= 0; } // Function to check if the criminal is dead

   
    void Criminal::ugyldigtValg() {  // Ugyldigt valg funktion
    std::cout << "Ugyldigt valg. Prøv igen. C'mon, ægte gangstere kan godt stave" << endl;
}

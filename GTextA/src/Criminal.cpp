// Criminal (Player) Class cpp file

#include <string>
#include <iostream> // For std::cout
#include "include/Criminal.h"
#include "include/Style.h" // Include the Style header file


// Member functions
    // Health og Damage funktioner
    void Criminal::takeDamage(int damage) {
        health -= damage;
        if (health < 0) health = 0;
    
        printStats();
    
        if (health <= 0) {
            WASTED();
            gameOver = true; // Set game over if health is 0 or less
        }
    }
    void Criminal::heal(int amount) { // Function to heal
        health += amount;
        if (health > maxHealth) health = maxHealth; // Ensure health doesn't exceed maxHealth
    }
    // Bevæbnet funktion
    void Criminal::arm() { bevæbnet = true; } // Function to arm the criminal
    void Criminal::disarm() { bevæbnet = false; } // Function to disarm the criminal
    
    // Nyttefunktioner
    void Criminal::printStats() const { // Viser stats 
        skrivLangsomt(name +  " har " + GREEN + std::to_string(health) + " Health " + RESET + "og " + RED + std::to_string(power) + " Power." + RESET);
    }
    bool Criminal::erDød() const { 
        return health <= 0; } // Function to check if the criminal is dead

    void Criminal::ugyldigtValg() {  // Ugyldigt valg funktion
    std::cout << "Ugyldigt valg. Prøv igen. C'mon, ægte gangstere kan godt stave" << endl;
    }

    // Inventory funktioner
    void Criminal::addItem(const std::string& item) { // Add item to inventory
        inventory.push_back(item); 
    }
    void Criminal::removeItem(const std::string& item) { // Remove item from inventory
        auto it = std::find(inventory.begin(), inventory.end(), item);
        if (it != inventory.end()) {
            inventory.erase(it); // Remove the item from the inventory
        }
    }
    // Check if item is in inventory
    bool Criminal::hasItem(const std::string& item) const { // Check if item is in inventory
        return std::find(inventory.begin(), inventory.end(), item) != inventory.end(); // Return true if item is found
    }
    void Criminal::printInventory() const { // Print inventory
        std::cout << "------ Inventory ------ "; // Print inventory header
        std::cout << std::endl; // New line
        if (inventory.empty()) {
            std::cout << "Ingen ting i lommerne" << std::endl; // If inventory is empty
        } else {
            for (const auto& item : inventory) {
                std::cout << "1 " << item << ", "; // Print each item in the inventory
            }
            std::cout << std::endl;
        }
    }

    // Wanted level funktioner
    void Criminal::increaseWantedLevel(int amount) {
        wantedLevel += amount;
        if (wantedLevel > 5) wantedLevel = 5;
    }
    
    void Criminal::decreaseWantedLevel(int amount) {
        wantedLevel -= amount;
        if (wantedLevel < 0) wantedLevel = 0;
    }
    
    int Criminal::getWantedLevel() const {
        return wantedLevel;
    }
    
    void Criminal::printWantedLevel() const {
        std::cout << "WANTED LEVEL: ";
        for (int i = 0; i < wantedLevel; ++i) {
            std::cout << "★";
        }
        if (wantedLevel == 0) {
            std::cout << "Ingen mistanke endnu...";
        }
        std::cout << std::endl;
    }
    
    void wantedLevel(int level) { // Set wanted level
        if (level < 0) level = 0; // Ensure level is not negative
        if (level > 5) level = 5; // Ensure level does not exceed 5
    }

    // Cash funktioner
    void Criminal::addCash(int amount) { // Add cash
        cash += amount;
    }
    void Criminal::removeCash(int amount) { // Remove cash
        cash -= amount;
        if (cash < 0) cash = 0; // Ensure cash doesn't go below 0
    }
    int Criminal::getCash() const { // Get cash
        return cash;
    }
    void Criminal::printCash() const { // Print cash
        skrivLangsomt("Du har $" + std::to_string(cash) + " på dig."); // Print cash amount
    }

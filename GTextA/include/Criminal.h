// Criminal Class Header File
#pragma once
#include <string>
#include <vector>

class Criminal {         // Class definition for Criminal
private:                 // Private member variables
    std::string name;    // Name of the criminal
    int health;          // Current health of the criminal
    int maxHealth = 100; // Maximum health of the criminal
    int power;           // Power of the criminal
    int maxPower = 200;  // Maximum power of the criminal
    bool bevæbnet;       // Indicates if the criminal is armed
    int wantedLevel = 0; // Wanted level of the criminal (0-5)
    std::vector<std::string> inventory; // Inventory of the criminal

public:
    // Constructor
    Criminal(std::string name, int health, int power, bool bevæbnet)
        : name(name), health(health), power(power), bevæbnet(bevæbnet) {}

    // Getters
    std::string getName() const { return name; }
    int getHealth() const { return health; }
    int getMaxHealth() const { return maxHealth; }
    int getPower() const { return power; }
    int getMaxPower() const { return maxPower; }
    bool isArmed() const { return bevæbnet; }
    int getWantedLevel() const; // Get wanted level

    // Setters
    void setHealth(int newHealth) { health = newHealth; }   // Set health
    void setPower(int newPower) { power = newPower; } // Set power
    void setwantedLevel(int level) { wantedLevel = level; } // Set wanted level

    // Member functions
    void takeDamage(int damage);
    void heal(int amount);
    void arm();
    void disarm();
    void printStats() const;
    bool erDød() const;
    void ugyldigtValg();
    void increaseWantedLevel(int amount); // Increase wanted level
    void decreaseWantedLevel(int amount); // Decrease wanted level

    // Inventory functions
    void addItem(const std::string& item);// Add item to inventory
    void removeItem(const std::string& item); // Remove item from inventory
    bool hasItem(const std::string& item) const; // Check if item is in inventory
    void printInventory() const; // Print inventory

    // Wanted level functions
    void printWantedLevel() const;
};

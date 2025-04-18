// Criminal Class Header File
#pragma once
#include <string>

class Criminal {         // Class definition for Criminal
private:                 // Private member variables
    std::string name;    // Name of the criminal
    int health;          // Current health of the criminal
    int maxHealth = 100; // Maximum health of the criminal
    int power;           // Power of the criminal
    int maxPower = 200;  // Maximum power of the criminal
    bool bevæbnet;       // Indicates if the criminal is armed

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

    // Setters
    void setHealth(int newHealth) { health = newHealth; }   // Set health
    void setPower(int newPower) { power = newPower; } // Set power

    void takeDamage(int damage);
    void heal(int amount);
    void arm();
    void disarm();
    void printStats() const;
    bool erDød() const;
    void ugyldigtValg();
         
};
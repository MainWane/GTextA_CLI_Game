#include "Style.h"
#include "Utility.h" // Include the Utility header file for skrivLangsomt
#include "StorySetup.h"


// MakeNode-funktion til at oprette StoryNode-objekter¨
// Med default værdier for action og choices som ikke findes i StoryNode.h
StoryNode* makeNode(const std::string& description,
    std::function<void(Criminal&)> action = nullptr,
    std::unordered_map<std::string, StoryNode*> choices = {}) 
{
    //
    StoryNode* node = new StoryNode(description, action);
    node->choices = choices;
    return node;
}

// Funktion til at oprette spilleren (Criminal objektet)
Criminal createPlayer() {
    // Spilleren vælger navn
    skrivLangsommere("Hvem er du? (indtast navn)");
    std::string navn = getValidName(); // Kald funktionen for at få et gyldigt navn

    // Opretter en Criminal objekt med spillerens navn, 100 health, 10 power, ikke bevæbnet, 0 wanted level og 5 cash
    Criminal Criminalprotag(navn, 100, 10, false, 0, 5);

    // Tilføjer genstande til spillerens inventar
    Criminalprotag.addItem("Shotgun");
    Criminalprotag.addItem("Granat");
    Criminalprotag.addItem("BananaBomb Snackbar");

    std::cout << "\n";

    return Criminalprotag; // Returner Criminal objektet
}


   
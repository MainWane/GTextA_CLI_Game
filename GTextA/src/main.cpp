/* GTextA ver. 0.62
af Ulrik Wandall - 20/04/2025
*/

#include <iostream> // For at bruge std::cout
#include <string> // For at bruge std::string
#include "include/Criminal.h" // Include the Criminal class header file
#include "include/Style.h" // Include the Style header file
#include "include/StoryGraph.h" // Include the StoryGraph header file
#include "include/StorySetup.h" // Include the StorySetup header file
#include "include/Utility.h" // Include the Utility header file



// Main funktion
// Her starter programmet
int main() {
    

    // Titel
    std::cout << "\n"; // Ny linje
    std::cout << "\n";
    skrivLangsommere(std::string(BOLD) + YELLOW + "G" + RESET);
    skrivLangsomt(std::string(BOLD) + YELLOW + "Text" + RESET);
    skrivLangsommere(std::string(BOLD) + YELLOW + "A" + RESET);
    std::cout << "\n";
    std::cout << "\n";

    // Introduktion
    skrivLangsomt("Velkommen til Vice City, Florida. Stedet hvor ingen");
    skrivLangsommere("(og vi mener INGEN)");
    skrivLangsomt("indskydelse er for vanvittig til at handle på.");
    std::cout << "\n";

    // Opret spilleren
    Criminal Criminalprotag = createPlayer(); // Call createPlayer() and assign the returned object to 'Criminalprotag'

     // Opret og spil historien
     StoryNode* startNode = createStory(); // Byg historien ved hjælp af StorySetup
     StoryGraph story(startNode); // Initialiser StoryGraph med startnoden
     story.play(Criminalprotag); // Spil historien med spilleren
 
     return 0;
 }

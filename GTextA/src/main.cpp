/* GTextA ver. 0.62
af Ulrik Wandall - 20/04/2025
*/

#include <iostream> // For at bruge std::cout
#include <string> // For at bruge std::string
#include "Criminal.h" // Include the Criminal class header file
#include "Style.h" // Include the Style header file
#include "StoryGraph.h" // Include the StoryGraph header file
#include "StorySetup.h" // Include the StorySetup header file
#include "Utility.h" // Include the Utility header file



// Main funktion
// Her starter programmet
int main() {
    

    // Titel
    visTitel();


    // Introduktion
    skrivLangsomt("Velkommen til Vice City, Florida. Stedet hvor ingen");
    skrivLangsommere("(og vi mener INGEN)");
    skrivLangsomt("indskydelse er for vanvittig til at handle på.");
    std::cout << "\n";

    // Opret spilleren
    Criminal Criminalprotag = createPlayer(); // Call createPlayer() and assign the returned object to 'Criminalprotag'

     // Opret og spil historien
     StoryNode* startNode = createStory(Criminalprotag); // Byg historien ved hjælp af StorySetup
     StoryGraph story(startNode); // Initialiser StoryGraph med startnoden
     story.play(Criminalprotag); // Spil historien med spilleren
 
     return 0;
 }

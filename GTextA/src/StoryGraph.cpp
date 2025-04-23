// StoryGraph.cpp brug af StoryGraph class uden for klasse defintion
#include "include/StoryGraph.h" // Include the StoryGraph header file
#include <iostream> // For std::cout
#include <algorithm>
#include <cctype> // For std::tolower

// Funktion til at standardisere brugerinput ved at fjerne mellemrum og konvertere til små bogstaver
// Den tager en std::string som input og returnerer den normaliserede version.
std::string normalizeInput(const std::string& input) {
    std::string result = input;
    result.erase(remove_if(result.begin(), result.end(), ::isspace), result.end()); // fjern mellemrum
    std::transform(result.begin(), result.end(), result.begin(), ::tolower); // små bogstaver
    return result;
}
   // Viser og håndterer brugerens valg i historien
   // Den normaliserer brugerens input og sammenligner det med de tilgængelige valg i den aktuelle node.
   // Hvis valget er gyldigt, opdaterer den den aktuelle node; ellers beder den brugeren om at prøve igen.
   void StoryGraph::play(Criminal& player) {
    while (currentNode) {
        currentNode->display(player);

        std::string choice;
        std::getline(std::cin, choice);
        std::string normalized = normalizeInput(choice);

        bool validChoice = false;
        for (const auto& option : currentNode->choices) {
            std::string keyNormalized = normalizeInput(option.first);
            if (normalized == keyNormalized) {
                currentNode = option.second;
                validChoice = true;
                break;
            }
        }

        if (!validChoice) {
            std::cout << "Det er ikke muligt - eller gangsta! Prøv igen." << std::endl;
        }
    }

    std::cout << "Holy Moly, du overlevede!?." << std::endl;
    skrivLangsomt("Tak for at spille GTextA. Vi ses næste gang, i Liberty City!");
}

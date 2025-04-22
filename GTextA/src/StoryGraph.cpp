// StoryGraph.cpp brug af StoryGraph class uden for klasse defintion
#include "include/StoryGraph.h" // Include the StoryGraph header file
#include <iostream> // For std::cout


   // Display the current scene and handle user input
   void StoryGraph::play(Criminal& player) { // Function to play the story with the player
    while (currentNode) { // While there are still nodes to explore 
        currentNode->display(player); // Display the current node and choices

        std::string choice;
        std::cout << "Hvad vælger du? ";
        std::getline(std::cin, choice);

        if (currentNode->choices.find(choice) != currentNode->choices.end()) { // Check if the choice is valid
            currentNode = currentNode->choices[choice]; // Move to the next node based on the choice
        } else {
            std::cout << "Det er ikke muligt - eller gangsta! Prøv igen." << std::endl; // Invalid choice message
        }
    }

    std::cout << "Holy Moly, du overlevede!?." << std::endl; // End of story message
    skrivLangsomt("Tak for at spille GTextA. Vi ses næste gang, i Liberty City!");
}
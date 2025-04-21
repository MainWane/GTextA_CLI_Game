#include <iostream>
#include <string>
#include "StoryNode.h" // Include the StoryNode header file

class StoryGraph {
    private:
        StoryNode* startNode; // Starting point of the story
        StoryNode* currentNode; // Current position in the story
    
    public:
        StoryGraph(StoryNode* start) : startNode(start), currentNode(start) {}
    
        // Restart the story
        void restart() {
            currentNode = startNode;
        }
    
        // Display the current scene and handle user input
        void StoryGraph::play(Criminal& player) {
            while (currentNode) {
                currentNode->display(player);
        
                std::string choice;
                std::cout << "Hvad vælger du? ";
                std::getline(std::cin, choice);
        
                if (currentNode->choices.find(choice) != currentNode->choices.end()) {
                    currentNode = currentNode->choices[choice];
                } else {
                    std::cout << "Det er ikke muligt - eller gangsta. Prøv igen." << std::endl;
                }
            }
        
            std::cout << "Holy Moly, du overlevede!?." << std::endl;
        }
        };
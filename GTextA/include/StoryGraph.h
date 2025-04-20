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
                std::cout << "Enter your choice: ";
                std::getline(std::cin, choice);
        
                if (currentNode->choices.find(choice) != currentNode->choices.end()) {
                    currentNode = currentNode->choices[choice];
                } else {
                    std::cout << "Invalid choice. Try again." << std::endl;
                }
            }
        
            std::cout << "The story has ended." << std::endl;
        }
        };
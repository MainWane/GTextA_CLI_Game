#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <functional> // For std::function
#include "Criminal.h" // Include the Criminal class header file

class StoryNode {
public:
    std::string description; // Description of the scene
    std::unordered_map<std::string, StoryNode*> choices; // Choices leading to other nodes
    std::function<void(Criminal&)> action; // Action to perform at this node

    StoryNode(const std::string& desc, std::function<void(Criminal&)> act = nullptr)
        : description(desc), action(act) {}

    // Add a choice to this node
    void addChoice(const std::string& choiceText, StoryNode* nextNode) {
        choices[choiceText] = nextNode;
    }

    // Display the current scene and choices
    void display(Criminal& player) const {
        std::cout << description << std::endl;
        if (action) {
            action(player); // Perform the action
        }
        std::cout << "Choices:" << std::endl;
        for (const auto& choice : choices) {
            std::cout << "- " << choice.first << std::endl;
        }
    }
};
/* StoryNode.h forvalter StoryNode-klassen, der repræsenterer en node i historien. Den indeholder beskrivelser, valg og handlinger, der skal udføres ved hver node. 
Den bruger også Criminal-objektet til at interagere med spillerens tilstand.
*/

#pragma once
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <functional> // For std::function
#include "Criminal.h" // Include the Criminal class header file
#include "Style.h"    // Include the Style header file for skrivLangsomt

class StoryNode {
public:
    std::string description; // Description of the scene
    std::unordered_map<std::string, StoryNode*> choices; // Choices leading to other nodes
    std::function<void(Criminal&)> action; // Action to perform at this node

    StoryNode(const std::string& desc, std::function<void(Criminal&)> act = nullptr)
        : description(desc), action(act) {}

    // New constructor to support initializer list for choices
    StoryNode(const std::string& desc, std::initializer_list<std::pair<std::string, StoryNode*>> initChoices)
        : description(desc), action(nullptr) {
        for (const auto& choice : initChoices) {
            choices[choice.first] = choice.second;
        }
    }
    // Add a choice to this node
    void addChoice(const std::string& choiceText, StoryNode* nextNode) {
        choices[choiceText] = nextNode;
    }

    // Display the current scene and choices
    void display(Criminal& player) const {
        skrivLangsomt(description); // Use skrivLangsomt for the description
        if (action) {
            action(player); // Perform the action
        }
    }
};
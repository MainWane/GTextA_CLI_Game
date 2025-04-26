// StorySetup.h - Headerfil til at oprette historien og spilleren

#pragma once
#include "StoryNode.h"
#include "Criminal.h" // Include the Criminal class header file

// Function to build the story and return the starting node
StoryNode* createStory(Criminal& player); 

// Function to create the player (Criminal object)
Criminal createPlayer();

// Funktion til makeNode som sparer plads og gør det lettere at oprette noder
// Den tager en beskrivelse, en handling og et kort med valg som input og returnerer en pointer til StoryNode
StoryNode* makeNode(const std::string& description,
    std::function<void(Criminal&)> action,
    std::unordered_map<std::string, StoryNode*> choices);

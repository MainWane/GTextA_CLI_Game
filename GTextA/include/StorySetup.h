#pragma once
#include "StoryNode.h"
#include "Criminal.h" // Include the Criminal class header file

// Function to build the story and return the starting node
StoryNode* createStory();

// Function to create the player (Criminal object)
Criminal createPlayer();
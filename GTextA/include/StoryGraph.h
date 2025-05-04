#pragma once
#include <iostream>
#include <string>
#include "StoryNode.h" // Include the StoryNode header file



class StoryGraph { // StoryGraph klasse til at håndtere historien
    private:
        StoryNode* startNode; // Starting point of the story
        StoryNode* currentNode; // Current position in the story
    
    public:
        StoryGraph(StoryNode* start) : startNode(start), currentNode(start) {} // Konstruktor til at initialisere startNode og currentNode

        void play(Criminal& player); // Metode til sætte spillerens position i historien
    
        // Restart the story
        void restart() {
            currentNode = startNode;
        }
    
     
    };
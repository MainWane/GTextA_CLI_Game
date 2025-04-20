#include "../include/StorySetup.h" // Adjust the path to match the actual location of StorySetup.h

StoryNode* createStory() {
    // Create story nodes
    StoryNode* intro = new StoryNode("Velkommen til Vice City, Florida. Stedet hvor ingen (og vi mener INGEN) indskydelse er for vanvittig til at handle på. Til alt held triller en funklende rød Infernus op til trafiklyset lige foran. En nar med klistret svenskergarn sidder bag ruden, foran rettet.");
    StoryNode* action = new StoryNode("Hvad skal der gøres?");

    // Return the starting node
    return intro;
}
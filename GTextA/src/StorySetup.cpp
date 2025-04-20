#include "../include/StorySetup.h" // Adjust the path to match the actual location of StorySetup.h

StoryNode* createStory() {
    // Create story nodes
    StoryNode* intro = new StoryNode("Velkommen til Vice City, Florida. Stedet hvor ingen (og vi mener INGEN) indskydelse er for vanvittig til at handle på.");
    StoryNode* hotel = new StoryNode("Du træder ud af dit rottebefængte hotel og kaster blikket ned på din rustne Mañana. Dybt suk, dækket er punkteret igen.");
    StoryNode* infernus = new StoryNode("Til alt held triller en funklende rød Infernus op til trafiklyset lige foran. En nar med klistret svenskergarn sidder bag ruden, foran rettet.");
    StoryNode* action = new StoryNode("Hvad skal der gøres?");

    // Add choices
    action->addChoice("flå", new StoryNode("Du flår døren op, og svenskergarnet går i panik."));
    action->addChoice("granat", new StoryNode("Du kaster en granat mod bilen. Den eksploderer."));
    action->addChoice("shotgun", new StoryNode("Du trækker din shotgun og peger mod svenskergarnet."));

    // Link nodes
    intro->addChoice("fortsæt", hotel);
    hotel->addChoice("fortsæt", infernus);
    infernus->addChoice("fortsæt", action);

    // Return the starting node
    return intro;
}
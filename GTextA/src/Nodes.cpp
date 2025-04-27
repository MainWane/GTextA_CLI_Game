#include "StoryNode.h"
#include "StorySetup.h" // hvis makeNode ligger her
#include "Utility.h"    // hvis du skal bruge skrivLangsomt osv.
#include "Nodes.h"    // hvis du skal bruge Nodes.h

StoryNode* Svenskergarn0 = makeNode(
    "Beskrivelse...",
    [](Criminal& player) { player.takeDamage(30); },
    {
        { "valg1", nullptr },
        { "valg2", nullptr }
    }
);

StoryNode* skydFalseSG = makeNode( // Valg af skyd uden trukket våben for Svenskergarn (SG) StoryLine
    "Du løfter armen og bevæger instintivt din triggerfinger. \n"
    "Du har dog intet våben trukket. Woopsie... \n"
    "Manden med svenskergarnet spilder ingen tid på at pløkke dig ned. \n",
    [](Criminal& player){
    WASTED(); }
);

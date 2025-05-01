#include "StoryNode.h"
#include "StorySetup.h" // hvis makeNode ligger her
#include "Utility.h"    // hvis du skal bruge skrivLangsomt osv.
#include "Nodes.h"    // hvis du skal bruge Nodes.h

// Her spilles intro teksten med spillerens navn
StoryNode* createStory(Criminal& player) {
    player.printInventory(); // Spillerens første møde med Inventory
    std::cout << endl;
    
    std::string introText = player.getName() + 
    " træder ud af sit rottebefængte hotel. Du har kun det allermest nødvendige på dig. Du kaster blikket ned på din rustne Mañana..... "
    "Dybt suk, dækket er punkteret igen.\n" 
    "Det er sgu surt at være en broke bitch.\n" 
    "Til alt held triller en funklende rød Infernus op til trafiklyset lige foran. "
    "En nar med klistret svenskergarn sidder bag ruden, foran rettet.\n";
                introText += player.getName() + " tænker det er tid til at opgradere bil...\n\n";
                 "Hvad skal der gøres? \n";
 
    // Define all nodes referenced in choices

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
    WASTED(); },
    {}
);

StoryNode* Svenskergarn0 = makeNode(
    "Du tager fat i døren. Svenskergarnet går med det samme i panik og jokker sømmet i bund. \n"
    "Du er dog fast besluttet på at stjæle bilen og holder fast med alle kræfter. \n"
    "Altså slæber bilen dig flagrende med. \n" 
    "Den fine røde bil bliver mindre funklende, men endnu rødere, mens den pløjer et par stakkels turister ned. \n"
    "Du bliver trukket næsten hundrede meter før " + player.getName() + " bliver sendt flyvende op på fortovet.\n"
    "Ouch!\n",
    [](Criminal& player) { player.takeDamage(30); },
    {
        { "skyd", skydFalseSG },
        { "hop i dækning", Svenskergarn1 },
        { "undskyld", nullptr }
    }
);

StoryNode* Shotgun0 = new StoryNode(
    "Du trækker din shotgun fra indersiden af din hawaiiskjorte. Du mærker dens tyngde i hænderne og smiler ondskabsfuldt.", [](Criminal& player) {
    player.arm();
    player.setPower(80);
    
});
StoryNode* Grenade0 = new StoryNode(
    "Du kaster en granat mod bilen. Den rammer ruden på bilen med et godt dunk. Granaten eksploderer. Både bilen og " + player.getName() + " bliver sprunget i luften.", [](Criminal& player) {
    WASTED();
});
StoryNode* BananaBomb0 = new StoryNode(
    "Du snacker en bid af din BananaBomb Snackbar og føler dig straks lidt bedre tilpas.\n" 
    "Desværre tiltrækker din BananaBomb uønsket opmærksomhed. Da " + player.getName() + "kigger op igen ser du at Svenskergarnet har rettet en Uzi direkte mod dig. \n"
    "Hans Aviator solbriller blinker i solen. \n"
    "Han griner ubehageligt og kommanderer dig til at give ham resten af din BananaBomb. \n"
    "Hvad gør du nu? \n"
    "- Giv ham din BananaBomb - tast 'giv'\n"
    "- Kast din BananaBomb - tast 'kast'\n"
    "- Snack resten af din BananaBomb - tast 'snack'\n"
    "- Træk din Shotgun - tast 'shotgun'\n"
    "- Stik af - tast 'løb'\n"
    , [](Criminal& player) {
    
});

StoryNode* choice1 = new StoryNode(introText +
    "- Flå døren på bilen op - tast 'flå'\n"
    "- Træk din Shotgun - tast 'shotgun'\n"
    "- Kast en granat - tast 'granat'\n"
    "- Snack en BananaBomb Snackbar - tast 'snack'\n",
    {
        { "flå", Svenskergarn0 },
        { "shotgun", Shotgun0 },
        { "granat", Grenade0 },
        { "snack", BananaBomb0 }
    });

};



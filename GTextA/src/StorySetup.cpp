#include "../include/StorySetup.h" // Adjust the path to match the actual location of StorySetup.h
#include "../include/Style.h"
#include "../include/Utility.h" // Include the Utility header file for skrivLangsomt


Criminal createPlayer() {
    // Spilleren vælger navn
    skrivLangsommere("Hvem er du? (indtast navn)");
    std::string navn = getValidName(); // Kald funktionen for at få et gyldigt navn

    // Opretter en Criminal objekt med spillerens navn, 100 health, 10 power, ikke bevæbnet, 0 wanted level og 5 cash
    Criminal Criminalprotag(navn, 100, 10, false, 0, 5);

    // Tilføjer genstande til spillerens inventar
    Criminalprotag.addItem("Shotgun");
    Criminalprotag.addItem("Granat");
    Criminalprotag.addItem("BananaBomb Snackbar");

    std::cout << "\n";

    return Criminalprotag; // Returner Criminal objektet
}


StoryNode* createStory(Criminal& player) {
    // Create story nodes
    StoryNode* intro = new StoryNode(player.getName() + " træder ud af sit rottebefængte hotel og kaster blikket ned på sin rustne Mañana. Dybt suk, dækket er punkteret igen.. Til alt held triller en funklende rød Infernus op til trafiklyset lige foran. En nar med klistret svenskergarn sidder bag ruden, foran rettet.");

    // Define all nodes referenced in choices
    StoryNode* Svenskergarnet0 = new StoryNode("Du flår døren op, og svenskergarnet går i panik.", [](Criminal& player) {
        player.takeDamage(30);
        player.printStats();
    });
    StoryNode* Shotgun0 = new StoryNode("Du trækker din shotgun fra indersiden af din hawaiiskjorte. Du mærker dens tyngde i hænderne og smiler ondskabsfuldt.", [](Criminal& player) {
        player.arm();
        player.setPower(80);
        player.printStats();
    });
    StoryNode* Grenade0 = new StoryNode("Du kaster en granat mod bilen. Den eksploderer.", [](Criminal& player) {
        WASTED();
    });
    StoryNode* BananSnackbar0 = new StoryNode("Du snacker en BananaBomb Snackbar og føler dig straks bedre tilpas.", [](Criminal& player) {
        player.heal(20);
        player.printStats();
    });

    // Now create the choice1 node
    StoryNode* choice1 = new StoryNode("Hvad skal der gøres?", {
        { "Flå døren op - tast 'flå'", Svenskergarnet0 },
        { "Træk din Shotgun", Shotgun0 },
        { "Kast en granat", Grenade0 },
        { "Snack en BananaBomb Snackbar", BananSnackbar0 }
    });

    return choice1;

}
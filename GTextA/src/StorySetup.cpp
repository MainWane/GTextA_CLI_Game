#include "StorySetup.h" // 
#include "Style.h"
#include "Utility.h" // Include the Utility header file for skrivLangsomt

// MakeNode-funktion til at oprette StoryNode-objekter¨
// Med default værdier for action og choices som ikke findes i StoryNode.h
StoryNode* makeNode(const std::string& description,
    std::function<void(Criminal&)> action = nullptr,
    std::unordered_map<std::string, StoryNode*> choices = {}) 
{
    //
    StoryNode* node = new StoryNode(description, action);
    node->choices = choices;
    return node;
}

// Funktion til at oprette spilleren (Criminal objektet)
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
        "Du tager fat i døren. Svenskergarnet går med det samme i panik og jokker sømmet i bund. \n"
        "Du er dog fast besluttet på at stjæle bilen og holder fast med alle kræfter. \n"
        "Altså slæber bilen dig flagrende med. \n" 
        "Den fine røde bil bliver mindre funklende, men endnu rødere, mens den pløjer et par stakkels turister ned. \n"
        "Du bliver trukket næsten hundrede meter før " + player.getName() + " bliver sendt flyvende op på fortovet.\n"
        "Ouch!\n",
        [](Criminal& player) { player.takeDamage(30); },
        [](Criminal& player) {player.printStats(); },
        "Du kigger op og ser at Svenskergarnet er steget ud af bilen. Svenskergarnet har en pistol i hånden og peger den mod dig.\n"
        "Shit!\n"
        "Hvad gør du nu?",
        {
            { "skyd", skydFalseSG },
            { "hop i dækning", Svenskergarn1 },
            { "undskyld", nullptr }
        }
    );
    };
   





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

    return choice1;

}
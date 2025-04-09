#include <iostream>
#include <string>

using namespace std;


int health = 100;
int maxHealth = 100;
int power = 10;
string criminalName;    
string valg1;


int main() {

cout << "Velkommen til Florida. Staten hvor ingen indskydelse, er for vanvittig til at føre ud i livet. Hvem er du? (indtast navn) " << endl;
cin >> criminalName;
cout << criminalName << " træder ud af sit rottebefængte hotel og kaster blikket ned på sin rustne Mañana. Dybt suk." << endl;
cout << "Til alt held triller en funklende Infernus op til trafiklyset lige foran. En nar med klistret svenskergarn sidder bag rettet." << endl;
cout << criminalName << " tænker det er tid til at opgradere. Hvad skal der gøres?" << endl;
cout << criminalName << " har " << health << " Health" << " og " << power << " power" << endl;
cout << "Flå døren op - tast 'flå'" << endl;
cout << "Kast en granat ind - tast 'granat'" << endl;
cout << "Træk shotgun - tast 'shotgun'" << endl;
cin >> valg1;

if(valg1 == "flå") {
    cout << criminalName << " tager fat i døren. Svenskergarnet går med det samme i panik og jokker sømmet i bund. Den fine røde bil bliver endnu rødere, da den pløjer et par turister ned." << criminalName << " bliver trukket næsten 100 meter, før " << criminalName << " bliver sendt flyvende op på fortovet." << endl;
    cout << "Du har nu 40% liv tilbage." << endl;
    health = 40;
} else if(valg1 == "granat") {
    cout << "Du kaster en granat mod bilen. Granaten rammer ruden på bilen med et godt dunk. Granaten eksploderer. Både, bilen og " << criminalName << " bliver sprunget i luften." << endl;
    cout << "Game over." << endl;
    return 0;
} else if(valg1 == "shotgun") {
    cout << "Du trækker din shotgun. Du mærker dens tyngde i hænderne." << endl;
    cout << "Du har nu 100% liv tilbage." << endl;
    cout << "Du har nu 80 power." << endl;
    health = 100;
    power = 80;
} else {
    cout << "Ugyldigt valg. Prøv igen." << endl;
    return 0;

}
}
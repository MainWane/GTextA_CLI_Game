GTextA is a small, text-based C++ CLI game.
It runs entirely in the terminal and can be built using G++.
UTF-8 encoding is recommended for correct display of Danish characters.

All in danish!

# GTextA CLI Game

Et tekstbaseret konsolspil skrevet i **C++**, udviklet som del af et 2024-projekt af *Ulrik Wandall*.  
Spillet kører i terminalen og er designet som et simpelt, interaktivt tekst-eventyr (CLI-game). 
NB: Grimt sprog og meningsløs vold kan forekomme.

---

## Formål

GTextA er et eksperiment i at bygge et **tekstbaseret spil** i C++, hvor brugerens kommandoer og programlogik håndteres direkte i terminalen.  
Det demonstrerer inputhåndtering, kontrolflow, filstruktur og cross-platform deploy. Spillet er under spordisk udvikling.

---

## Struktur
GTextA_CLI_Game/
- GTextA/ # sourcecode i C++
- .vscode/ # VSCode-opsætning til projektet
- .gitattributes # Git-format- og tekstindstillinger

## Kompilering og kørsel

1. Sørg for, at projektfilerne er gemt som **UTF-8** (for danske bogstaver æ, ø og å).  
2. Brug **GCC** eller **G++** til at kompilere:

   ```bash
   g++ -std=c++17 -o GTextA GTextA/*.cpp
3. Kør spillet

   ```bash
   ./GTextA

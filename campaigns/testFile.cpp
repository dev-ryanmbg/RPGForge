// [BIBLIOTEC]
#include <iostream>
#include <cstdlib>
#include <locale.h>
#include "../system/ui.hpp"
#include "../system/statblock.hpp"
using namespace std;

struct DnDPlayerCharacter {

    Points Hp;

    AbilityScore Str;
    AbilityScore Dex;
    AbilityScore Con;
    AbilityScore Int;
    AbilityScore Wis;
    AbilityScore Cha;

    Container Inventory;

    DnDPlayerCharacter()
        : Hp("Hit Points", 30, 30, 1, 0),
          Str("STR", 1, 20, 1),
          Dex("DEX", 1, 20, 1),
          Con("CON", 1, 20, 1),
          Int("INT", 1, 20, 1),
          Wis("WIS", 1, 20, 1),
          Cha("CHA", 1, 20, 1),
          Inventory("Inventory", 10)
    {}
};


int main (){
    setlocale(LC_ALL, ".UTF-8");
    header("RPG Forge");
    DnDPlayerCharacter Ryan;
    formatMessage("Ryan Strenght Value: {AbilityScore}", Ryan.Str);
    return 0;
}
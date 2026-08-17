// [BIBLIOTECAS]
#include <iostream>
#include <cstdlib>
#include <locale.h>
#include "entidades.hpp"
#include "hud.hpp"
using namespace std;

int main (){
    setlocale(LC_ALL, ".UTF-8");
    header("RPG Forge");
    personagem ryan("Ryan", "Guerreiro",10, 10, 1, 2, 3, 4, 5, 6);
    ryan.info();
    system("pause");
    return 0;
}
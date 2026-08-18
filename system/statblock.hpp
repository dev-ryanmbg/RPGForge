#pragma once
#include <iostream>
#include <locale.h>
#include "ui.hpp"
using namespace std;

struct abilityScore{

    string viewName; // element name (ex: "Strength")
    int minValue; // the maximum value it can reach. Can't be lower than this. 
    int value; // the actual value.
    int maxValue; // the minimum value it can reach. Can't be lower than this.
    
    // When you start an element of type abilityScore, enter the parameters below into the order.
    abilityScore(string _viewName, int _minValue, int _maxValue, int _startingValue){
        viewName = _viewName;
        minValue = _minValue;
        value = _startingValue;
        maxValue = _maxValue;
    }

    // Use this function to set the value for an new one
    void set(int _newValue){
        if(_newValue >= maxValue && _newValue <= minValue){value = _newValue;}
    }
};

struct points{
    string viewName; // element name that will be shown "ex: Hit Points"
    int maxPoints; // actualPoints cannot exceed this value
    int actualPoints; // entity actual points
    int minPoints; 
    /*When actualPoints fall below this value, the function assigned to the string event will run
    ex: for HP could be 1, and then set to trigger "Death"*/
    int runOutEvent; // this value will be matched into switch and trigger some event of the function damage() above.
    /* just an example:
    1 = death()
    2 = breakItem()
    3 to 6 = custom user functions
    */

    // When you start an element of type points, enter the parameters below into the order.
    points(string _viewname, int _maxPoints, int _actualPoints, int _minPoints, int _runOutEvent){
        viewName = _viewname;
        maxPoints = _maxPoints;
        actualPoints = _actualPoints;
        minPoints = _minPoints;
        runOutEvent = _runOutEvent;
    }

    /* Reduce actual points
    If below the minimum points, triggers the event*/
    void damage(int _damage){
        if (actualPoints - _damage >= minPoints){
            actualPoints -= _damage;
        } else {
            actualPoints = minPoints;
            // switch (event){...}
        }
    }

    /* Increase actual points
    If above the maximum points, just keep the maximum value*/
    void heal(int _heal){
        if(actualPoints + _heal < maxPoints){
            actualPoints += _heal;
        } else {
            actualPoints = maxPoints;
        }
    }
};

struct inv{
    // In dev
};
/*

May some parts of code also can be reused so that is why its still here

class personagem{
    public:
    
    string nome, classe;
    points pv, pm;
    ability_score atr;

    string inv[25];
    int itemcount = 0;
    int lim = 0;

    personagem(string n, string c, int _pv, int _pm, int _val1, int _val2, int _val3, int _val4, int _val5, int _val6){
        nome=n;
        classe=c;

        _pv += (atr.mod("CON")*2);
        _pm += (atr.mod("INT")*2);
        lim = 15 + (atr.mod("FOR") * 2);

        pv.set_max(_pv);
        pv.set_atual(_pv);
        pm.set_max(_pm);
        pm.set_atual(_pm);
        
        atr.set_all(_val1,_val2,_val3,_val4,_val5, _val6);
    }

    bool pick(string i){
        if(itemcount < lim){
            bool x;
            int y=0;
            do{
                if(inv[y] == ""){
                    inv[y] = i;
                    x = true; // espaço encontrado
                    itemcount++;
                } else {
                    y++;
                }
            }while(x == false); // repetir enquanto o espaço não for encontrado
            printf("Você adquiriu %s!", i.c_str());
            return true; // Item adicionado, operação efetuada
        } else {
            cout << endl << "Seu inventário está cheio!";
            return false; // Item não adicionado, operação não efetuada
            system("pause");
        }
    }

    void info(){
        section("ability_score");
        for (int i =1; i < 7;  i++){
            switch (i){
                case 1: printf("\nForça        (FOR): "); break; 
                case 2: printf("\nDestreza     (DES): "); break;
                case 3: printf("\nConstituição (CON): "); break;
                case 4: printf("\nInteligência (INT): "); break;
                case 5: printf("\nSabedoria    (SAB): "); break;
                case 6: printf("\nCarisma      (CAR): "); break;
            }
            switch(i){
                case 1: printf("%d (%d)", this->atr.val("FOR"), this->atr.mod("FOR")); break;
                case 2: printf("%d (%d)", this->atr.val("DES"), this->atr.mod("DES")); break;
                case 3: printf("%d (%d)", this->atr.val("CON"), this->atr.mod("CON")); break;
                case 4: printf("%d (%d)", this->atr.val("INT"), this->atr.mod("INT")); break;
                case 5: printf("%d (%d)", this->atr.val("SAB"), this->atr.mod("SAB")); break;
                case 6: printf("%d (%d)", this->atr.val("CAR"), this->atr.mod("CAR")); break;
            }
        }

        printf("\n\n");
        
        // EXIBIR PONTOS DE VIDA E PONTOS DE MANA
        printf("Pontos de Vida (PV): %d / %d\n"
               "Pontos de Mana (PM): %d / %d\n", 
                pv.atual(), pv.max(), pm.atual(), pm.max());
        
        // EXIBIR INVENTÁRIO
        printf("Inventário (%d/%d)", itemcount, lim);
        for (int i=0; i < lim; i++){
            printf("\n[%d] %s", i+1, inv[i].c_str());
        }
    }
};*/
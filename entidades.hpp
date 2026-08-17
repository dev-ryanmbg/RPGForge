#pragma once
#include <iostream>
#include <locale.h>
#include "hud.hpp"
using namespace std;

class atributos{
    int _val[6];
    int _mod[20] = {-5, -4, -4, -3, -3, -2, -2, -1, -1, 0, 0, 1, 1, 2, 2, 3, 3, 4, 4, 5};

    public:
    void set(string atr, int nv){
        if (atr == "FOR"){
            _val[0] = nv;
        } else if (atr == "DES"){
            _val[1] = nv;
        } else if (atr == "CON"){
            _val[2] = nv;
        } else if (atr == "INT"){
            _val[3] = nv;
        } else if (atr == "SAB"){
            _val[4] = nv;
        } else if (atr == "CAR"){
            _val[5] = nv;
        }
    };
    //set: RECEBE a sigla do atributo(atr) e o Novo Valor(nv) DEPOIS DEFINE o atributo para o novo valor.

    void set_all(int v1, int v2, int v3, int v4, int v5, int v6){
        _val[0] = v1;
        _val[1] = v2;
        _val[2] = v3;
        _val[3] = v4;
        _val[4] = v5;
        _val[5] = v6;
    }
    // set_all: recebe os novos valores de atributo e atribui, respectivamente a cada um (ex: v1 = Força).

    int mod(string atr){
        if (atr == "FOR"){
            return _mod[0];
        } else if (atr == "DES"){
            return _mod[1];
        } else if (atr == "CON"){
            return _mod[2];
        } else if (atr == "INT"){
            return _mod[3];
        } else if (atr == "SAB"){
            return _mod[4];
        } else if (atr == "CAR"){
            return _mod[5];
        } else {
            return 0;
        }
    }
    //mod: RECEBE o nome do atributo (ex: "DES") e RETORNA o modificador do respectivo atributo.
    
    int val(string atr){
        if (atr == "FOR"){
            return _val[0];
        } else if (atr == "DES"){
            return _val[1];
        } else if (atr == "CON"){
            return _val[2];
        } else if (atr == "INT"){
            return _val[3];
        } else if (atr == "SAB"){
            return _val[4];
        } else if (atr == "CAR"){
            return _val[5];
        } else {
            return 0;
        }
    }
};

class points{
    int pointsMAX, pointsATUAL;

    public:
    void dmg(int x){
        if (pointsATUAL - x > 0){
            pointsATUAL -= x;
        } else {
            // morte()
        }
    }
    void heal(int x){
        if(pointsATUAL + x < pointsMAX){
            pointsATUAL += x;
        } else {
            pointsATUAL = pointsMAX;
        }
    }
    void set_max(int x){
        pointsMAX = x;
    }
    void set_atual(int x){
        pointsATUAL = x;
    }
    int atual(){
        return pointsATUAL;
    }
    int max(){
        return pointsMAX;
    }
};

class inv{
    public:
    
};

class personagem{
    public:
    
    string nome, classe;
    points pv, pm;
    atributos atr;

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
        section("Atributos");
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
};
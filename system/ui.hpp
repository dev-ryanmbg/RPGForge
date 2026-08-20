#pragma once
#include <stdio.h>
#include <locale.h>
#include <stdarg.h>
#include "statblock.hpp"
using namespace std;

// FILE NOT COMMENTED OR TRANSLATED YET

/*Recieves a text and print the message. This can be used to substitue by tags.
Back-end its just a printf(), but have the system tags and the data.*/
// NOT WORKING CORRECTLY

int searchForReplace(string obj, int checkingPosition, string text)
{   
    int checkingPosition;
    int replacePos;
    string::size_type stringLength = obj.size();
    if(text.find(obj.c_str(), checkingPosition, stringLength) != string::npos){
            replacePos = text.find(obj.c_str(), checkingPosition, checkingPosition + stringLength);
            return replacePos;
    } else {
        replacePos = 0;
        return replacePos;
    }
}

template <typename T>

void formatMessage(string text, ...){
    va_list args;
    vector<int> replacePos;
    int posFound;
    vector<T *> replaceType;

    for(size_t checkingPosition = 0; checkingPosition < text.size(); checkingPosition++){
        posFound = searchForReplace("{AbilityScore}", checkingPosition, text)
        if(posFound != 0){
        replacePos.push_back(posFound);
        replaceType.push_back(AbilityScore);
        text.replace("",checkingPosition, "{AbilityScore}".size())
        }
        posFound = searchForReplace("{Points}", checkingPosition, text)
        if(posFound != 0){
        replacePos.push_back(posFound);
        replaceType.push_back(Points);
        text.replace("",checkingPosition, "{Points}".size())
        }
        // replacePos.push_back(searchForReplace("{Container}", checkingPosition, text));
        // replacePos.push_back(searchForReplace("{Char}", checkingPosition, text));
    }
    va_start(args, replacePos.size());

    vector<string> finalReplace;
    for(int loop = 0; loop < replacePos.size(); loop++){
        finalReplace = va_arg(args, replaceType[loop])
    };

    va_end(args);

    cout << text << endl;
}


// Prints "ERROR: " then text
void errorMessage(string text, ...){
    va_list args;
    va_start(args, text);

    printf("ERROR: ");

    for(size_t checkingPosition = 0; checkingPosition < text.size(); checkingPosition++){
        int replacePos; // Position of the part that will be replaced
        if(text.find("{AbilityScore}", checkingPosition, 15) != string::npos){   
            replacePos = text.find("{AbilityScore}", checkingPosition, 15);
            text.replace(replacePos, 13, (va_arg(args, AbilityScore*))->viewName);
        }

        else if (text.find("{Points}", checkingPosition, 9) != string::npos){
            replacePos = text.find("{Points}", checkingPosition, 9);
            text.replace(replacePos, 9, (va_arg(args, Points*))->viewName);
        }

        else if(text.find("{Container}", checkingPosition, 12) != string::npos){
            replacePos = text.find("{Container}", checkingPosition, 12);
            text.replace(replacePos, 12, (va_arg(args, Container*))->viewName);
        }

        else if(text.find("{char}", checkingPosition, checkingPosition + 7) != string::npos){
            replacePos = text.find("{char}", checkingPosition, checkingPosition + 7);
            text.replace(replacePos, 7, va_arg(args, char *));
        }
    }

    cout << text << endl;
}

struct style{
    int width;
    string header_style, section_style;
    style(){
        width=30;
        header_style="=";
        section_style="-";
    }; 
};

style _default;

int ceil(int x){
    int integer = static_cast<int>(x);

    if (x > integer)
        integer++;

    return integer;
}

void header(string cont){
    int _width = _default.width;
    float mid = ceil(_width/2.0);
    float mid_cont = ceil(cont.size()/2);


    for(int i = 0; i < _width; i++){printf("%s", _default.header_style.c_str());}
    printf("\n");
    for(int i = 0; i < (mid - mid_cont); i++){printf(" ");}
    printf("%s\n", cont.c_str());
    for(int i = 0; i < _width; i++){printf("%s", _default.header_style.c_str());}
    printf("\n");
}

void section(string cont){
    int _width = _default.width;
    printf("\n%s ", cont.c_str());
    for (string::size_type i=0; i < ((_width-1) - cont.size()); i++){printf("%s", _default.section_style.c_str());}
    printf("\n");
}

// TODO: Replace this UTF-8 handling with a proper solution
// Code imported from: https://www.reddit.com/r/Cplusplus/comments/1axx2u2/some_tips_to_handle_utf8_strings_in_c/?tl=pt-br
int check_utf8_char(string &utf, long i)
{
    unsigned char check = utf[i] & 0xF0;

    switch (check)
    {
    case 0xC0:
        return bool((utf[i + 1] & 0x80) == 0x80) * 1;
    case 0xE0:
        return bool(((utf[i + 1] & 0x80) == 0x80 && 
                     (utf[i + 2] & 0x80) == 0x80)) * 2;
    case 0xF0:
        return bool(((utf[i + 1] & 0x80) == 0x80 && 
                     (utf[i + 2] & 0x80) == 0x80 && 
                     (utf[i + 3] & 0x80) == 0x80)) * 3;
    }
    return 0;
}

void lista(string itens){
    int x = 1;
    printf("[%d] ", x);
    for(string::size_type i=0; i < size(itens); i++){
        if (itens[i] != '/'){
            long sz;
            string finalprint;
            sz = check_utf8_char(itens, i);
            //sz >= 0 && sz <= 3, precisamos adicionar 1 para o tamanho completo
            finalprint = itens.substr(i, sz + 1);
            //adicionamos esse valor para pular o caractere integer de uma vez
            //daí o motivo pelo qual retornamos o tamanho completo - 1
            i += sz;  
            printf("%s", finalprint.c_str());
        } else {
            x++;
            printf("\n[%d] ", x);
        }
    }
}


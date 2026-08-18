#pragma once
#include <iostream>
#include <stdio.h>
#include <locale.h>
using namespace std;

// FILE NOT COMMENTED OR TRANSLATED YET

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
}

void section(string cont){
    int _width = _default.width;
    printf("\n%s ", cont.c_str());
    for (string::size_type i=0; i < ((_width-1) - cont.size()); i++){printf("%s", _default.section_style.c_str());}
    printf("\n");
}

// Código importado de: https://www.reddit.com/r/Cplusplus/comments/1axx2u2/some_tips_to_handle_utf8_strings_in_c/?tl=pt-br
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


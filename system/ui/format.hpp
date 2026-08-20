#pragma once
#include <stdarg.h>
#include <iostream>
using namespace std;

void formatMessage(string _text, ...){
    cout << "TESTE NOVA VERSAO 456" << endl;
    va_list args;
    cout << _text.size() << endl;
    for(size_t checkingPosition = 0; checkingPosition < _text.size(); checkingPosition++){
        cout << checkingPosition << endl;
        if(_text[checkingPosition] == '{'){
            cout << _text[checkingPosition];
        }
    }
    va_end(args);
    cout << _text << endl;
}
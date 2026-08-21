#pragma once
#include <stdarg.h>
#include <iostream>
#include <vector>
#include "../statblocks/AbilityScore.hpp"
#include "../statblocks/Container.hpp"
#include "../statblocks/Points.hpp"

using namespace std;

int returnType(string text, int checkingPosition){
    vector<string> typeTags; // Stores the types of tags to be analized
    // Typetags:
    typeTags.push_back("{AbilityScore}");
    typeTags.push_back("{Container}");
    typeTags.push_back("{Points}");
    int originalCheckingPosition = checkingPosition; // Keeps the original enter value for checkingPosition

    // Checks all members of vector typeTags
    // loop: goes through all the vector
    for(size_t loop = 0; loop < typeTags.size(); loop++){
        // Checks if the checking position (and the following characters) matches the current typeTag 
        size_t matchingCharacters = 0;
        checkingPosition = originalCheckingPosition;
        for(size_t inTypePosition = 0; inTypePosition < (typeTags[loop]).size(); inTypePosition++){
            if(text[checkingPosition] == (typeTags[loop])[inTypePosition]){
                matchingCharacters++;
                checkingPosition++;
                if(matchingCharacters == (typeTags[loop]).size()){
                    return loop + 1; // return number of typeTag
                    /*
                    1: AbilityScore type
                    2: Container type
                    3: Points type
                    */
                }
            }
        }
    }
    return 0;
}

void formatMessage(string _text, ...){
    vector<int> replacePos;
    va_list args;
    va_start(args, _text);
    for(size_t checkingPosition = 0; checkingPosition < _text.size(); checkingPosition++){
        if(_text[checkingPosition] == '{'){
            switch (returnType(_text, checkingPosition)){
                case 1:
                _text.replace(checkingPosition, string("{AbilityScore}").size(), va_arg(args, AbilityScore *)->viewName);
                break;
                case 2:
                _text.replace(checkingPosition, string("{Container}").size(), va_arg(args, Container *)->viewName);
                break;
                case 3:
                 _text.replace(checkingPosition, string("{AbilityScore}").size(), va_arg(args, Points *)->viewName);
                break;
            }
        }
    }

    va_end(args);
    cout << _text << endl;
}
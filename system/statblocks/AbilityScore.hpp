#pragma once
#include <iostream>
using namespace std;

struct AbilityScore{

    string viewName; // element name (ex: "Strength")
    int minValue; // the maximum value it can reach. Can't be higher than this. 
    int value; // the actual value.
    int maxValue; // the minimum value it can reach. Can't be lower than this.
    
    // When you start an element of type AbilityScore, enter the parameters below into the order.
    AbilityScore(string _viewName, int _minValue, int _maxValue, int _startingValue){
        viewName = _viewName;
        minValue = _minValue;
        value = _startingValue;
        maxValue = _maxValue;
    }

    // Use this function to set the value for an new one
    void set(int _newValue){
        if(_newValue >= minValue && _newValue <= maxValue){value = _newValue;}
    }
};

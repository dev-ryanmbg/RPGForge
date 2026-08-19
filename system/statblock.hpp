#pragma once
#include <iostream>
#include <vector>
using namespace std;

void formatMessage(string _text, ...);
void errorMessage(string _text, ...);

// TODO: Refactor the system above
// the code above is an temporary solution for the "formatMessage()" function (see more in ui.hpp).

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

struct Points{
    string viewName; // element name that will be shown "ex: Hit Points"
    int maxPoints; // actualPoints cannot exceed this value
    int actualPoints; // entity actual points
    int minPoints; 
    /*When actualPoints fall below this value, the function assigned to the string event will run
    ex: for HP could be 1, and then set to trigger "Death"*/
    int runOutEvent; // this value will be matched into switch and trigger some event of the function damage() above.
    /* just an example:
    0 = Just keep the minimum value, so nothing happens, no matter how much times it go to minimum.
    1 = death()
    2 = breakItem()
    3 to 6 = custom user functions
    */

    // When you start an element of type Points, enter the parameters below into the order.
    Points(string _viewname, int _maxPoints = 1, int _actualPoints = 1, int _minPoints = 1, int _runOutEvent = 0){
        viewName = _viewname;
        maxPoints = _maxPoints;
        actualPoints = _actualPoints;
        minPoints = _minPoints;
        runOutEvent = _runOutEvent;
    }

    /* Reduce actual Points
    If below the minimum Points, triggers the event*/
    void damage(int _damage){
        if (actualPoints - _damage >= minPoints){
            actualPoints -= _damage;
        } else {
            actualPoints = minPoints;
            // switch (event){...}
        }
    }

    /* Increase actual Points
    If above the maximum Points, just keep the maximum value*/
    void heal(int _heal){
        if(actualPoints + _heal < maxPoints){
            actualPoints += _heal;
        } else {
            actualPoints = maxPoints;
        }
    }
};

struct Container{
    string viewName; // Element name that will be shown for this Container. ex: "Inventory".
    vector<string> content; // Contain all the contents of the Container.
    int capacity; // How many slots this Container has.

    // Constructor parameters:
    // _viewName: Element name that will be shown for this Container. ex: "Inventory". 
    // _capacity:  How many slots this Container has.
    Container(string _viewName, int _capacity = 1){
        viewName = _viewName;
        capacity = _capacity;
        content.resize(capacity - 1, "");
    }

    // Return the number of ocuppied slots
    int occupied(){
        int numberOfOcuppiedSlots = 0;
        for(int loop = 0; loop < capacity; loop++){
            if(content[loop] != ""){
                numberOfOcuppiedSlots += 1;
            }
        }
        return numberOfOcuppiedSlots;
    }

    /*Searchs for an free slot into the Container and returns the slot position.        
        The verification rule is based on "_checkType": 
            1: start to end (Ascending)
            2: end to start (Descending).
            
        Returns:
                "freeSlot": the slot position (array index + 1).
                0: no free slot found.
            */ 
    int searchFreeSlot(int _checkType = 0){
        int slotVerify; // Current position that is being verified.
        /*Can't be below 0 because it will be the starting position 
        to search in the array. Arrays index always start on 0.*/

        int changeValue; // Determines how it will go through the vector "content". Automatically defined by the _checkType.
        int freeSlot = 0; // Number of the free slot found. 0 if not found.

        // Verify the check type choosen by the user. Default is Ascending.
        switch(_checkType){
            case 1: // Ascending
                slotVerify = 0;
                changeValue = +1;
                break;
            case 2: // Descending
                slotVerify = capacity - 1;
                changeValue = -1;
                break;
            default: // Unvalid type
                errorMessage("Unvalid check type into searchFreeSlot function {char}\nThe program will continue to run, however it will be used the default check type Ascending (start from slot 1)", _checkType);
                slotVerify = 0;
        }

        /* Check into "content" array members using "slotVerify" as index 
        following the check type (Ascending or Descending)*/
        for(int loop = 0; loop < capacity; loop++){
            if(content[slotVerify] == ""){
                freeSlot = slotVerify + 1;
                return freeSlot;
            }
            
            slotVerify += changeValue; // move to next one
            
        }
        
        return freeSlot;
    }

    /*Used when you want the entity to pick object
        Returns:
            true : if entity can pick the object
            false: if entity can't pick the object*/
    bool insert(string _object, string _sucessfullMessage = "", string _failMessage = ""){
        // Free slot found
        int freeSlot = searchFreeSlot();

        if(freeSlot != 0){
            if (_sucessfullMessage != ""){
                formatMessage(_sucessfullMessage);
                getchar();
            }
            content[freeSlot-1] = _object;
            return true;

        // Free slot not found
        } else {
            if (_failMessage != ""){
                formatMessage(_failMessage);
                getchar();
            }
            return false;
        }
    }   
};
#include <iostream>
using namespace std;

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

#ifndef ITEM_H_INCLUDED
#define ITEM_H_INCLUDED

#include <iostream>
#include <string>
#include <vector>
#include "Object.h"
#include "Player.h"

using namespace std;

class Player;

class Item: public Object
{
private:
    int health,attack,defense;
    int cost;
    bool sell;
public:
    Item();
    Item(string, int, int, int, int);

    /* Virtual function that you need to complete    */
    /* In Item, this function should deal with the   */
    /* pick up action. You should add status to the  */
    /* player.                                       */
    bool triggerEvent(Object*);

    /* Set & Get function*/
    int getHealth();
    int getAttack();
    int getDefense();
    int getCost();
    bool getSell();
    void setHealth(int);
    void setAttack(int);
    void setDefense(int);
    void setSell();
};

class Chest: public Object
{
private:
    Item contain;
public:
    Chest();
    Chest(Item, string);
    void setItem(Item);
    Item getItem();
    bool triggerEvent(Object*);
};

#endif // ITEM_H_INCLUDED

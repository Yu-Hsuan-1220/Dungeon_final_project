#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

#include <iostream>
#include <string>
#include <vector>
#include "GameCharacter.h"
#include "Room.h"
#include "Item.h"

using namespace std;

class Item;

class Player: public GameCharacter
{
private:
    Room* currentRoom;
    Room* previousRoom;
    vector<string> inventory;
    int mp;
    int poison;
    bool key;
public:
    Player();
    Player(string,int,int,int, int, int, int);

    void increaseStates(int,int,int,int, int, int);
    void decreaseStates(int,int);
    void changeRoom(Room*);
    void addItem(string);
    /* Virtual function that you need to complete   */
    /* In Player, this function should show the     */
    /* status of player.                            */
    bool triggerEvent(Object*);
    int getMP();
    int getAtt();
    int getDef();
    int getHel();
    void setHel(int);
    void setMP(int);
    int getm();
    void setPoi(int);
    void setKey();
    /* Set & Get function*/
    void setCurrentRoom(Room*);
    void setPreviousRoom(Room*);

    Room* getCurrentRoom();
    Room* getPreviousRoom();
    void setPoison(int);
    int getPoison();
    bool getKey();
    vector<string> getInventory();
};

#endif // PLAYER_H_INCLUDED

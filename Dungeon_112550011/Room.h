#ifndef ROOM_H_INCLUDED
#define ROOM_H_INCLUDED

#include <iostream>
#include <string>
#include <vector>
#include "Object.h"

using namespace std;

class Room
{
private:
    Room* upRoom;
    Room* downRoom;
    Room* leftRoom;
    Room* rightRoom;
    bool isExit;
    int index;
    int hungerDecrese;
    int thirstyDecrease;
    int type;
    vector<Object*> objects; /*contain 1 or multiple objects, including monster, npc, etc*/
public:

    Room();
    Room(bool, int, vector<Object*>);
    /*pop out the specific object, used when the interaction is d   one*/

    /* Set & Get function*/
    void setUpRoom(Room*);
    void setDownRoom(Room*);
    void setLeftRoom(Room*);
    void setRightRoom(Room*);
    void setIsExit(bool);
    void setIndex(int);
    void setType(int);
    void setObjects(vector<Object*>);
    void setHungerDecrease(int);
    void setThirstyDecrease(int);
    bool getIsExit();
    int getIndex();
    int getHungerDecrease();
    int getThirstyDecrease();
    int getType();
    vector<Object*> getObjects();
    Room* getUpRoom();
    Room* getDownRoom();
    Room* getLeftRoom();
    Room* getRightRoom();
};

#endif // ROOM_H_INCLUDED

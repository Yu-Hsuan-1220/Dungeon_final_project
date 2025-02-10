#include "Room.h"
#include<bits/stdc++.h>
using namespace std;
Room::Room(){
    leftRoom=NULL;
    rightRoom=NULL;
    upRoom=NULL;
    downRoom=NULL;
}
Room::Room(bool exit, int index, vector<Object*> obj){
    this->isExit = exit;
    this->index = index;
    this->objects = obj;
    leftRoom=NULL;
    rightRoom=NULL;
    upRoom=NULL;
    downRoom=NULL;
}



void Room::setUpRoom(Room* up){
    upRoom= up;
}
void Room::setDownRoom(Room* down){
    downRoom= down;
}
void Room::setLeftRoom(Room* left){
    leftRoom= left;
}
void Room::setRightRoom(Room* right){
    rightRoom= right;
}
void Room::setIsExit(bool b){
    isExit=b;
}
void Room::setIndex(int idx){
    index=idx;
}
void Room::setObjects(vector<Object*> vec){
    for(Object* u: vec){
        objects.push_back(u);
    }
}
void Room::setType(int n){
    type=n;
}
void Room::setHungerDecrease(int n){
    hungerDecrese=n;
}
void Room::setThirstyDecrease(int n){
    thirstyDecrease=n;
}
bool Room::getIsExit(){
    return isExit;
}
int Room::getIndex(){
    return index;
}
vector<Object*> Room::getObjects(){
    return objects;
}
Room* Room::getUpRoom(){
    return upRoom;
}
Room* Room::getDownRoom(){
    return downRoom;
}
Room* Room::getLeftRoom(){
    return leftRoom;
}
Room* Room::getRightRoom(){
    return rightRoom;
}
int Room::getHungerDecrease(){
    return hungerDecrese;
}
int Room::getThirstyDecrease(){
    return thirstyDecrease;
}
int Room::getType(){
    return type;
}

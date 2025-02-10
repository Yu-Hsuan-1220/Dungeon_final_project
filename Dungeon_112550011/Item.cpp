#include "Item.h"
#include<bits/stdc++.h>
using namespace std;
Item::Item(){}
Item::Item(string name, int health, int defense, int attack, int cost){
    this->setName(name);
    this->setTag("Item");
    this->health=health;
    this->defense=defense;
    this->attack=attack;
    this->cost=cost;
    this->sell=true;
}
int Item::getHealth(){
    return health;
}
int Item::getAttack(){
    return attack;
}
int Item::getDefense(){
    return defense;
}
int Item::getCost(){
    return cost;
}
bool Item::getSell(){
    return sell;
}
void Item::setHealth(int health){
    this->health=health;
}
void Item::setAttack(int attack){
    this->attack=attack;
}
void Item::setDefense(int defense){
    this->defense=defense;
}
void Item::setSell(){
    this->sell=false;
}
bool Item::triggerEvent(Object* Obj){
    if(Obj->getm()>=cost){
        Obj->increaseStates(health, defense, attack, cost, 0, 0);
        bool contain = false;
        for(string s: Obj->getInventory()){
            if(s==getName()){
                contain=true;
            }
        }
        if(!contain){
            Obj->addItem(getName());
        }
        if(cost)cout<<"Buy a "<<getName()<<"\n";

    }
    else{
        cout<<"no enough money\n\n";
    }
    if(getName()=="banana"){
        cout<<"get 30 hunger\n\n";
        Obj->increaseStates(0, 0, 0, 0, 30, 0);
    }
    else if(getName()=="milk"){
        cout<<"NO poison now\n\n";
        Obj->setPoi(0);
    }
    else if(getName()=="water"){
        cout<<"get 30 thirsty\n\n";
        Obj->increaseStates(0, 0, 0, 0, 0, 30);
    }
    return true;
}
Chest::Chest(){

}
Chest::Chest(Item i, string s){
    contain = i;
    this->setName(s);
    this->setTag("Chest");
}
Item Chest::getItem(){
    return contain;
}
void Chest::setItem(Item i){
    contain = i;
}
bool Chest::triggerEvent(Object* Obj){
    cout<<"Opening a "<<getName()<<"\nYou get a "<<contain.getName()<<"\n";

    cout<<"Increse your health  : "<<contain.getHealth()<<"\n";
    cout<<"Increse your defense : "<<contain.getDefense()<<"\n";
    cout<<"Increse your attack  : "<<contain.getAttack()<<"\n";

    cout<<"\n";
    contain.triggerEvent(Obj);
    return true;
}


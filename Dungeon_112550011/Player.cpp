#include "Player.h"
#include<bits/stdc++.h>
using namespace std;
Player::Player(){

}
Player::Player(string s,int a,int b,int c, int d, int e, int f){
    this->setName(s);
    this->setMaxHealth(a);
    this->setCurrentHealth(a);
    this->setDefense(b);
    this->setAttack(c);
    this->setHunger(d);
    this->setThirsty(e);
    this->setMoney(f);
    this->mp=0;
    this->poison=0;
    this->key=false;
    setDebuff(false);
}

void Player::increaseStates(int a,int b,int c, int d,int e,int f){
    this->setCurrentHealth(this->getCurrentHealth()+a);
    this->setDefense(this->getDefense()+b);
    this->setAttack(this->getAttack()+c);
    this->setMoney(this->getMoney()-d);
    this->setHunger(this->getHunger()+e);
    this->setThirsty(this->getThirsty()+f);
}
void Player::changeRoom(Room* r){
    previousRoom=currentRoom;
    currentRoom=r;
}
void Player::decreaseStates(int a, int b){
    this->setHunger(((this->getHunger()-a) <= 0 ) ? 0: this->getHunger()-a);
    this->setThirsty(((this->getThirsty())-b <= 0 ) ? 0: this->getThirsty()-b);
    if(this->getHunger()==0){
        cout<<"Health - 15 because of Hunger\n";
        setCurrentHealth(getCurrentHealth()-15);
        if(getCurrentHealth()<=0){
            cout<<"You died because of Hunger\n";
            return;
        }
    }
    if(this->getThirsty()==0){
        cout<<"Health - 10 becasue of Thirsty\n";
        setCurrentHealth(getCurrentHealth()-10);
        setDebuff(true);
        if(getCurrentHealth()<=0){
            cout<<"You died because of Thirsty\n";
            return;
        }
    }
    else{
        setDebuff(false);
    }
    if(poison){
        cout<<"Health -10 because of Poison\n";
        this->setCurrentHealth(this->getCurrentHealth()-poison);

    }
}

int Player::getm(){
    return this->getMoney();
}
int Player::getMP(){
    return this->mp;
}
int Player::getAtt(){
    return this->getAttack();
}
int Player::getDef(){
    return this->getDefense();
}
int Player::getHel(){
    return this->getCurrentHealth();
}
void Player::setHel(int x){
    this->setCurrentHealth(this->getCurrentHealth()-x);
}
void Player::setMP(int x){
    this->mp+=x;
}
void Player::setPoi(int x){
    this->poison=x;
}
void Player::setKey(){
    this->key=true;
}
void Player::addItem(string s){
    inventory.push_back(s);
}
bool Player::triggerEvent(Object* Obj){
    cout<<"\n";
    cout<<this->getName()<<"\'s status:\n";
    cout<<"Current health : "<<this->getCurrentHealth()<<"\n";
    cout<<"Defense        : "<<this->getDefense()<<"\n";
    cout<<"Attack         : "<<this->getAttack();
    if(getDebuff())  cout<<"  (debuff)";
    cout<<"\n";
    cout<<"Hunger         : "<<this->getHunger()<<"\n";
    cout<<"Thirsty        : "<<this->getThirsty()<<"\n";
    cout<<"Poison         : "<<this->poison<<"\n";
    cout<<"Mp             : "<<this->mp<<"\n";
    cout<<"Money          : "<<this->getMoney()<<"\n";
    cout<<"Inventory : \n";
    for(string s: inventory){
        cout<<s<<'.';
    }
    cout<<"\n\n";
    return true;
}

void Player::setCurrentRoom(Room* r){
    currentRoom=r;
}
void Player::setPreviousRoom(Room* r){
    previousRoom=r;
}

Room* Player::getCurrentRoom(){
    return currentRoom;
}
Room* Player::getPreviousRoom(){
    return previousRoom;
}
vector<string> Player::getInventory(){
    return inventory;
}
int Player::getPoison(){
    return poison;
}
void Player::setPoison(int n){
    poison = n;
}
bool Player::getKey(){
    return key;
}


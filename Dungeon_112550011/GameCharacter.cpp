#include "GameCharacter.h"
#include<bits/stdc++.h>
using namespace std;

GameCharacter::GameCharacter(){

}
GameCharacter::GameCharacter(string, string, int ,int ,int ){

}
void GameCharacter::setMaxHealth(int health){
    this->maxHealth=health;
}
void GameCharacter::setCurrentHealth(int health){
    this->currentHealth=health;
}
void GameCharacter::setAttack(int attack){
    this->attack = attack;
}
void GameCharacter::setDefense(int defense){
    this->defense = defense;

}
void GameCharacter::setHunger(int hunger){
    this->hunger = (hunger<0)?  0: hunger;
}
void GameCharacter::setThirsty(int thirsty){
    this->thirsty= (thirsty<0)? 0: thirsty;
}
void GameCharacter::setMoney(int money){
    this->money= money;
}
int GameCharacter::getMaxHealth(){
    return maxHealth;
}
int GameCharacter::getCurrentHealth(){
    return currentHealth;
}
int GameCharacter::getAttack(){
    if(debuff) return floor(attack*0.8);
    return attack;
}
int GameCharacter::getDefense(){
    return defense;
}
int GameCharacter::getHunger(){
    return hunger;
}
int GameCharacter::getThirsty(){
    return thirsty;
}
int GameCharacter::getMoney(){
    return money;
}
bool GameCharacter::getDebuff(){
    return debuff;
}
void GameCharacter::setDebuff(bool b){
    debuff = b;
}

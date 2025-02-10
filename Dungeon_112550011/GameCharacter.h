#ifndef GAMECHARACTER_H_INCLUDED
#define GAMECHARACTER_H_INCLUDED
#include<bits/stdc++.h>
#include "Object.h"
using namespace std;

class GameCharacter: public Object
{
private:
    int maxHealth;
    int currentHealth;
    int attack;
    int defense;
    int hunger;
    int thirsty;
    int money;
    bool debuff;
public:
    GameCharacter();
    GameCharacter(string,string,int,int,int);



    /* Set & Get function*/
    void setMaxHealth(int);
    void setCurrentHealth(int);
    void setAttack(int);
    void setDefense(int);
    void setHunger(int);
    void setThirsty(int);
    void setMoney(int);
    int getMaxHealth();
    int getCurrentHealth();
    int getAttack();
    int getDefense();
    int getHunger();
    int getThirsty();
    int getMoney();
    bool getDebuff();
    void setDebuff(bool);
};
#endif // GAMECHARACTER_H_INCLUDED

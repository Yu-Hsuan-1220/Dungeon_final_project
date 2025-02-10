#include "Monster.h"
#include<bits/stdc++.h>
using namespace std;
Monster::Monster(){

}
Monster::Monster(string name,int health,int defense,int attack, int money){
    this->setName(name);
    this->setMaxHealth(health);
    this->setCurrentHealth(health);
    this->setDefense(defense);
    this->setAttack(attack);
    this->setTag("Monster");
    this->setMoney(money);
    this->script="\n";
}

bool Monster::triggerEvent(Object* Obj){
    if(getName()=="Boss")
        cout<<"I am the Boss of the dungeon. You can leave here if you beated me!!\n";
    else cout<<"I am Monter "<<getName()<<" \nI won't let you pass!!!!!\n";
    cout<<"\nMonster Status : \n";
    cout<<"Health         : "<<this->getMaxHealth()<<"\n";
    cout<<"Defense        : "<<this->getDefense()<<"\n";
    cout<<"Attack         : "<<this->getAttack()<<"\n\n";
    cout<<"Do you want to fight "<<getName()<<"?  1 Fight : 0 RUN\n";
    cout<<"Enter your choice : ";
    int req;
    cin>>req;
    if(req!=1) return false;
    else{
        cout<<"\nFight start!!!\n\n";
        while(1){
            cout<<"\n\nYour current health "<<Obj->getHel()<<"\n";
            cout<<"Monster current health "<<getCurrentHealth()<<"\n\n";
            cout<<"Choose an action : \n0 or Invalid Input RUN\n1 normal attack\n";
            if(Obj->getMP()>=50){
                cout<<"2 special attack\n";
            }
            cout<<"Enter your action : ";
            cin>>req;
            if(req==0){
                cout<<"Run~\n\n";
                setCurrentHealth(getMaxHealth());
                return false;
            }
            else{
                if(req==1){
                    cout<<"Your deal "<<Obj->getAtt()<<" damages to "<<getName()<<"\n";
                    Obj->setMP(10);
                    setCurrentHealth(getCurrentHealth()-Obj->getAtt());
                }
                else if(req==2){
                    if(Obj->getMP()<50){
                        cout<<"Run~\n\n";
                        return false;
                    }
                    else{
                        cout<<"Your deal "<<100+Obj->getAtt()<<" damages to "<<getName()<<"\n";
                        Obj->setMP(-50);
                        setCurrentHealth(getCurrentHealth()-(Obj->getAtt()*2));
                    }
                }
            }
            if(getCurrentHealth()<=0){
                cout<<"You defeat "<<getName()<<"\n";
                cout<<"You get money "<<getMoney()<<"\n";
                cout<<"You get carrion which decrease your hunger by 40\n";
                cout<<"You get a health potion which increase your health by 50\n";
                Obj->increaseStates(50, 0, 0, -getMoney(), 40, 0);
                setTag("Died");
                break;
            }
            int damage=(getAttack()-Obj->getDef()<0)? 0: getAttack()-Obj->getDef();
            cout<<getName()<<" deal "<<damage<<" damage to you\n";
            Obj->setHel(damage);
            if(Obj->getHel()<=0){
                cout<<"\nYou are killed by "<<getName()<<"\n";
                return false;
            }
        }
    }
    if(getName()=="keyKeeper"){
        cout<<"You get a key for a room\n";
        Obj->setKey();
    }
    return true;
}

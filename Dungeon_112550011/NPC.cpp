#include "NPC.h"
#include<bits/stdc++.h>
using namespace std;
NPC::NPC(){

}
NPC::NPC(string a, string b, vector<Item> items){
    this->setName(a);
    this->setScript(b);
    this->commodity= items;
    this->setTag("Npc");
}
void NPC::listCommodity(){
    for(int i=0; i<commodity.size(); i++){
        Item item = commodity[i];
        cout<<i<<' '<<item.getName()<<" cost : "<<item.getCost()<<"\n";
        if(item.getName()=="banana"){
            cout<<"decrease your hunger \n";
        }
        else if(item.getName()=="milk"){
            cout<<"eliminate poison\n";

        }
        else if(item.getName()=="water"){
            cout<<"decrease your thirsty\n";
        }
        else{
            cout<<"Health : "<< item.getHealth()<<"\n";
            cout<<"Defense : "<< item.getDefense()<<"\n";
            cout<<"Attack : "<< item.getAttack()<<"\n\n";
        }

    }


}
bool NPC::triggerEvent(Object* Obj){
    cout<<getScript()<<"\n";
    cout<<"Current money : "<<Obj->getm()<<"\n";
    cout<<"Here the Items you can buy: \n\n";
    listCommodity();
    cout<<"Which one do want to buy? (Invalid Input : None) : ";
    int req;
    cin>>req;
    if(req<commodity.size() && req>=0){
        Item item = commodity[req];

        item.triggerEvent(Obj);

    }
    return true;
}
void NPC::setScript(string s){
    script=s;
}
void NPC::setCommodity(vector<Item> items){
    commodity=items;
}
string NPC::getScript(){
    return script;
}
vector<Item> NPC::getCommodity(){
    return commodity;
}

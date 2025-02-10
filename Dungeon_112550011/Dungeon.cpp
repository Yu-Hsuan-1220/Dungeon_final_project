#include "Dungeon.h"
#include<bits/stdc++.h>
using namespace std;

void Dungeon::createMap(){

    for(int i=0; i<20; i++){
        Room tmp = Room();
        tmp.setIndex(i);
        tmp.setHungerDecrease(1);
        tmp.setThirstyDecrease(1);
        tmp.setIsExit(false);
        tmp.setType(1); //1 normal  2 swamp 3 forest 4 desert
        rooms.push_back(tmp);
    }
    rooms[0].setRightRoom(&rooms[1]);
    rooms[1].setLeftRoom(&rooms[0]);

    rooms[1].setRightRoom(&rooms[2]);
    rooms[2].setLeftRoom(&rooms[1]);

    rooms[1].setDownRoom(&rooms[3]);
    rooms[3].setUpRoom(&rooms[1]);

    rooms[3].setRightRoom(&rooms[4]);
    rooms[4].setLeftRoom(&rooms[3]);

    rooms[4].setRightRoom(&rooms[5]);
    rooms[5].setLeftRoom(&rooms[4]);

    rooms[3].setDownRoom(&rooms[7]);
    rooms[7].setUpRoom(&rooms[3]);

    rooms[4].setDownRoom(&rooms[7]);
    rooms[7].setRightRoom(&rooms[4]);

    rooms[6].setRightRoom(&rooms[7]);
    rooms[7].setLeftRoom(&rooms[6]);

    rooms[7].setDownRoom(&rooms[8]);
    rooms[8].setUpRoom(&rooms[7]);

    rooms[8].setRightRoom(&rooms[9]);
    rooms[9].setLeftRoom(&rooms[8]);

    rooms[9].setRightRoom(&rooms[10]);
    rooms[10].setLeftRoom(&rooms[9]);

    rooms[10].setDownRoom(&rooms[11]);
    rooms[11].setUpRoom(&rooms[10]);

    rooms[9].setDownRoom(&rooms[13]);
    rooms[13].setUpRoom(&rooms[9]);

    rooms[13].setDownRoom(&rooms[14]);
    rooms[14].setUpRoom(&rooms[13]);
    //room 0
    Item a("wooden sword", 0, 0, 10, 10);
    Item b("shield", 0, 10, 0, 10);
    Item c("apple", 50, 0 , 0, 10);
    vector<Item> tmp;
    tmp.push_back(a);
    tmp.push_back(b);
    tmp.push_back(c);
    NPC* starter = new NPC("Chris", "Welcome to dungeon. \nTry your best to kill the boss and leave here\n", tmp);
    vector<Object*> vec;
    vec.push_back(starter);
    rooms[0].setObjects(vec);
    rooms[0].setThirstyDecrease(1);
    rooms[0].setHungerDecrease(1);
    //room 1
    while(vec.size()>0) vec.pop_back(); while(tmp.size()>0) tmp.pop_back();
    Monster* banana = new Monster("Banana", 50, 0, 15, 20);
    banana->script="You will get 10 MP for your every normal attack\n You can use specail attack when you have 50 MP";
    vec.push_back(banana);
    rooms[1].setObjects(vec);
    rooms[1].setThirstyDecrease(1);
    rooms[1].setHungerDecrease(1);
    //room 2
    while(vec.size()>0) vec.pop_back(); while(tmp.size()>0) tmp.pop_back();
    Monster* skelton = new Monster("skelton king", 150, 0, 25, 20);
    vec.push_back(skelton);
    Item item("Iron sword", 0, 0 , 20, 0);
    Chest* che = new Chest(item, "iron chest");
    vec.push_back(che);
    rooms[2].setObjects(vec);
    rooms[2].setThirstyDecrease(1);
    rooms[2].setHungerDecrease(1);
    //room3
    while(vec.size()>0) vec.pop_back(); while(tmp.size()>0) tmp.pop_back();
    rooms[3].setType(2);
    Monster* slime = new Monster("slime", 300, 0, 50, 40);
    vec.push_back(slime);
    rooms[3].setObjects(vec);
    rooms[3].setThirstyDecrease(1);
    rooms[3].setHungerDecrease(1);
    //room4
    while(vec.size()>0) vec.pop_back(); while(tmp.size()>0) tmp.pop_back();
    Item d("water", 0, 0, 0, 10);
    Item e("banana", 0, 0, 0, 10);
    Item f("milk", 0, 0 , 0, 15);
    tmp.push_back(d);
    tmp.push_back(e);
    tmp.push_back(f);
    NPC* vendor = new NPC("Vendor", "I sell lots of essential items for survival\n", tmp);
    vec.push_back(vendor);
    rooms[4].setObjects(vec);
    rooms[4].setThirstyDecrease(1);
    rooms[4].setHungerDecrease(1);
    //room5
    while(vec.size()>0) vec.pop_back(); while(tmp.size()>0) tmp.pop_back();
    Monster* keyKeeper = new Monster("keyKeeper", 320, 0, 50, 40);
    vec.push_back(keyKeeper);
    rooms[5].setObjects(vec);
    rooms[5].setThirstyDecrease(1);
    rooms[5].setHungerDecrease(1);
    //room6
    while(vec.size()>0) vec.pop_back(); while(tmp.size()>0) tmp.pop_back();
    rooms[6].setType(3);
    rooms[6].setThirstyDecrease(1);
    rooms[6].setHungerDecrease(2);

    //room7
    while(vec.size()>0) vec.pop_back(); while(tmp.size()>0) tmp.pop_back();
    Monster* Tiger = new Monster("Tiger", 400, 0, 50, 80);
    vec.push_back(Tiger);
    rooms[7].setObjects(vec);
    rooms[7].setType(3);
    rooms[7].setThirstyDecrease(1);
    rooms[7].setHungerDecrease(2);
    //room8
    while(vec.size()>0) vec.pop_back(); while(tmp.size()>0) tmp.pop_back();
    Monster* Bear = new Monster("Bear", 500, 0, 50, 80);
    Item item1("daimond sword", 0, 0 , 40, 0);
    Chest* ch = new Chest(item1, "gold chest");
    vec.push_back(ch);
    vec.push_back(Bear);
    rooms[8].setObjects(vec);
    rooms[8].setType(3);
    rooms[8].setThirstyDecrease(1);
    rooms[8].setHungerDecrease(2);
    //room9
    while(vec.size()>0) vec.pop_back(); while(tmp.size()>0) tmp.pop_back();
    Item g("enchant sword", 0, 0, 40, 30);
    Item h("enchant shield", 0, 40, 0, 30);
    Item i("enchant apple", 80, 0 , 0, 30);
    tmp.push_back(g);
    tmp.push_back(h);
    tmp.push_back(i);
    rooms[9].setType(4);
    rooms[9].setThirstyDecrease(2);
    NPC* vendor1 = new NPC("Vendor", "I can help you enchant your weapon\n", tmp);
    vec.push_back(vendor1);
    rooms[9].setObjects(vec);
    //room 13
    while(vec.size()>0) vec.pop_back(); while(tmp.size()>0) tmp.pop_back();
    rooms[13].setType(4);
    rooms[13].setThirstyDecrease(2);
    Monster* desertKing = new Monster("desertKing", 800, 0, 50, 80);
    vec.push_back(desertKing);
    rooms[13].setObjects(vec);
    //room14
    while(vec.size()>0) vec.pop_back(); while(tmp.size()>0) tmp.pop_back();
    rooms[14].setType(4);
    rooms[14].setThirstyDecrease(2);
    Item item2("banana sword", 0, 0 , 100, 0);
    Chest* che1= new Chest(item2, "gold chest");
    vec.push_back(che1);
    rooms[14].setObjects(vec);
    //room10
    while(vec.size()>0) vec.pop_back(); while(tmp.size()>0) tmp.pop_back();
    rooms[10].setType(1);
    //room11
    Monster* Boss = new Monster("Boss", 2000, 0, 200, 0);
    vec.push_back(Boss);
    rooms[11].setObjects(vec);
}
void Dungeon::createPlayer(){
    printf("Please enter your name: ");
    string s;
    cin>>s;
    cout<<"\n";
    player = Player(s, 100, 10, 30, 150, 150, 10);
    //player = Player(s, 600, 150, 100, 150, 150, 100);
    //player.setKey();
    player.setTag("player");
}
void Dungeon::startGame(){
    cout<<"preparing game~~\n";
    createMap();
    createPlayer();
    player.setCurrentRoom(&rooms[0]);
    cout<<"Every time you move or fight with monster, your hunger and thirsty state will increase\n";
    cout<<"Try to find something to eat and to drink\n";
    cout<<"When you kill a monster, it may drop money. Buy some cool items with NPC\n";

    cout<<"";
}

Dungeon::Dungeon(){
    startGame();
}
void Dungeon::handleMovement(){
    Room* position = player.getCurrentRoom();
    if(position->getRightRoom()!=NULL){
        cout<<"1 move right\n";
    }
    if(position->getDownRoom()!=NULL){
        cout<<"2 move down\n";
    }
    if(position->getLeftRoom()!=NULL){
        cout<<"3 move left\n";
    }
    if(position->getUpRoom()!=NULL){
        cout<<"4 move up\n";
    }
    cout<<"5 stay\n";
    cout<<"\nEnter your choose:";
    int req;
    cin>>req;
    if(req==1){
        if(position->getRightRoom()==&rooms[10]){
            if(player.getKey()){
                player.setCurrentRoom(position->getRightRoom());
                cout<<"Use the Key to open the door\n";
            }
            else{
                cout<<"You have no key\n";
            }
        }
        else if(position->getRightRoom()!=NULL){
            player.setCurrentRoom(position->getRightRoom());
        }
        else{
            cout<<"No room there\n";
        }
    }
    else if(req==2){
        if(position->getDownRoom()!=NULL){
            player.setCurrentRoom(position->getDownRoom());
        }
        else{
            cout<<"No room there\n";
        }
    }
    else if(req==3){
        if(position->getLeftRoom()!=NULL){
            player.setCurrentRoom(position->getLeftRoom());
        }
        else{
            cout<<"No room there\n";
        }
    }
    else if(req==4){
        if(position->getUpRoom()!=NULL){
            player.setCurrentRoom(position->getUpRoom());
        }
        else{
            cout<<"No room there\n";
        }
    }
    else if(req==5){

    }
    else {
        cout<<"No room there/n";
    }
    if(position->getType()==3&&position->getType()==4){
        cout<<"You Hunger and Thirsty increase more\n";
    }
    position=player.getCurrentRoom();
    if(position == &rooms[3]){
        cout<<"Going into a swamp, you are poison\nTry to find some milk\n";
        player.setPoison(10);
    }
    if(position == &rooms[13]){
        cout<<"Sand storm!!!  \nYour thirsty increase 40\n";
    }

}

void Dungeon::handleEvent(Object* obj){
    if(obj->getTag()=="Npc"){
        obj->triggerEvent(&player);
    }
    else if(obj->getTag()=="Monster"){
        if(obj->triggerEvent(&player)){
            player.decreaseStates(10*player.getCurrentRoom()->getHungerDecrease(), 10*player.getCurrentRoom()->getThirstyDecrease());
        }
    }
    else if(obj->getTag()=="Chest"){
        obj->setTag("None");
        obj->triggerEvent(&player);
    }
}

void Dungeon::chooseAction(){

    Room* position = player.getCurrentRoom();
    cout<<"\n\nIn Room "<<position->getIndex()<<"  ";
    if(position->getType()==1) cout<<"(normal room)\n";
    else if(position->getType()==2) cout<<"(swamp)\n";
    else if(position->getType()==3) cout<<"(forest)\n";
    else if(position->getType()==4) cout<<"(desert)\n";
    cout<<"choose an action\n\n";
    cout<<"1 move\n";
    bool npc = false, monster = false, chest = false;

    for(Object* u: position->getObjects()){

        if(u->getTag()=="Npc"){
            npc=true;
        }
        else if(u->getTag()=="Chest"){
            chest =true;
        }
        else if(u->getTag() == "Monster"){
            monster=true;
        }
    }
    if(npc){
        for(Object* u: position->getObjects()){
            if(u->getTag()=="Npc"){
                cout<<"2 talk with NPC "<<u->getName()<<"\n";
                break;
            }
        }
    }
    if(monster){
        for(Object* u: position->getObjects()){
            if(u->getTag()=="Monster"){
               cout<<"3 fight the monster "<<u->getName()<<"\n";
                break;
            }
        }

    }
    if(chest){
        cout<<"4 open the chest \n";
    }
    cout<<"5 player status \n";
    if(position==&rooms[6]){
        cout<<"6 get some milk from the cow\n";
        cout<<"7 get some water from the lake\n";
    }
    if(position==&rooms[9]){
        cout<<"6 get some water from the Oasis\n";
    }
    if(position==&rooms[10]){
        cout<<"6 play an 1A2B game (may deal a lot of damage and cannot leave) \n";
    }
    int req;
    cout<<"\nEnter your choose : ";
    cin>>req;
    cout<<"\n\n";
    if(req==1){
        handleMovement();
        player.decreaseStates(10*position->getHungerDecrease(), 10*position->getThirstyDecrease());
    }
    else if(req==2){
        for(Object* u: position->getObjects()){
            if(u->getTag()=="Npc"){
                handleEvent(u);

            }
        }
    }
    else if(req==3){
        for(Object* u: position->getObjects()){
            if(u->getTag()=="Monster"){
                handleEvent(u);
            }
        }
    }
    else if(req==4){
        for(Object* u: position->getObjects()){
            if(u->getTag()=="Chest"){
                handleEvent(u);
            }
        }
    }
    else if(req==5){
        player.triggerEvent(&player);
    }
    if(position==&rooms[6]){
        if(req==6){
            cout<<"Acquire the milk !!!  You eliminate the poison\n";
            player.setPoison(0);
        }
        else if(req==7){
            cout<<"Acquire some water from the lake !!! You don't fell thirsty now\n";
            player.setThirsty(150);
        }
    }
    if(position==&rooms[9]){
        if(req==6){
            cout<<"Acquire some water from the Oasis !!! You don't fell thirsty now\n";
            player.setDebuff(false);
            player.setThirsty(150);
        }
    }
    if(position==&rooms[10]){
        if(req==6){
            cout<<"Welcome to 1A2B\n\nYou will -10 health for each guess and gain 150 health for the correct answer!\n";
            srand(time(NULL));
            int A[4];
            for(int i=0; i<4; i++){
                A[i]=rand()%9+1;
                for(int j=0; j<i; j++){
                    if(A[i]==A[j]){
                        i--;
                        break;
                    }
                }
            }
            //for(int i=0; i<4; i++) cout<<A[i];
            string s;
            while(1){
                cout<<"Health : "<<player.getCurrentHealth();
                cout<<"\nEnter the number(Eg: 1234) : ";
                cin>>s;
                int a=0;
                int b=0;
                for(int i=0; i<4; i++){
                    if(A[i]==s[i]-'0') a++;
                }
                for(int i=0; i<4; i++){
                    for(int j=0; j<4; j++){
                        if(i!=j&&s[i]-'0'==A[j]){
                            b++;
                        }
                    }
                }
                if(a==4){
                    cout<<"Congratulation!! You win 1A2B and gain 150 HP\n";
                    player.setCurrentHealth(150);
                    break;
                }
                else{
                    cout<<a<<'A'<<b<<"B\n";
                    cout<<"You -10 health\n";
                    player.setCurrentHealth(player.getCurrentHealth()-10);
                    if(player.getCurrentHealth()<=0){
                        cout<<"You died because of a fun game\n";
                        break;
                    }
                }
            }
        }
    }
}


bool Dungeon::checkGameLogic(){
    if(player.getCurrentHealth()<=0){
        cout<<"\nGameover!!!\n";
        return false;
    }
    if(rooms[11].getObjects()[0]->getTag()=="Died"){
        player.triggerEvent(&player);
        cout<<"\n\nYou win !!";
        return false;
    }
    return true;
}

void Dungeon::runDungeon(){
    while(1){
        chooseAction();
        if(!checkGameLogic()) break;
    }
}

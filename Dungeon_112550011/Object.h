#ifndef OBJECT_H_INCLUDED
#define OBJECT_H_INCLUDED

#include <iostream>
#include <string>
#include <vector>

using namespace std;
class Object
{
private:
    string name;
    string tag;
public:
    Object();
    Object(string,string);

    /* pure virtual function */
    virtual bool triggerEvent(Object*) = 0;
    virtual void increaseStates(int,int,int,int,int,int){
    }
    virtual int getm(){

    }
    virtual int getMP(){

    }
    virtual int getAtt(){

    }
    virtual int getDef(){

    }
    virtual int getHel(){

    }
    virtual void setHel(int){

    }
    virtual void setMP(int){

    }
    virtual void setPoi(int){

    }
    virtual void setKey(){

    }
    virtual void addItem(string){

    }
    virtual vector<string> getInventory(){
    }
    /* Set & Get function*/
    void setName(string);
    void setTag(string);
    string getName();
    string getTag();
};

#endif // OBJECT_H_INCLUDED

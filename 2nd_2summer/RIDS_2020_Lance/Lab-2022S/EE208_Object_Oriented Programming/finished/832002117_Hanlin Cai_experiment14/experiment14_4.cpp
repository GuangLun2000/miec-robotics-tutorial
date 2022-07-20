#include <iostream>
#include <cstring>
using namespace std;

/*
Calling the who() member for the derived class object indicates that 
the who() member is inherited in the two derived classes.
*/

class Animal
{
    protected:
    char name[20];
    int weight;

    public:
    Animal(char pname[] = "", int pweight = 0){
        strcpy(name, pname);
        weight = pweight;
    }
    void who() const {
        cout << "Name: " << name << endl;
        cout << "Weight: " << weight << endl;
    }

};

class Lion : public Animal{
    public:
    Lion(char pname[] = "", int pweight = 0){
        strcpy(name, pname);
        weight = pweight;
    }

};
class Aardvark : public Animal{
    public:
    Aardvark(char pname[] = "", int pweight = 0){
        strcpy(name, pname);
        weight = pweight;
    }

};

int main(){
    Lion lion("Leo",400);
    Aardvark aardvark("Algernon",50);

    lion.who();
    aardvark.who();
}

// Experiment 14 - 4
// This code is created by Hanlin Cai
// MU  number : 20122161
// FZU number : 832002117
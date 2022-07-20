
#include <iostream>
#include <cstring>
#include <stdlib.h>

using namespace std;

class Animal {
public:
    Animal(string theName, int wt);    // ¹¹ÔìÆ÷
    void who() const;

private:
    string name;
    int weight;
};

Animal::Animal(string theName, int wt) : name(theName), weight(wt) {}


void Animal::who() const {
    cout << "\nMy name is " << name << " and I weight " << weight << endl;
}


class Lion : public Animal {
public:
    Lion(string theName, int wt) : Animal(theName, wt) {}
};

class Aardvark : public Animal {
public:
    Aardvark(string theName, int wt) : Animal(theName, wt) {}
};

int main() {
    Lion lion1("Leo", 400);
    Aardvark aardvark1("Algernon", 50);

    lion1.who();
    aardvark1.who();
}

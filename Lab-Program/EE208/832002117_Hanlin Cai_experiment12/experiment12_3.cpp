#include <iostream>
using namespace std;

/*
Create a class named Toy, which includes four attributes: name, price, address, discount.
Create a Toy, enter a discount number, and display detailed Toy information after the discount.
*/

class Toy {
    private:
    string name;
    double realPrice;
    double discount;
    string address;

    public:
    void setinfo();
    void getName(string name1){ name = name1; }
    void getAddress(string address1){ address = address1; }
    void getDiscount(double y){ discount = y; }
    void getrealPrice(double x){ realPrice = x * discount; }


    void print();

};

void Toy::setinfo() {
    name = 1.0;
    address = 1.0;
    realPrice = 1.0;
    discount = 1.0;
}

void Toy::print() {
    cout << "------------------"<<endl;
    cout << "Name: " << name << endl;
    cout << "Address: " << address << endl;
    cout << "Real Price: " << realPrice << endl;
    cout << "------------------"<<endl;
}


int main() {

    Toy toy1;
    string name1,address1;
    double x,y;
    cout << "Please enter the name: ";
    cin >> name1;
    cout << "Please enter the address: ";
    cin >> address1;
    cout << "Please enter the orginal price: ";
    cin >> x;
    cout << "Please enter the discount: ";
    cin >> y;
    
    // toy1.setAndGet(name1, address1, x, y);
    toy1.setinfo();
    toy1.getName(name1);
    toy1.getAddress(address1);
    toy1.getDiscount(y);
    toy1.getrealPrice(x);
    toy1.print();


    return 0;
}
// Experiment 12 - 3
// This code is created by Hanlin Cai
// MU  number : 20122161
// FZU number : 832002117
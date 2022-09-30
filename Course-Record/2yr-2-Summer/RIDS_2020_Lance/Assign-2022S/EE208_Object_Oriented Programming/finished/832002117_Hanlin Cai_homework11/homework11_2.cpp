#include <iostream>
using namespace std;

/*
the data member elNum is used to store the elevator’s number, 
the data member currentFloor is used to store the elevator’s current floor position, 
and the data member highestFloor is used to store the highest floor the elevator can reach.
*/

class Elevator {
    private:
    int elNum; // elevator number
    int currentFloor; // current floor
    int highestFloor; // highest floor
    int requestFloor; // request floor
    
    public:
    // Elevator(int = 1, int = 1, int =15); //constructor
    void setElevator(int i, int j, int k);
    void request(int l);
};

void Elevator::setElevator(int i,int j,int k) {
    elNum = i;
    currentFloor = j;
    highestFloor = k;

}

void Elevator::request(int l) {
    requestFloor = l;
    if(requestFloor < 0 || requestFloor > highestFloor || requestFloor == currentFloor) {
        cout << "Wrong Input" << endl;
    } else {
        if (requestFloor > currentFloor)
        {
            cout << "Now! Current Floor : " << currentFloor << endl;
            
            while(requestFloor > currentFloor){
                currentFloor ++;
                cout << "Current Floor : " << currentFloor << endl;
            }
            cout << "End! Current Floor : " << currentFloor << endl;
        } else {
            cout << "Now! Current Floor : " << currentFloor << endl;
            while (requestFloor < currentFloor) {
                currentFloor --;
                cout << "Current Floor : " << currentFloor << endl;
            }
            cout << "End! Current Floor : " << currentFloor << endl;
        }
        
    }
}


int main() {
    Elevator ele1;
    int i, j, k, l;
    cout << "Please enter the elNum, currentFloor and the highestFloor : ";
    cin >> i >> j >> k;
    cout << "Please enter the request floor: ";
    cin >> l;
    ele1.setElevator(i, j, k);
    ele1.request(l);

    return 0;
}
// Homework 11 - 2
// This code is created by Hanlin Cai
// MU  number : 20122161
// FZU number : 832002117
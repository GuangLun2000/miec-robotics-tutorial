#include <iostream>
using namespace std;

/*
Create a Rectangle, set a set of correct length and width and a set of wrong length and width, 
verify and output the perimeter and area.
*/

class Rectangle{
    private:
    double m_length;
    double m_width;
    double perimeter;
    double area;
    
    public:
    bool setWidth(double width);
    bool setLength(double length);
    void getWidth(double width) { m_width = width; }
    void getLength(double length) { m_length = length; }
    void calc();

};

bool Rectangle::setWidth(double width) {
    m_width = 1.0;
    if(width >= 0 && width <= 20){
        return 1;
    } else {
        return 0;
    }
}

bool Rectangle::setLength(double length) {
    m_length = 1.0;
    if(length >= 0 && length <= 20){
        return 1;
    } else {
        return 0;
    }
}


void Rectangle::calc() {
    perimeter = 2*(m_width + m_length);
    area = m_width * m_length;
    cout << "Perimeter = " << perimeter << endl;
    cout << "Area = " << area << endl;
}


int main() {
    Rectangle rect1;
    double width, length;
    cout << "Please enter the width and length: ";
    cin >> width >> length;

    if(rect1.setWidth(width) && rect1.setLength(length)) {
        rect1.getLength(width);
        rect1.getWidth(length);
        rect1.calc();
    } else {
        cout << "Wrong Input!!" << endl;
    }


    return 0;
}
// Experiment 12 - 4
// This code is created by Hanlin Cai
// MU  number : 20122161
// FZU number : 832002117
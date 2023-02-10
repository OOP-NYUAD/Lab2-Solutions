/*Create a class called Point to store (x , y) coordinates. Define operator overloading 
for +, - , = and = =  operators for Point class. Test your class with several test 
cases of Point class instances.*/
#include <iostream>

using namespace std;

class Point{
    int x, y;

public: 
    Point(int x = 0, int y = 0){
        this->x = x;
        this->y = y;
    }

    // defining the copy constructor does the same thing as overloading the assignment ('=') operator 
    Point(const Point &obj){
        cout << "Just to be sure\n";
        this->x = obj.x;
        this->y = obj.y;
    }

    Point operator +(const Point &obj){
        return Point(this->x + obj.x, this->y + obj.y);
    }

    Point operator -(const Point &obj){
        return Point(this->x - obj.x, this->y - obj.y);
    }

    bool operator ==(const Point &obj){
        return (this->x == obj.x && this->y == obj.y);
    }

    void print(){
        cout << '(' << x << ", " << y << ")\n";
    }
};

int main(){
    Point p1(1, 2), p2(1, 2), p3;

    /*Testing the == operator first*/
    p1 == p2 ? cout << "Same point\n" : cout << "Different point\n";

    /*Testing the +*/
    (p1 + p2).print();

    /*Testing the -*/
    (p1 - p2).print();

    /*Testing the =*/
    p3 = p1;
    p3.print();

    return 0;
}
#include <iostream>

using namespace std;


/*Another thing about abstract data types is that you can overload the arithmetic operators
to do other things that make sense in the context of the object. For example, if you have a
Point or 2DVector class, you can define the '+' operator to add the x values and y values
respectively and return another Point object.*/

class myClass{
private:
    int num1;
    int num2;

public:
    myClass(int a = 0, int b = 0){
        num1 = a;
        num2 = b;
    }


    int getNum1(){ return num1; }
    int getNum2(){ return num2; }

    // syntax for overloading operators is
    // return type operator operator_to_overload(const myClass &obj)

    void operator +=(const myClass &obj){
        this->num1 += obj.num1;
        this->num2 += obj.num2;
    } 

    myClass operator *(const myClass &obj){
        myClass object(this->num1 * obj.num1, this->num2 * obj.num2);
        return object;
    }
};

int main(int argc, char *argv[]){
    myClass obj1(1, 2), obj2(4, 6);

    obj1 += obj2;

    cout << obj1.getNum1() << ' ' << obj1.getNum2() << '\n';

    myClass obj3 = obj1 * obj2;

    cout << obj3.getNum1() << ' ' << obj3.getNum2() << '\n';

    return 0;
}
/*Create a simple class MyInt that holds an integer pointer to a value. Implement 
the copy constructor so a new instance should have a distinct copy of int* member 
variable (“val” should have different address in memory).*/
#include <iostream>

using namespace std;

class myInt{
    int *ptr;

public:
    myInt(int num = 0){
        ptr = new int(num);
    }

    myInt(myInt &obj){
        this->ptr = new int(*obj.ptr);
    }

    ~myInt(){
        delete ptr;
    }

    void print(){
        cout << "Value of number is: " << *ptr << '\n'
             << "Value is stored in address: " << ptr << '\n';
    }
};

int main(){
    myInt obj1(5);
    
    myInt obj2 = obj1;

    obj1.print();
    obj2.print(); // to verify that the addresses are different

    return 0;
}
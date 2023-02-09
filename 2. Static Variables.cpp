#include <iostream>

using namespace std;

class myClass{
private:
    // You can define a "static" member that is associated with all objects in a class
    // syntax is simple:

    static int myStaticMember;  // all instances of the class can refer to this same variable
                                // a common use for static variables is unique identifiers

    // lets say I have a private member "ID" that has to be unique and sequential to all objects
    int ID;

public:
    myClass(){
        ID = myStaticMember++; // set ID to current value to the static variable and increment the variable 
    }

    // lets also make a getter for the ID
    int getID(){ return ID; }

    // we can also have static functions. These cannot have any reference to any non-static memebrs
    static int getMyStaticMember(){ return myStaticMember; }
};

// static membrs must be initialized outside the class
int myClass::myStaticMember = 0;

int main(int argc, char *argv[]){

    // lets make some objects in an array
    myClass arr[10];    // Important note: when declaring objects like this, the default 
                        // constructor is called n times where n is the size of the array

    for(int i = 0; i < 10; i++){
        cout << "Object " << i << " ID is: " << arr[i].getID() << '\n';
    }

    // One can call a static function in one of two ways:

    // through any object using the dot operator
    cout << arr[2].getMyStaticMember() << '\n';

    // or through the class itself
    cout << myClass::getMyStaticMember() << '\n';

    return 0;
}
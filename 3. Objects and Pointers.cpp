#include <iostream>
#include <iomanip>

using namespace std;

class myClass{
private:
    int i;

public:
    myClass(int i = 0){
        this->i = i; // the 'this' keyword returns a pointer to the current object
    }

    int getNum(){ return this->i; }
    
    myClass *getRef(){ return this; }
};

int main(int argc, char *argv[]){
/*In this lab, we will talk about 
    - dynamic memory allocation for objects
    - how pointers to object differ in syntax
    - the "this" keyword
*/
    myClass *ptr = new myClass(3);  // using the "new" keyword, I can call the constructor (with an initial parameter 3)
                                    // now ptr is a poniter to the new object.


    // I can refer to member functions of the object through the pointer by using the arrow (->) operator
    cout << "stored integer in object is: " << ptr->getNum() << '\n';

    // so instead of the normal dot (.) operator, we use the arrow for pointer. The arrow is equivalent to:
    cout << "stored integer in object is: " << (*ptr).getNum() << "\n\n"; // syntax wise this is stupid so we use the arrow

    // Now that we don't need the object stored in ptr, I will delete the pointer
    delete ptr;


    /*As was mentioned above, the "this" keyword returns a pointer to the object currently in use. This means that if 
    object A called a member function, when executing that code, the "this" keyword will return a pointer to object A.
    To demonstrate this, I will do the following: */

    // first I will create an object
    myClass myObj(2);

    cout << "my object is stored in memory location: " << setw(44) <<&myObj << '\n';
    cout << "the \"this\" keyword refers to this memory when invoked from my object: " << myObj.getRef() << "\n\n";

    cout << "Are they identical? Also, is this proof/explanation enough?\n";

    return 0;
}
#include <iostream>

using namespace std;

class myClass{
private:
    int *myArr;

public:
    myClass(int size = 5){
        myArr = new int[size];
        cout << "memory allocated.\n";
        for(int i = 0; i < size; i++){
            myArr[i] = 0;
        }
    }

    /*in a nice symmetry offered by cpp, just like there are constructors there are destructors
    when an object goes out of scope or is deleted, the memory allocated for it is deallocated
    and that is about it. However, if we want something special to happen, we can define our
    own destructor. Also important. If you do any dynamic memory allocation in your class, the
    memory must be deallocated in a destructor as the deafult destructor only deallocates the 8
    bytes for the pointer.*/
    ~myClass(){
        delete[] myArr;
        cout << "Memory deallocated successfully.\n";
    }
};

int main(int argc, char *argv[]){

    // I'll create a local scope and create an object inside
    {
        myClass obj1(6);
    }
    cout << "Was the memory deallocated?\n";

    return 0;
}
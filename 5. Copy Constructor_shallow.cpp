#include <iostream>

using namespace std;

class shallow{
private:
    int *arr;
    int size;
public:
    shallow(int i = 5){
        size = i;
        arr = new int[size];
        for(int i = 0; i < size; i++){
            arr[i] = i*i;
        }
    }

    int *getArray(){ return arr; }
    void printArray(){
        for(int i = 0; i < 5; i++){
            cout << arr[i] << ' ';
        }

        cout << '\n';
    }

    ~shallow(){
        delete[] arr;
    }
};

int main(int argc, char *argv[]){
    shallow obj1;
    
    obj1.getArray()[0] = 0;
    obj1.getArray()[1] = 1;
    obj1.getArray()[2] = 2;
    obj1.getArray()[3] = 3;
    obj1.getArray()[4] = 4; // setting the array value

    // performing a shallow copy
    shallow obj2 = obj1;

    // What is the expected output here?
    obj2.printArray();

    // let's try changing something
    obj2.getArray()[3] = 5;

    // What's the expected output here?
    obj1.printArray();

    return 0;
}
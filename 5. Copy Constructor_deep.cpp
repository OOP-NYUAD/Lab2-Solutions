#include <iostream>

using namespace std;

class deep{
private:
    int *arr;
    int size;
public:
    deep(int i = 5){
        size = i;
        arr = new int[size];
        for(int i = 0; i < size; i++){
            arr[i] = i*i;
        }
    }
    // unlike in the last file, we will define a copy constructor now
    // so we can perform a deep copy
    deep(const deep &obj){
        this->size = obj.size;
        this->arr = new int[size];
        for(int i = 0; i < size; i++){
            arr[i] = obj.getArray()[i];
        }
    }

    int *getArray() const{ return arr; }

    void printArray(){
        for(int i = 0; i < 5; i++){
            cout << arr[i] << ' ';
        }

        cout << '\n';
    }


    ~deep(){
        delete[] arr;
    }
};

int main(int argc, char *argv[]){
    deep obj1;

    // performing a deep copy
    deep obj2 = obj1;

    // let's try changing something
    obj2.getArray()[3] = 5;
    
    // What's the expected output here?
    cout << "Object 1 values:\n";
    obj1.printArray();

    cout << "Object 2 values:\n";
    obj2.printArray();

    return 0;
}
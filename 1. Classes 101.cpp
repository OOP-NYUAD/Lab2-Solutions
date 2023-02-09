#include <iostream>
#include <string>

using namespace std;

/*object oriented programming is what makes c++ better then c that only has structures and no classes
What does that mean? Hardly matters. Just know that classes can be used to define "abstract" data types.
abstract, in the sense that an instance of an object can have any attribute and functionality you define.*/

// let's go over basic syntax

class className{
private:    // this is an access specifier. As the name suggests, it specifies who can access the class member
            // a private member can only be accessed by member functions.
            // Usually, private members are variables.
            // by default, the access specifier is private (if a member element doesn't have a specifier it is
            // assumed to be private)

    int memberA, memberB;
    char memberC;
    string memberD; // member elements can even be objects from other classes.

public:     // this is another access specifier. Public members can be accessed by both member and non-member functions
            // Usually, public members are functions.

/*
    className(){    // this is a constructor. Constructor functions are called when an instance of the object is created
                    // a constructor with no input arguemnts is a "default" constructor. This sets all initial values
                    // if the user did not provide any values themselevs

        memberA = 0;
        memberB = 0;
        memberC = '0';
        memberD = "";
    }

    className(int a, int b, char c, string d){ // a non default constructor takes in arguments to set the intial values
        memberA = a;
        memberB = b;
        memberC = c;
        memberD = d;
    }
*/

    // Both defaul and non default constructors can be combined into one function using the following syntax
    className(int a = 0, int b = 0, char c = '0', string d = ""){
        memberA = a;
        memberB = b;
        memberC = c;
        memberD = d;
    } 

    // getters: since the member elements are private and can only be accessed by member functions
    // we make these so called getters. These can also mediate access to the member elements
    int     getA(){ return memberA; }
    int     getB(){ return memberB; } 
    char    getC(){ return memberC; }
    string  getD(){ return memberD; }

    // setters: again, since member elements are private and can only be accesed by member functions
    // we make setters to set the values as per the user's input. We can also do input validation on
    // the user input before we set anything.

    void setA(int a){
        memberA = a;
    }

    // for example, lets say memberB can only be a poisitive number, we can ensure that that rule is
    // followed in our setter function
    void setB(int b){
        if(b <= 0) return; // return without actually changing memberB
        else memberB = b;
    }

    void setC(char c){
        memberC = c;
    }

    void setD(string d){
        memberD = d;
    }

    // You can also declare any function you want that pertains to the object
    // I will make a print function that prints the values of all member elements

    void print(){
        cout << "Member A: " << memberA << '\n';
        cout << "Member B: " << memberB << '\n';
        cout << "Member C: " << memberC << '\n';
        cout << "Member D: " << memberD << '\n';

    }

}; // you have to put a semi-colon after the curly brace

int main(int argc, char *argv[]){

    // Here's how you make an instance of an object
    // type the classname and the name of the variable
    // it's identicial to creating any variable. i.e.:
    // <variable type> <variable name>

    className myObject1; // since no arguments were passed, the default constructor was called

    className myObject2(1, 2, '3', "four"); // here the non default constructor was called
    
    className myObject3(1, 2, '9'); // here the non-default constryctor was called as well
                                    // however, a different one then on line 104. since our
                                    // constructor made 5 different overloaded constructors

    // to call a member function, we can use the dot (.) operator:
    myObject1.print();
    myObject2.print();
    myObject3.print();


    return 0;
}
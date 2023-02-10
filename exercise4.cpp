/*Create a class Player including a copy constructor to create new Player instance 
with initial values from another Player instance. A Player class should maintain 
the name, age, score and health information of the player. Create test 
instances of Player and verify the copy construction operation.*/

#include <iostream>
#include <string>

using namespace std;

class Player{
    string name;
    int age, score;
    float health;

public:
    Player(string name = "Majida El Roumi", int age = 23, int score = 0, float health = 100){
        this->name   = name;
        this->age    = age;
        this->score  = score;
        this->health = health;
    }

    Player(Player &obj){
        this->name   = obj.name;
        this->age    = obj.age;
        this->score  = obj.score;
        this->health = obj.health;
    }

    void print(){
        cout << "Player name: "   << name << '\n'
             << "Player age: "    << age  << '\n'
             << "Player score: "  << score << '\n'
             << "Player health: " << health << '\n';
    }

};

int main(){
    Player p1("Ahmad", 23, 999, 100);
    p1.print();

    Player p2(p1); // one way of calling the copy constructor
    p2.print();

    Player p3 = p1; // another way of calling the copy constructor
    p3.print(); 

}
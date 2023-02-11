/*Linked list is one of the most important data structure. A linked list is a data 
structure that can store an indefinite amount of items. These items are connected 
using pointers in a sequential manner. A linked list is made up of many nodes which 
are connected in nature. Each node in linked list has two parts, one part is to hold 
the data in the node and the other part contains the address of the next node in the 
list. The first node in the list is called ‘head’ node and the last node is called 
the ‘tail’. Note that the last node doesn’t point to any other node and just stores 
null. The nodes are linked using pointers as shown in the image:*/

/*
    - Create a class called ‘Node’ with two public members: data (int) and Node *next.
    - Create a class called ‘Linked_List’ which will contain all the data members and 
      functions required for a linked list.
    - Create constructor for ‘Linked_List’ to initialize head and tail pointers to null.
    - Maintain two private data members *head and *tail pointers to store addresses of 
      head and tail nodes in the linked list.
    - Create a public function ‘Insert_Node(int data)’ to add a new node to linked list. 
      Note: maintain head and tail nodes appropriately.
    - Create a public function ‘Display_List()’ to display the contents stored in the 
      linked list.
    - Now, extend the functionality of ‘Linked_List’ class to add some more member 
      functions:
        > Create a function called ‘Insert_Front(int data)’ to add node at the front of 
          the linked list.
        > Create a function called ‘Insert_At(int position, int data)’ to add a new node 
          at a particular position in a linked list. 
        > Create a function called ‘Delete_First(),Delete_Last()and 
          Delete_At(int position)’ to delete the first node, the last node or delete the 
          node at a particular position from the list respectively. Maintain head and 
          tail pointers accordingly.
*/

/*Note that if you do this exercise, it will only be a bonus to the lab grade, not your overall
score. The bonus points will be transferable to other labs as well. The exercise is worth 3 points*/

#include <iostream>
#include <assert.h>

using namespace std;

/*Node objects are very simple, they have the stored data, in this case its an integer but it could be
generalized to a template class (more on that later on in the course). The node object also contains
a reference to the next node in the list (this is a single linked list)*/

u_int NumOfNodesCreated = 0;
u_int NumOfNodesDeleted = 0;  // I will use these two to keep track of memory usage

class Node{
  int data;
  Node *next;


public:
  Node(int data = 0, Node *next = nullptr){
    this->data = data;
    this->next = next;

    NumOfNodesCreated++;
  }

  int getData()   { return data; }
  Node* getNext() { return next; }
  
  void setValue(int data)  { this->data = data; }
  void setNext(Node *next) { this->next = next; } // You can make setters or make the data and next variables public

  ~Node(){
    NumOfNodesDeleted++;
  }
};


/*A linked list object keeps track of the haed and tails of the list. The list grows in the direction of 
the head. Initially, both head and tail pointers point to nothing, then to a single Node, afterwards, the
more the list grows, the head points at the latest added node and the tail points at the first node created*/
class List{
  Node *head, *tail;

public:
  /*The constructor makes an empty list. Nodes are then added to the list by insert functions*/
  List(Node *first = nullptr){
    this->head = first;
    this->tail = first;
  }

  /*This is "Insert_front()" function, it's typically called push_front (there's also a push_back())*/
  /*the "front" of the linked list is where the head is pointing to*/
  void push_front(int data){
    Node *ptr = new Node(data); // First we make the new node (still unconnected)

    if(!head && !tail){   // if the list is empty (both head and tail are null pointers)
      head = ptr;         // we point both head and tail to the new pointer
      tail = ptr;
    }
    else{                 // in all other cases, we do the same thing
      head->setNext(ptr);
      head = ptr;
    }
  }

  /*The "back" of the linked list is where the tail is pointing to*/
  void push_back(int data){
    Node *ptr = new Node(data); // First we make the new node (still unconnected)

    if(!head && !tail){   // if the list is empty (both head and tail are null pointers)
      head = ptr;         // we point both head and tail to the new pointer
      tail = ptr;
    }
    else{                 // in all other cases, we do the same thing
      ptr->setNext(tail);
      tail = ptr;
    }
  }

  void insert_at(u_int pos, int data){
    if(pos == 0){
      push_back(data);
      return;
    }


    int i = 1;          // this will serve as out current position indiciator.
                        // we insert the new node when i == pos

    Node *temp = tail;
    while(temp){
      if(i++ == pos){                     // when we get to our desired position, insert node
        if(head == temp){                 // if we get to the end of the list, we can use push_front()
          push_front(data);
        }
        else{                               // otherwise, we do it manually
          Node *ptr = new Node(data);       // again, we make the new pointer
          ptr->setNext(temp->getNext());    // set the new node's next pointer
          temp->setNext(ptr);               // link previous node to new node
        }

        return;
      }
      temp = temp->getNext();             // move temp pointer to next node if we're still not there
    }

    if(!temp){
      cout << "Index provided is out of bounds of the linked list\n";
      return;
    }
  }

  /*Printing the list. Whenever you traverse a linked list, make sure to store the reference
  to either the head or tail to a temporary value as to not mess with the pointers*/
  void display_list() const{
    Node *temp = tail;
    while(temp){
      cout << temp->getData() << ' ';
      temp = temp->getNext();
    }
    cout << '\n';
  }

  /*Remove the current head node*/
  void pop_front(){
    Node *temp = tail;

    /*traverse the list until you get to the second to last node*/
    while(temp->getNext()->getNext()){
      temp = temp->getNext();
    }

    /*delete last node*/
    delete temp->getNext();

    /*next node for the last node in the list is the null pointer*/
    temp->setNext(nullptr);

    /*reset the head variable*/
    head = temp;
  }

  /*Remove the current tail node*/
  void pop_back(){
    Node *temp = tail;      // keep reference to tail
    tail = tail->getNext(); // reset tail to next node over
    delete temp;            // delete previous tail node
  }

  void delete_at(u_int pos){
    if(pos == 0){
      pop_back();
      return;
    }

    int i = 1;          // this will serve as out current position indiciator.
                        // we insert the new node when i == pos

    Node *temp = tail;
    while(temp){
      if(i++ == pos){
        if(temp->getNext() == head){
          pop_front();
          return;
        }
        else{
          Node *toDelete = temp->getNext();
          if(!toDelete){
            cout << "Index provided is out of bounds of the linked list\n";
            return;
          }
          temp->setNext(temp->getNext()->getNext());
          delete toDelete;
        }
        return;
      }
      temp = temp->getNext();
    }

    if(!temp){
      cout << "Index provided is out of bounds of the linked list\n";
      return;
    }
  }
  

  ~List(){
    Node *lag = tail;
    Node *current = tail->getNext();

    while(lag){
      delete lag;
      lag = current;
      if(current) current = current->getNext();
    }

    assert(NumOfNodesCreated == NumOfNodesDeleted); // If all was done correctly, these two numbers must be equal
  }

};


int main(){
  List l;

  l.push_front(0);
  l.push_front(1);
  l.push_front(2);
  l.push_front(3);
  l.display_list();

  l.push_back(-1);
  l.push_back(-2);
  l.display_list();

  l.insert_at(0, -3);
  l.insert_at(7, 4);
  l.display_list();

  l.pop_back();
  l.pop_back();
  l.pop_back();
  l.display_list();

  l.pop_front();
  l.display_list();

  l.insert_at(2, 99);
  l.display_list();
  l.delete_at(2);
  l.display_list();

  return 0;
}
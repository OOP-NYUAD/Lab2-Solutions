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
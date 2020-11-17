#include <iostream>
using namespace std;

//A circular list is where the last node in the list points back to the first node
//isCircularList tests whether a list is well-formed or a circular list.

struct Node {
    int data;
    Node * next;
    Node(int item); // create a Node with the given value and NULL next field
    // create a Node with the given data value (item) and next field 
    Node(int item, Node * n);
};
Node::Node(int item) {
   data = item;
   next = NULL;
}
Node::Node(int item, Node *n) {
   data = item;
   next = n;
}
typedef Node * ListType;

// returns true iff list is a circular list
// PRE: list has at least one node and is either a well-formed linked list
// or a circular list
bool isCircularList(Node * list) {
    ListType p = list;
    //traverse to last element (where p->next is NULL or points back to first element)
    while(p->next != NULL && p->next != list){
        p = p->next;
    }
    if(p->next == NULL) {
        return false;
    } else {
        return true;
    }
}

int main() {
    //create a circular linked list
    ListType testList1 = new Node(5, new Node(9, new Node(4)));
    ListType p = testList1;
    while(p->next != NULL){
        p = p->next;
    }
    //update to point to start of list
    p->next = testList1;
    cout << isCircularList(testList1) << endl;

    //create another circular linked list
    ListType testList2 = new Node(5);
    testList2->next = testList2;
    cout << isCircularList(testList2) << endl;

    //create a non circular linked list
    ListType testList3 = new Node(5, new Node(9, new Node(4)));
    cout << isCircularList(testList3) << endl;
}
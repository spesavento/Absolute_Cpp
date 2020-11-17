#include <iostream>
using namespace std;

//Two methods - removeLast1 and removeLast2, remove the last Node in a linked list.
//in removeLast1, (1) cannot be removed,
//in removeLast2, (2) and (3) can be swapped

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

void printList(ListType list) {
    ListType p = list;
    while(p != NULL) {
        cout << p->data << " ";
        p = p->next;
    } 
}

void removeLast1(ListType & list) {
    if(list == NULL) {
        return;
    }
    if(list->next == NULL){
        delete list;
        list = NULL;
        return;
    }
    Node * p = list;

    while(p->next->next != NULL) {
        p = p->next;
    }
    delete p->next;
    p->next = NULL;  //(1)
    //cout << p->next->data;
}

// PRE: list is a well-formed linked list
// this version uses two pointers for traversal
void removeLast2(ListType & list) {
     if (list == NULL) { // no elements in list
        return;
     }
     if (list->next == NULL) { // one element in list
        delete list;
        list = NULL;
        return;
     }

     Node * prev = list;
     Node *curr = list ->next;
     while (curr->next != NULL) {
        prev = curr;
        curr = curr->next;
     }
     delete curr; // (2)
     prev->next = NULL; // (3)
}

int main() {
    //create a list 
    ListType testList1 = new Node(1, new Node(2, new Node(3, new Node(4))));
    printList(testList1);
    cout << endl;
    removeLast1(testList1);
    printList(testList1);
    cout << endl;

    //create a list 
    ListType testList2 = new Node(1, new Node(2, new Node(3, new Node(4))));
    printList(testList2);
    cout << endl;
    removeLast2(testList2);
    printList(testList2);
    cout << endl;
}

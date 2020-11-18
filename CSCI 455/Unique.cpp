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

bool allUnique(ListType list){
    //if list is NULL or only one element, return true
    if(list == NULL || list->next == NULL){
        return true;
    }
    ListType p = list;
    ListType check = list;
    while(p != NULL){
        check = p->next;
        while(check != NULL){
            if(p->data == check->data){
                return false;
            } else {
                check = check->next;
            }
        }
        p=p->next;
    }
    return true;
}

int main(){
    ListType testList0 = NULL;
    cout << allUnique(testList0) << endl;

    ListType testList1 = new Node(1);
    cout << allUnique(testList1) << endl;

    ListType testList2 = new Node(3, new Node(2, new Node(1)));
    cout << allUnique(testList2) << endl;

    ListType testList3 = new Node(1, new Node(1, new Node(1)));
    cout << allUnique(testList3) << endl;

    ListType testList4 = new Node(3, new Node(2, new Node(3)));
    cout << allUnique(testList4) << endl;

    ListType testList5 = new Node(4, new Node(3, new Node(7, new Node(3, new Node(4, new Node(5))))));
    cout << allUnique(testList5) << endl;
}
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

void printList(ListType list) {
    ListType p = list;

    while(p != NULL) {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

void compress(ListType & list) {
    //if it's NULL or only one element, stays the same
    if(list != NULL && list->next != NULL){
        ListType p = list->next;
        ListType lag = list;
        int currVal = p->data;

        //iterate through last element 
        while(p->next != NULL){
            //if p is the same as the last, we want to delete it
            if(p->data == lag->data){
                lag->next = p->next;
                delete(p);

                //update pointer p (lag and currVal stay same)
                p = lag->next;

            } else {
                //if data is not the same, update the currVal and pointers
                lag = p;
                p=p->next;
                currVal = lag->data;
            }
        }
        //if last element is same as currVal, delete
        if(p->data == currVal){
                lag->next = p->next;
                delete(p);

                //update pointer p (lag and currVal stay same)
                p = NULL;
        }
    }
}

int main() {
    ListType myList0 = NULL;
    compress(myList0);
    printList(myList0);

    ListType myList1 = new Node(1);
    compress(myList1);
    printList(myList1);

    ListType myList2 = new Node(3, new Node(2, new Node(1)));
    compress(myList2);
    printList(myList2);

    ListType myList3 = new Node(1, new Node(1, new Node(1)));
    compress(myList3);
    printList(myList3);

    ListType myList4 = new Node(3, new Node(2, new Node(2, new Node(3))));
    compress(myList4);
    printList(myList4);

    ListType myList5 = new Node(2, new Node(2, new Node(3, new Node(3, new Node(3, new Node (3, new Node(1, new Node(2, new Node (2)))))))));
    compress(myList5);
    printList(myList5);


}

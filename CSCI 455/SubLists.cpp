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

void splice(ListType & list, int value, ListType subList){

	//if empty list
	if(list == NULL){
		list = subList;
		return;
}
//if empty sublist 
if(subList == NULL){
	return;
}
//if inserting at the front of the list
if(value == 0) {
	//iterate through sublist and connect last element to start of list, update list pointer 
	ListType p = subList;
	while(p->next != NULL){
		p = p->next;
	}
	p->next = list;
	list = subList;
} else {
	//else if inserting in middle or end, iterate first through list to find location
	ListType l = list;
	ListType lag = l;

	int index = 0;
while(index < value && l != NULL){
	index++;
	lag = l;
	l = l->next;
}
//if(l is null), you are inserting at the end
if(l == NULL){
	lag->next = subList;
} else {
//else inserting in middle, connect the subList between lag and l
	lag->next = subList;  //connect front to list
	ListType sub = subList;
	while(sub->next != NULL){
		sub = sub->next;
	}
	sub->next = l; ///connect end to list
}

}
}

int main(){
    //create a list 
    ListType list1 = new Node(2, new Node(3, new Node(8, new Node(3, new Node(9)))));
    ListType splice1 = new Node(6, new Node(6, new Node(6)));
    splice(list1, 2, splice1);
    printList(list1);

    ListType list2 = NULL;
    ListType splice2 = new Node(6, new Node(6, new Node(6)));
    splice(list2, 0, splice2);
    printList(list2);

    ListType list3 =new Node(8, new Node(7, new Node(5)));
    ListType splice3 = new Node(6, new Node(6, new Node(6)));
    splice(list3, 0, splice3);
    printList(list3);

    ListType list4 =new Node(8, new Node(5));
    ListType splice4 = new Node(1, new Node(2));
    splice(list4, 2, splice4);
    printList(list4);

    ListType list5 =new Node(8, new Node(5));
    ListType splice5 = NULL;
    splice(list5, 1, splice5);
    printList(list5);
}
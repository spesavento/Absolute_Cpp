
#include <iostream>
using namespace std;

struct Node {
    string data;
    Node * next;
    Node(string item); // create a Node with the given value and NULL next field
    // create a Node with the given data value (item) and next field 
    Node(string item, Node * n);
};
Node::Node(string item) {
   data = item;
   next = NULL;
}
Node::Node(string item, Node *n) {
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

void gut(ListType & list) {
	
	//if list not empty and over one element, remove middle elements
	if(list != NULL && list->next != NULL) {
		ListType tmp = list->next;
		ListType del = list->next;

		while(tmp->next != NULL) {
			delete del;
			del = NULL;
			tmp = tmp->next;
			del = tmp;
}
//update links 
list->next = tmp;
}
}

int main() {
    ListType myTestList = new Node("the", new Node("big", new Node("sloppy", new Node("dog"))));
    gut(myTestList);
    printList(myTestList);
    cout << endl;

    ListType myTestList2 = new Node("the", new Node("dog"));
    gut(myTestList2);
    printList(myTestList2);
    cout << endl;

    ListType myTestList3 = new Node("the");
    gut(myTestList3);
    printList(myTestList3);
    cout << endl;

    ListType myTestList4 = new Node("the", new Node("wet", new Node("dog")));
    gut(myTestList4);
    printList(myTestList4);
    cout << endl;

    ListType myTestList5 = NULL;
    gut(myTestList5);
    printList(myTestList5);
    cout << endl;
}
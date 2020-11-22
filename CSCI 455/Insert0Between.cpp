#include <iostream>
using namespace std;

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
void insert0Between(ListType & list) {
	ListType p = list;

	//if the list is greater than 1 element (otherwise do nothing)
	if(p != NULL && p->next != NULL) {
		//go until the second to last
		while(p->next != NULL) {
			//create a new Node with 0
			ListType tmp = new Node(0);
			//connect it 
			tmp->next = p->next;
			p->next = tmp;

			//update iteration (and skip past this 0)
			p = p->next->next;
		}

	}

}
int main() {
    ListType testlist1 = new Node(3, new Node(7));
    insert0Between(testlist1);
    printList(testlist1);

    ListType testlist2 = new Node(12, new Node(5, new Node(9, new Node(9))));
    insert0Between(testlist2);
    printList(testlist2);

    ListType testlist3 = new Node(0, new Node(0, new Node(0)));
    insert0Between(testlist3);
    printList(testlist3);

    ListType testlist4 = NULL;
    insert0Between(testlist4);
    printList(testlist4);

    ListType testlist5 = new Node(3);
    insert0Between(testlist5);
    printList(testlist5);
}
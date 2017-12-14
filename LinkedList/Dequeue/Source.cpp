#include<iostream>
#define size 100
using namespace std;
struct node {
	int info;
	node* next;
};
class LinkedList
{
	node* list;
public:
	LinkedList() { list = NULL; }
	node* createnode();
	void freenode(node* p);
	void insertFirst(int value);
	void insertLast(int value);
	void insertPosition(int value,int pos);
	void printLinkedList();
	void reverse();
	int search(int value);

};
node* LinkedList::createnode()
{
	node* p = new node;
	return p;
}
void LinkedList::freenode(node* p)
{
	delete p;
}
void LinkedList::insertFirst(int value)
{
	node*p = createnode();
	p->info = value;
	if (list == NULL)
	{
		list = p;
		p->next = NULL;
		return;
	}
	p->next = list;
	list = p;
}
void LinkedList::insertLast(int value)
{
	node* p = createnode();
	p->info = value;
	p->next = NULL;
	if (list == NULL)
	{
		list = p;
		return;
	}
	node* q = list;
	while (q->next != NULL)
	{
		q = q->next;
	}
	q->next = p;
}
void LinkedList::insertPosition(int value, int pos)
{
	node *p = createnode();
	p->info = value;

	if (list == NULL)
	{
		list = p;
		p->next = NULL;
		return;
	}

	if (list == NULL && pos != 0) {
		cout << "Pos not existing!\n";
		return;
	}

	if (pos < 0) {
		cout << "Invalid pos!\n";
		return;
	}

	if (pos == 0) {
		
		
		p->next = list;
		list = p;
		return;
	}



	node *q = list,*k=q;
	for (int i = 0;i < pos;i++)
	{
		if (q->next == NULL)
		{
			cout << "This Position not Exist.\n";
			return;
		}
		k = q;
		q = q->next;
	}
	p->next = q;
	k->next = p;
}
void LinkedList::printLinkedList()
{
	node* q = list;
	while (q->next != NULL)
	{
		cout << q->info << " ---> ";
		q = q->next;
	}
	cout <<q->info<< " ---> NULL\n";

}
void LinkedList::reverse()
{
	node* currentNode = list;
	node* PreviousNode=NULL;
	node* NextNode = NULL;
	while (currentNode != NULL)
	{
		NextNode = currentNode->next;
		currentNode->next = PreviousNode;
		PreviousNode = currentNode;
		currentNode = NextNode;
	}
	list = PreviousNode;
}
int LinkedList::search(int value)
{
	node* p = list;
	int position = 0;
	if (list == NULL)
	{
		cout << "List if Empty.\n";
		return -1;
	}
	while (p->next != NULL)
	{
		position++;
		p = p->next;
		if (p->info == value)
		{
			return position;
		}
	}
	cout << "Element Not Exists in the List.\n";
	return -1;
}
void main() {
	LinkedList linked;
	linked.insertFirst(10);
	linked.insertFirst(20);
	linked.insertFirst(30);
	linked.printLinkedList();
	linked.insertLast(40);
	linked.insertLast(50);
	linked.insertLast(60);
	linked.printLinkedList();
	linked.insertPosition(-1, 4);
	linked.printLinkedList();
	linked.insertPosition(-50, 4);
	linked.printLinkedList();
	linked.reverse();
	cout << "\nAfter Reversing the List\n\n";
	linked.printLinkedList();
	cout << "\n\n" << linked.search(-1)<< "\n";
	linked.insertPosition(-50, 1);
	linked.printLinkedList();
}
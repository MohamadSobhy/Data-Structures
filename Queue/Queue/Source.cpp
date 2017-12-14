#include<iostream>
#include<conio.h>
using namespace std;
#define size 100
class line_queue
{
	int items[size];
	int front;
	int rear;
public:
	line_queue()
	{
		front = -1;
		rear = -1;
	}
	bool isFull()
	{
		if (rear == size - 1)
		{
			return 1;
		}
	return 0;
	}
	bool isEmpty()
	{
		if (front > rear||front==-1)
		{
			return 1;
		}
		return 0;
	}
	void insert(int item)
	{
		if (isFull())
		{
			cout << "Queue Overflow.\n";
			return;
		}
		if(front==-1)
		front = 0;

		items[++rear] = item;
	}
	int remove()
	{
		int item;
		if (isEmpty())
		{
			cout << "Queue Underflow.\n";
			return -1;
		}
		item = items[front++];
		return item;
	}
	void print()
	{
		if (isEmpty())
		{
			cout << "Queue is Empty.\n";
			return;
		}
		cout << "Queue elements :\n";
		for (int i = front;i <= rear;i++)
		{
			cout << items[i] << "  |  ";
		}
		cout << "\n";
	}
};

void main()
{
	//leaner Queue Application....
	line_queue queue;
	char choice; int item;
	do {
		cout << "Enter :\n1 - Insert item.\n2 - Remove item.\n3 - Print queue.\n4 - Exit.\n";
		choice = _getche();
		switch (choice)
		{
		case '1':
		{
			system("cls");
			cout << "Enter item : ";
			cin >> item;
			queue.insert(item);
			cout << "item inserted successfully.\n";
			break;
		}
		case '2':
		{
			system("cls");
			item = queue.remove();
			if(item!=-1)
			cout << "item removed successfully.\n";
			break;
		}
		case '3':
		{
			system("cls");
			queue.print();
			break;
		}
		case '4':
		{
			system("cls");
			exit(0);
		}
		}

		cout << "Do you want to use another function ? (y---> Yes).\n";
		choice = _getche();
		system("cls");
	} while (toupper(choice) == 'Y');
}
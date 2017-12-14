#include<iostream>
#define size 4
using namespace std;
class cr_queue
{
private:
	int front, rear;
	int items[size];
public:
	cr_queue() { front = rear = -1; }
	int isEmpty();
	int isFull();
	void insert(int value);
	int remove();
	void print();
};
int cr_queue::isEmpty()
{
	if (front == -1||front>rear)
		return 1;
	return 0;
}
int cr_queue::isFull()
{
	if ((front == 0 && rear == size - 1) || front == rear + 1)
		return 1;
	return 0;
}
void cr_queue::insert(int item)
{
	if (isFull())
	{
		cout << "Queue OverFlow.\n"; return;
	}
	if (front == -1)
		front = 0;
	if (rear == size - 1)
		rear = 0;
	else
		rear++;

	items[rear] = item;

}
int cr_queue::remove()
{
	if (isEmpty())
	{
		cout << "Queue UnderFlow.\n"; return -1;
	}

	int item = items[front];
	if (front == rear)
	{
		front = rear = -1;
	}
	if (front == size - 1)
		front = 0;
	else
		front++;
	return item;
}
void cr_queue::print()
{
	if (isEmpty())
	{
		cout << "Queue is Empty.\n"; return;
	}
	int i = front;
	while (1)
	{
		cout << items[i]<<" | ";
		if (i == rear)
			break;
		if (i == size - 1)
			i = 0;
		else
			i++;
	}
	cout << "\n";
}
void main()
{
	cr_queue queue;
	queue.insert(10);
	queue.insert(20);
	queue.insert(30);
	queue.print();
	queue.insert(40);
	queue.print();
	queue.insert(50);
	queue.remove();
	queue.remove();
	queue.print();
	queue.remove();
	queue.remove();
	queue.print();
	

}
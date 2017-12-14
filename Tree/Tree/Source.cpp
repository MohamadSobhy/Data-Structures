#include<iostream>
using namespace std;
struct node
{
	int info;
	node* leftchild;
	node* rightchild;
};

class Tree
{
private:
	node* tree;
public:

	Tree() { tree = NULL; }
	void insert(int valus);
	node* create();
	void setLeft(node *p, node* c);
	void setRight(node *p, node* c);
};
node* Tree::create()
{
	node *p = new node;
	tree->leftchild = NULL;
	tree->rightchild = NULL;
	return p;
}
void Tree::setLeft(node* p, node* c)
{
	if (p->info == c->info)
	{
		cout << "This Element already exist.\n";
		return;
	}
	if (p->leftchild == NULL)
	{
		p->leftchild = c; return;
	}
	if (p->leftchild->info < c->info)
	{
		setRight(p->leftchild, c);
	}
	else
	{
		setLeft(p->leftchild, c);
	}
}
void Tree::setRight(node* p, node* c)
{
	if (p->info == c->info)
	{
		cout << "This Element already exist.\n";
		return;
	}
	if (p->rightchild == NULL)
	{
		p->rightchild = c; return;
	}
	if (p->rightchild->info < c->info)
	{
		setRight(p->rightchild, c);
	}
	else
	{
		setLeft(p->rightchild, c);
	}
}
void Tree::insert(int value)
{
	node* p = create();
	node* q = tree;
	p->info = value;
	if (q == NULL)
	{
		tree = p; return;
	}
	if (p->info == q->info)
	{
		cout << "This Element is already exist.\n"; return;
	}
	else if (p->info < q->info)
	{
		setLeft(q, p);
	}
	else
	{
		setRight(q, p);
	}
}

void main()
{
	//Tree tree;

}













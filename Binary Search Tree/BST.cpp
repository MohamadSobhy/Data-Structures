// An implementation of Binary Search Tree

#include <iostream>
#include <string.h>
using namespace std;

#define  TRUE  1
#define  FALSE 0
typedef  int BOOL;

/**************** Class *****************/
struct node
{
	int info;
	node *leftChild;
	node *rightChild;
};
class binary_tree
{
private:
	node *tree;
public:
	binary_tree();
	//~binary_tree() { free_BST(tree); }
	node* create_node();
	void free_node(node *p);
	void insert_node(int value);
	void set_left_child(node *p, node* new_node);
	void set_right_child(node *p, node* new_node);
	void preorder_traversal(node *);
	void inorder_traversal(node *);
	void postorder_traversal(node *);
	void free_BST(node* t);
	void search(int key);
	node* get_tree(){ return tree; };
	BOOL delete_node(node *t, int key);
};
/************** binary_tree *********************/
binary_tree::binary_tree()
{

	tree = NULL;

}
/************** Create NODE *********************/
node* binary_tree::create_node()
{
	node *p = new node;
	p->leftChild = NULL;
	p->rightChild = NULL;
	return p;
}
/*************** FREE NODE *****************/
void binary_tree::free_node(node *ptree)
{
	delete (ptree);
}

/*********** Insert_node *****************/
void binary_tree::insert_node(int value)
{

	node *new_node = create_node();
	new_node->info = value;

	if (tree == NULL) // Tree is empty
	{
		tree = new_node;
		return;
	}
		
	node *temp = tree;
	if (new_node->info == temp->info) // duplicate in values is not accepted
	{
		cout << "The item is already in the tree"<<endl;
		system("pause");
		return;
	}
	else if (new_node->info > temp->info)  //add rightChild
		set_right_child(temp, new_node);
	else if (new_node->info < temp->info)
		set_left_child(temp, new_node);    //add leftChild
}
/*********** Set leftChild  *****************/
void binary_tree::set_left_child(node *p, node* new_node)
{
	if (new_node->info == p->info) // duplicate in values is not accepted
	{
		cout << "The item is already in the tree" << endl;
		system("pause");
		return;
	}
	if (p == NULL)
		cout << "void insertion" << endl;
	else if (p->leftChild != NULL)
	if (new_node->info > p->leftChild->info)  //add new_node as rightChild 
		set_right_child(p->leftChild, new_node);
	else
		set_left_child(p->leftChild, new_node);    //add new_node as leftChild 

	else
		p->leftChild = new_node; // leftChild is null for the currrent node
}
/*********** Set rightChild  *****************/
void binary_tree::set_right_child(node *p, node* new_node)
{
	if (new_node->info == p->info) // duplicate in values is not accepted
	{
		cout << "The item is already in the tree" << endl;
		system("pause");
		return;
	}
	if (p == NULL)
		cout << "void insertion" << endl;
	else if (p->rightChild != NULL)
	if (new_node->info > p->rightChild->info)  //add as rightChild 
		set_right_child(p->rightChild, new_node);
	else
		set_left_child(p->rightChild, new_node);    //add as leftChild 
	else
		p->rightChild = new_node;//  rightChild is null for the currrent node
}
/************ Preorder Traversal ******************/
void  binary_tree::preorder_traversal(node *t)
{
	if (tree == NULL)
	{
		cout << "Tree is empty" << endl;
		system("pause");
		return;
	}
	// traverse Root,leftChild subtree, and rightChild sub tree
	if (t != NULL)
	{
		cout << t->info << " "; //visit the root
		preorder_traversal(t->leftChild);// vist the leftChild Sub Tree
		preorder_traversal(t->rightChild);// vist the rightChild Sub Tree
	}
}
/************* Inorder Traversal ******************/
void  binary_tree::inorder_traversal(node *t)
{
	if (tree == NULL)
	{
		cout << "Tree is empty" << endl;
		system("pause");
		return;
	}
	// traverse leftChild subtree,Root, and rightChild sub tree
	if (t != NULL)
	{
		inorder_traversal(t->leftChild);// vist the leftChild Sub Tree
		cout << t->info << " "; //visit the root
		inorder_traversal(t->rightChild);// vist the rightChild Sub Tree
	}
}
/************ Postorder Traversal *****************/
void  binary_tree::postorder_traversal(node *t)
{
	if (tree == NULL)
	{
		cout << "Tree is empty" << endl;
		system("pause");
		return;
	}
	// traverse leftChild subtree, rightChild sub tree, and the Root
	if (t != NULL)
	{
		postorder_traversal(t->leftChild);// vist the leftChild Sub Tree
		postorder_traversal(t->rightChild);// vist the rightChild Sub Tree
		cout << t->info << " "; //visit the root
	}
}
/************ Search in Tree  *****************/
void binary_tree::free_BST(node* t) //get root
{
	if (t == NULL)
		return;
	if (t->leftChild != NULL)
		free_BST(t->leftChild);
	if (t->rightChild != NULL)
		free_BST(t->rightChild);

	free_node(t);       // free(t) if c

	return;
}

/************ Search in Tree  *****************/
void binary_tree::search(int key)
{
	node *parent = tree;
	node *temp = tree;
	char path[100];

	strcpy_s(path, "");
	if (temp == NULL)
		cout << "The tree is empty" << endl;
	else
	{
		strcpy_s(path, "root");
		while (temp != NULL && temp->info != key)
		{
			parent = temp;
			if (key > temp->info)
			{
				temp = temp->rightChild;
				strcat_s(path, " ->rightChild ");
			}
			else
			{
				temp = temp->leftChild;
				strcat_s(path, " ->leftChild ");
			}
		}//end while
	}//end outter else
	if (temp == NULL)
		cout << "Key not found!";
	else
	{
		cout << "Key is found\n";
		cout << "Paht is: ";
		cout << path;
	}
}
////////////////////////////// Delete node

BOOL binary_tree::delete_node(node *t, int key)
{
	if (t == NULL) // item not in BST
		return FALSE;
	if (key < t->info)  // check if the value in the leftChild subtree
		delete_node(t->leftChild, key);
	else if (key > t->info) // check if the value in the rightChild subtree
		delete_node(t->rightChild, key);
	else
	{
		node *temp = NULL;
		if (t->leftChild == NULL) // the node to be deleted has not a leftChild child
		{
			temp = t->rightChild;
			free_node(t);
			t = temp;
		}
		else if (t->rightChild == NULL)  // the node to be deleted has not a rightChild child
		{
			temp = t->leftChild;
			free_node(t);
			tree = temp;
		}
		else    //the node to be deleted has 2 children
		{
			temp = t->rightChild;
			while (temp->leftChild != NULL)
			{
				temp = temp->leftChild;
			}
			t->info = temp->info;
			delete_node(t->rightChild, temp->info);

		}
	}
}

//////////////////////////////////////////////////////////////////
/******************* MAIN ************************/
void main()
{
	
	binary_tree bi_s_tree;

	int choice, n, key;
	while (1)
	{
		cout << "\n\t1. Insert\n\t2. Search\n\t3. Preorder Traversal\n\t4. Inorder Treversal\n\t5. Postorder Traversal\n\t6. Delete node\n\t7. Exit" << endl;
		cout << "Enter your choice: ";
		cin >> choice;
		switch (choice)
		{
		case 1: // insert node
			cout << "Enter item: ";
			cin >> n;
			bi_s_tree.insert_node(n);
			break;
		case 2: // search for element
			cout << "Enter element to search: ";
			cin >> key;
			bi_s_tree.search(key);
			break;
		case 3: // prints tree nodes in pre-order
			cout << endl;
			bi_s_tree.preorder_traversal(bi_s_tree.get_tree());
			break;
		case 4:// prints tree nodes in-order
			cout << endl;
			bi_s_tree.inorder_traversal(bi_s_tree.get_tree());		
			break;
		case 5: // prints tree nodes in post-order
			cout << endl;
			bi_s_tree.postorder_traversal(bi_s_tree.get_tree());
			break;
		case 6: // delete a node 
			cout << "Enter a node value to be deleted: ";
			cin >> n;
			bi_s_tree.delete_node(bi_s_tree.get_tree(), n);
			break;
		case 7: // delete all nodes in the BST before exit
			bi_s_tree.free_BST(bi_s_tree.get_tree());
			exit(0);
		}// end switch
	}//endl while loop

	system("pause");
}
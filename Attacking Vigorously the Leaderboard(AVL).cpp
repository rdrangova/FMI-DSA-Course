#include"stdafx.h"
#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>

using namespace std;

struct Node
{
	double value;
	Node *left;
	Node *right;
	int height;

	Node(double value, Node *left, Node *right, int height)
	{
		this->value = value;
		this->left = left;
		this->right = right;
		this->height = height;
	}
};

class AVLTree
{
private:
	

	int height(Node *N)
	{
		if (N == NULL)
			return 0;
		return N->height;
	}

	bool containsRecursive(Node *current, double value)
	{
		if (current == NULL)
		{
			return false;
		}

		if (current->value == value)
		{
			return true;
		}

		if (value < current->value)
		{
			return containsRecursive(current->left, value);
		}
		else
		{
			return containsRecursive(current->right, value);
		}
	}

	void printRecursive(Node *current)
	{
		if (current == NULL)
		{
			return;
		}

		printRecursive(current->left);
		cout << current->value << " ";
		printRecursive(current->right);
	}

	Node *rightRotate(struct Node *y)
	{
		struct Node *x = y->left;
		struct Node *T2 = x->right;
 
		x->right = y;
		y->left = T2;

		y->height = max(height(y->left), height(y->right)) + 1;
		x->height = max(height(x->left), height(x->right)) + 1;
 
		return x;
	}

	Node *leftRotate(Node *x)
	{
		 Node *y = x->right;
		 Node *T2 = y->left;
 
		y->left = x;
		x->right = T2;

		x->height = max(height(x->left), height(x->right)) + 1;
		y->height = max(height(y->left), height(y->right)) + 1;
 
		return y;
	}
 
	int getBalance(struct Node *N)
	{
		if (N == NULL)
			return 0;
		return height(N->left) - height(N->right);
	}

	Node * minValueNode(Node* node)
	{
		Node* current = node;

		while (current->left != NULL)
			current = current->left;

		return current;
	}



public:
	Node * root;
	AVLTree()
	{
		root = NULL;
	}



	void add(Node* &node, double value)
	{
		if (node == NULL) {
			node = new Node(value, NULL, NULL, 1);
			return;
		}
			

		if (value < node->value)
			add(node->left, value);
		else if (value > node->value)
			add(node->right, value);
		else
			cout << value << " already added" << endl;
			return;

		node->height = 1 + max(height(node->left),
			height(node->right));

		int balance = getBalance(node);

		if (balance > 1 && value < node->left->value)
			node= rightRotate(node);

		if (balance < -1 && value > node->right->value)
			node= leftRotate(node);

		if (balance > 1 && value > node->left->value)
		{
			node->left = leftRotate(node->left);
			node= rightRotate(node);
		}

		if (balance < -1 && value < node->right->value)
		{
			node->right = rightRotate(node->right);
			node= leftRotate(node);
		}

	}

	void remove(Node* root, double value)
	{ 

		if (root == NULL) {
			cout << value << " not found to remove" << endl;
			//root = new Node(value, NULL, NULL, 1);
			return;
		}
			

		if (value < root->value)
			remove(root->left, value);

		else if (value > root->value)
			remove(root->right, value);

		else
		{
			if ((root->left == NULL) || (root->right == NULL))
			{
				Node *temp = root->left ? root->left :root->right;
 
				if (temp == NULL)
				{
					temp = root;
					root = NULL;
				}
				else  
					*root = *temp; 

				free(temp);
			}
			else
			{ 
				Node* temp = minValueNode(root->right);
 
				root->value = temp->value;
 
				remove(root->right, temp->value);
			}
		}

		if (root == NULL)
			return;

		root->height = 1 + max(height(root->left),
			height(root->right));

		int balance = getBalance(root);

		if (balance > 1 && getBalance(root->left) >= 0)
			root= rightRotate(root);

		if (balance > 1 && getBalance(root->left) < 0)
		{
			root->left = leftRotate(root->left);
			root= rightRotate(root);
		}

		if (balance < -1 && getBalance(root->right) <= 0)
			root= leftRotate(root);

		if (balance < -1 && getBalance(root->right) > 0)
		{
			root->right = rightRotate(root->right);
			root=leftRotate(root);
		}

	}


	bool contains(double value)
	{
		if (root == NULL)
		{
			return false;
		}

		return containsRecursive(root, value);
	}

	void print()
	{
		if (root == NULL)
		{
			return;
		}

		printRecursive(root);
		cout << endl;
	}
};

int main()
{
	AVLTree tree;
	string operation;
	double number;
	int N;

	cin >> N;
	cout << fixed;

	for (size_t i = 0; i < N; i++)
	{
		cin >> operation;
		if (operation != "print")
		{
			cin >> number;
		}

		if (operation == "add")
		{
			tree.add(tree.root, number);
		}
		else if (operation == "remove")
		{
			tree.remove(tree.root, number);
		}
		else if (operation == "contains")
		{
			if (tree.contains(number))
			{
				cout << "yes" << endl;
			}
			else
			{
				cout << "no" << endl;
			}
		}
		else if (operation == "print")
		{
			tree.print();
		}
	}

	return 0;
}
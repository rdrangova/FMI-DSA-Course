// BinaryTree.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include<iomanip>
#include <queue>
#include <vector>
using namespace std;

struct Node {
	int data;
	Node* left, *right;
};


Node* insert(Node*root, int data){
	if (root == NULL)
		return new Node{ data,nullptr,nullptr };
	if (data < root->data)
		root->left = insert(root->left, data);
	else
		root->right = insert(root->right, data);

	return root;

}

void averageOfLevels(Node* root)
{
	vector<float> res;
 
	queue<Node*> q;
	q.push(root);

	while (!q.empty()) {

		int sum = 0, count = 0;
		queue<Node*> temp;
		while (!q.empty()) {
			Node* n = q.front();
			q.pop();
			sum += n->data;
			count++;
			if (n->left != NULL)
				temp.push(n->left);
			if (n->right != NULL)
				temp.push(n->right);
		}
		q = temp;
		double average = sum * 1.00 / count;
		cout << fixed << showpoint;
		cout << setprecision(2) << average<<endl;
	}
}

int main()
{
	Node* root = nullptr;

	int n;
	cin >> n;

	int data;
	for (size_t i = 0; i < n; i++)
	{
		cin >> data;
		root = insert(root, data);
	}

	averageOfLevels(root);
    return 0;
}


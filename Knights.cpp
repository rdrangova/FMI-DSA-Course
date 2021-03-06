// Knights.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

struct Node
{
	int value;
	Node* next;
};

Node* head;
Node* tail;
Node newNode[20000001];
void push(int data)
{
	
	if (head == nullptr)
	{
		head = &newNode[0];
		tail = &newNode[0];
		head->value = data;
	}
	else
	{
		tail->next = tail+1;
		tail = tail->next;
		tail->value = data;
	}
}


int putBack() {
	while (head != tail) {
		tail->next = head;
		tail = tail->next;
		head= head->next->next;
	}
	
	return head->value;
}


int main()
{
	
	int n;
	cin >> n;
	for (size_t i = 1; i <= n; i++)
	{
		push(i);
	}

	cout << putBack()<<"\n";
    return 0;
}


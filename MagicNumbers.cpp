// MagicNumbers.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <queue>

using namespace std;

int main()
{
	unsigned long long num;
	cin >> num;

	if (num < 10)
	{
		for (size_t i = 1; i <= num; i++)
		{
			cout << i << " ";
		}
		cout << endl;
		return 0;
	}

	queue<unsigned long long> q;
	for (int i = 1; i < 10; i++)
	{
		q.push(i);
	}

	while (!q.empty())
	{
		unsigned long long temp = q.front();
		q.pop();

		if (temp < num)
		{
			cout << temp << " ";
		}

		int lastdigit = temp % 10;
		int putInBackSmall = lastdigit - 2;
		int putInBackBig = lastdigit + 2;

		unsigned long long tempSmaller=temp;
		unsigned long long tempBigger=temp;

		if (putInBackSmall >= 0)
		{
			unsigned long long tempSmaller = temp * 10 + putInBackSmall;
			if (tempSmaller < num)
			{
				q.push(tempSmaller);
			}
		}
		
		if (putInBackBig<= 9)
		{
			unsigned long long tempBigger = temp * 10 + putInBackBig;
			if (tempBigger < num)
			{
				q.push(tempBigger);
			}
		}

		if ((tempSmaller > num && tempSmaller!=temp) || (tempBigger > num && tempBigger!=temp))
		{
			while (!q.empty())
			{
				cout << q.front() << " ";
				q.pop();
			}
		}

	}
	return 0;

}


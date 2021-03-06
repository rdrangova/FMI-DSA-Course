// Road.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main()
{
	int n;
	cin >> n;
	
	string color;
	int numeration;
	stack<int> tiles;
	for (size_t i = 0; i < n; i++)
	{
		cin >> color>>numeration;
		if (color == "white")
			tiles.push(numeration);
		else if (color == "green") 
		{
			int sum = 0;
			while (!tiles.empty() && numeration) 
			{
				sum += tiles.top();
				tiles.pop();
				abs(numeration--);
			}
			tiles.push(sum);
		}
		else
		{
			int max = tiles.top();
			while (!tiles.empty() && numeration)
			{
				if(tiles.top()>max)
					max = tiles.top();
				tiles.pop();
				abs(numeration--);
			}			
			tiles.push(max);

		}
	}


	stack <int> output;
	while (!tiles.empty())
	{
		output.push(tiles.top());
		tiles.pop();
	}

	while (!output.empty())
	{
		cout<<output.top()<<" ";
		output.pop();
	}
	
	cout << endl;
    return 0;
}


// BrandNew.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <math.h>
#include <iomanip>
#include <algorithm>
#include <stack>;
using namespace std;


vector< int> map;

bool visited[100001];

vector<int>edges[100001];

int main()
{

	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	int m;
	cin >> m;
	
	map.resize(n + 1);

	int temp;
	for (int i = 0; i < n; i++)
	{

		cin >> temp;
		map[i + 1] = temp;

	}
	int temp1;
	int temp2;
	for (int i = 1; i < n; i++)
	{
		cin >>temp1;
		cin >> temp2;
		edges[temp1].push_back(temp2);
		edges[temp2].push_back(temp1);

	}

	int counter = 0;
	stack <int> paths;
	paths.push(1);
	visited[1] = true;


	while (!paths.empty())
	{
		int curr = paths.top();
		bool inPaths = false;

		for (int i = 0; i < edges[curr].size(); i++)
		{
			int node = edges[curr][i];
			if (!visited[node])
			{
				visited[node] = true;
				if (map[node] == 1)
				{
					map[node] += map[curr];
				}

				if (map[node] <= m)
				{
					paths.push(node);
					inPaths = true;

					break;
				}
			}
		}

		if (!inPaths)
		{
			if (curr != 1 && edges[curr].size() == 1)
				counter++;
			paths.pop();
		}
	}

	cout << counter << endl;

    return 0;
}


// BDZ.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <limits>
#include <map>
using namespace std;

long long MAX = 10000000000;

struct Path
{
	int second;
	long long length;
	bool isBDZ;
};
vector < vector <Path>> adjList;
//struct Edge


bool  operator <(Path &p1, Path &p2)
{
	return p1.length < p2.length;
}

vector <Path> distances;
int importantTrains=0;
void dijkstra() {
	int n = adjList.size();
	distances.assign(n + 1, { -1, MAX,false });
	vector<bool> marked;
	marked.resize(n + 1);
	marked.assign(n + 1, false);

	distances[1].length = 0;

	int to;
	long long len;

	for (int i = 1; i <= n; i++)
	{
		int v = -1;
		for (int j = 1; j <= n; j++)
		{
			if (!marked[j] && (v == -1 || distances[j] < distances[v]))
			{
				v = j;
			}
		}

		if (distances[v].length == MAX)
			break;

		marked[v] = true;

		for (auto edge : adjList[v]) {
			to = edge.second;
			len = edge.length;

			if (distances[v].length + len < distances[to].length)
			{
				distances[to].length = distances[v].length + len;
				if (edge.isBDZ)
				{
					distances[to].isBDZ = true;
				}
				else if (!edge.isBDZ && !distances[v].isBDZ)
				{
					distances[to].isBDZ = false;
				}

			}
		
		}
	}
}


int main()
{
	ios_base::sync_with_stdio(false);

	int n; //cities count
	int m;//magistrali
	int k; //bdz
	int u, v;
	long long w; //edge
	cin >> n >> m>>k;
	adjList.resize(n + 1);
		//adjList.assign(m, nullptr);

	for (int j = 1; j <= m; j++)
	{
		cin >> u >> v >> w;
		adjList[u].push_back({v,w,false });
		adjList[v].push_back({u, w,false });
	}
	for (int j = 1; j <= k; j++)
	{
		cin >> v >> w;
		adjList[1].push_back({v, w,true });
		adjList[v].push_back({1, w,true });
	}

	dijkstra();

	for (int i=1;i<=n;i++)
	{
		if (distances[i].isBDZ)
		{
			importantTrains++;
		}
	}
	cout << k - importantTrains;
	return 0;
}


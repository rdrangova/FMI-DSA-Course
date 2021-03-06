// Labirinth.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <queue>

using namespace std;

bool labirinth[5000][5000];
int temp[5000][5000];
const int neighbourRows[] = { -1,0,0,1 };
const int neighbourColumns[] = { 0,-1,1,0 };

struct Point {
	int x;
	int y;
};

struct Node {
	Point point;
	int distance;
};

int main()
{
	int rows;
	cin >> rows;
	int columns;
	cin >> columns;

	int queries;
	cin >> queries;
	int x;
	int y;

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++) {
			cin >> labirinth[i][j];
		}
	}
	
	labirinth[0][0] = true;
	temp[0][0] = 0;
	queue<Node> distances;
	Point start = { 0,0 };
	distances.push({ start,0 });
	while (!distances.empty())
	{
		Node currNode = distances.front();
		Point currPoint = currNode.point;

		distances.pop();

		for (int i = 0; i < 4; i++)
		{
			int row = currPoint.x + neighbourRows[i];
			int col = currPoint.y + neighbourColumns[i];

			if (row >= 0 && col >= 0 && !labirinth[row][col] && temp[row][col]==0 && row < rows && col < columns)
			{
				temp[row][col] = currNode.distance+1;
				distances.push({ { row,col },currNode.distance + 1 });
			}
		}

	}
	
	for (size_t i = 0; i < queries; i++)
	{

		cin >> x >> y;
		Point dest = { x,y };
		if (temp[x][y] == 0)
			cout << -1 << endl;
		else 
			cout << temp[x][y]<<endl;
	}
    return 0;
}


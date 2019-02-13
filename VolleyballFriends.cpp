
#include <iostream>
#include <map>

using namespace std;

int main()
{
	map<int, int> players;
	int firstPlayer;
	cin >> firstPlayer;
	players.emplace(firstPlayer, firstPlayer);
	int n;
	cin >> n;
	int friendN;
	int currentN;
	for (int i = 0; i < n; i++)
	{
		cin >> friendN;
		cin >> currentN;
		if (players.find(friendN) != players.end())
		{
			players.emplace(currentN,friendN);
		}
	}
	cout << players.size() << endl;


    return 0;
}


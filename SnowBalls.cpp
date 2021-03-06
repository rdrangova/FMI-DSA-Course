// SnowBalls.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

int sum = 0;

const int MAX = 10000001;
int sums[MAX] = { 0 };
int ancestors[MAX] = { 0 };

int main()
{
	int n;
	cin >> n;

	long long sum=0;
	for (int i = 1; i <= n; i++)
	{

		int ancestor;
		cin >> ancestor;
		int balls;
		cin >> balls;

		if (balls == 0)
		{
			int indexprev = ancestors[ancestor];
			sums[i] = sums[indexprev];
			ancestors[i] = ancestors[indexprev];

		}
		else
		{
			sums[i] = sums[ancestor] + balls;
			ancestors[i] = ancestor;
		}
	}

	for (size_t i = 1; i <= n; i++)
	{
		//cout << sums[i] << "    " << ancestors[i] << "\n";
		sum += sums[i];
	}

	cout << sum << "\n";
    return 0;
}


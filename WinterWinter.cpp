// WinterWinter.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <math.h>

using namespace std;

int BinarySearch(int* arr, int maxTime, int n, double k) //k must be int, but ceil doesn't like it that way
{
	//int optimalTime = maxTime;
	int remainingSum = 0;
	int mid = maxTime / 2;
	//int minDiff = 
	for (size_t i = 0; i < n; i++)
	{
		if (arr[i] - mid> 0)
		{
			remainingSum += ceil((arr[i]-mid) / k);
		}
	}
	cout << mid <<" " <<remainingSum << endl;

	if (remainingSum == mid || mid - remainingSum == 1) //this diff could be bigger
		return mid;
	else if (remainingSum - mid == 1)
		return remainingSum;

	if (remainingSum < mid) 
		return BinarySearch(arr, mid - 1, n,k);
	if(remainingSum > mid) 
		return BinarySearch(arr, maxTime+2, n, k);

	return -1;
}

int main()
{

	int n;
	cin >> n;
	double k;
	cin >> k;
	int maxTime = 0;
	int * arr = new int[n];
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
		if (arr[i] > maxTime)
			maxTime = arr[i];
	}

	int result = BinarySearch(arr, maxTime, n, k);
	cout << result<<endl;

	 return 0;
}


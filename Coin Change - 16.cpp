// CoinChange.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

int arr[] = { 1, 2, 3 };
int cache[11][5001];
void initCache() {
	for (int i = 0; i < 11; i++)
		for (int j = 0; j < 5001; j++)
			cache[i][j] = -1;
}

int coinChange(int index, int sum) {
	if (sum == 0)
		return 1;

	if (index < 0 && sum > 0)
		return 0;

	if (arr[index] > sum)
		return coinChange(index - 1, sum);
	
	if (cache[index][sum] != -1)
		return cache[index][sum];

	int option1 = coinChange(index - 1, sum);
	int option2 = coinChange(index, sum - arr[index]);

	return cache[index][sum] = option1 + option2;
}

int _tmain(int argc, _TCHAR* argv[])
{
	initCache();
	cout << coinChange(2, 4000);
	return 0;
}


// Binomial coefficient.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

//int set[] = { 3, 34, 4, 5, 12, 35, 98 };
//int sum = 43;

int set[] = { 3, 34, 4, 12, 5, 2, 1, 2, 3, 4, 5, 6 ,7 ,8 ,9, 10,
          11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25 };
int sum = 325;

int cache[51][1001];
void initCache() {
	for (int i = 0; i < 51; i++)
		for (int j = 0; j < 1001; j++)
			cache[i][j] = -1;
}

bool isSubset(int index, int sum) {
	if (sum == 0)
		return true;

	if (index < 0 && sum != 0)
		return false;

	if (set[index] > sum)
		return isSubset(index - 1, sum);

	if (cache[index][sum] != -1)
		return cache[index][sum];
	
	bool option1 = isSubset(index - 1, sum);
	bool option2 = isSubset(index - 1, sum - set[index]);

	return cache[index][sum] = option1 || option2;
}


int _tmain(int argc, _TCHAR* argv[])
{
	int asize = sizeof(set) / sizeof(set[0]);
	initCache();
	cout<<isSubset(asize - 1, sum);
	return 0;
}


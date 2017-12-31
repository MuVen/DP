// Binomial coefficient.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

/*
Count number of ways to cover a distance

Given a distance ‘dist, count total number of ways to cover the distance with 1, 2 and 3 steps.
*/
typedef unsigned int uint;

uint cache[101];
void initCache() {
	for (int i = 0; i < 101; i++)
		cache[i] = -1;
}

int countNWays(int d) {
	if (d < 0)
		return 0;

	if (d == 0)
		return 1;

	if (cache[d] != -1)
		return cache[d];

	int option1 = countNWays(d - 1);
	int option2 = countNWays(d - 2);
	int option3 = countNWays(d - 3);

	return cache[d] = option1 + option2 + option3;
}

int _tmain(int argc, _TCHAR* argv[])
{
	initCache();
	cout << countNWays(20);
	return 0;
}


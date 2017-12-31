// Binomial coefficient.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

/*
value[] = { 60, 100, 120 };
weight[] = { 10, 20, 30 };
W = 50;

Weight 10 - > 60;
Weight 20 - > 100;
Weight 30 - > 120;

Weight 10, 20 -> 60 + 100;
Weight 10, 30 -> 60 + 120;
Weight 20, 30 -> 100 + 120;

Weight 10, 20, 30 (Not possible as you can carry max limit of 50 kgs only)

*/

int value[] = { 60, 100, 120,60, 100, 120,60, 100, 120,60, 100, 120,60, 100, 120,60, 100, 120,60, 100, 120,60, 100, 120,60, 100, 120,60, 100, 120 };
int weight[] = { 10, 20, 30,10, 20, 30,10, 20, 30,10, 20, 30,10, 20, 30,10, 20, 30,10, 20, 30,10, 20, 30,10, 20, 30,10, 20, 30 };
int W = 340;

int cache[51][501];
void initCache() {
	for (int i = 0; i < 51; i++)
		for (int j = 0; j < 501; j++)
			cache[i][j] = -1;
}

#define MAX(a,b) ((a)>(b)?(a):(b))

int knapsack(int index, int capacity) {
	if (index < 0 || capacity == 0)
		return 0;

	if (weight[index] > capacity)
		return knapsack(index - 1, capacity);

	if (cache[index][capacity] != -1)
		return cache[index][capacity];

	int option2 = knapsack(index - 1, capacity);
	int option3 = value[index] +
		knapsack(index - 1, capacity - weight[index]);

	return cache[index][capacity] = MAX(option2, option3);
}

int _tmain(int argc, _TCHAR* argv[])
{
	int wsize = sizeof(weight) / sizeof(weight[0]);
	initCache();
	cout << knapsack(wsize, W)<<endl;
	return 0;
}


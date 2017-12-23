// DP.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
// Dynamic Programming !!!

// Find the Nth Febinocc number.

// 0, 1, 1, 2, 3, 5, 8, 13, 21, ...

// F(N-1)+F(N-2).

// N == 1, 1
// N == 0, 0.

//N 1<=N<=45 (1,45)

int cache[45+1];
void initCache() {
	for (int i = 0; i < 46; i++)
		cache[i] = -1;
}


int F(int N) {
	if (N == 0 || N == 1)
		return N;

	if (cache[N] != -1)
		return cache[N];

	return cache[N] = F(N - 1) + F(N - 2);
}

int main()
{
	initCache();
	printf("%d is the 8th Feb number\n", F(8));
	initCache();
	printf("%d is the 5th Feb number\n", F(5));
	initCache();
	printf("%d is the 10th Feb number\n", F(10));
	initCache();
	printf("%d is the 45th Feb number\n", F(45));
}


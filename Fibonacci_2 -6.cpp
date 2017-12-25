// function calling.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

//write a function which returns nth febo.
// N - [1, 45]
int cache[46];
void initCache() {
	for (int i = 0; i < 46; i++)
		cache[i] = -1;
}


int F(int N) {
	if (N == 0 || N == 1)
		return N;
	//dynamic programming or smart recursion;
	// this method of caching, memoization or top-down
	if (cache[N] != -1)
		return cache[N];

	return cache[N] = F(N - 1) + F(N - 2);
}

int main()
{
	initCache();
	printf("%d ", F(45));
    return 0;
}


// Binomial coefficient.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;


//N-[1,50]
//6,2 = 5,1 + 5,2

typedef long long int lii;
lii cache[51][51];
void initCache() {
	for (int i = 0; i < 51; i++)
		for (int j = 0; j < 51; j++)
			cache[i][j] = -1;
}

lii bCoe(int N, int K) {
	if (K == 0 || N == K)
		return 1;

	if (cache[N][K] != -1)
		return cache[N][K];

	lii option1 = bCoe(N - 1, K - 1);
	lii option2 = bCoe(N - 1, K);
	return cache[N][K] = option1 + option2;
}


int _tmain(int argc, _TCHAR* argv[])
{
	initCache();
	cout << "BC(40,14) " << bCoe(40, 14);
	return 0;
}


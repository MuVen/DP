// Binomial coefficient.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

#define MAX(a,b) ((a)>(b)?(a):(b))

string str1 = "ABEGHPUJABEGHPUJABEGHPUJABEGHPUJABEGHPUJABEGHPUJABEGHPUJ";
string str2 = "BYFGKOPJBYFGKOPJBYFGKOPJBYFGKOPJBYFGKOPJBYFGKOPJBYFGKOPJ";

int cache[151][151];
void initCache() {
	for (int i = 0; i < 151; i++)
		for (int j = 0; j < 151; j++)
			cache[i][j] = -1;
}

int LCS(int s1Len, int s2Len) {
	if (s1Len == 0 || s2Len == 0)
		return 0;

	if (cache[s1Len][s2Len] != -1)
		return cache[s1Len][s2Len];

	if (str1[s1Len - 1] == str2[s2Len - 1])
		return 1 + LCS(s1Len - 1, s2Len - 1);

	int option1 = LCS(s1Len - 1, s2Len);
	int option2 = LCS(s1Len, s2Len - 1);
	return cache[s1Len][s2Len] = MAX(option1, option2);
}

int _tmain(int argc, _TCHAR* argv[])
{
	initCache();
	cout << LCS(str1.length(), str2.length());
	return 0;
}


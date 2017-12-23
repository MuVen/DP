// DP.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
// Dynamic Programming !!!
#include <iostream>
#include <string>
using namespace std;

//edit distance; min number of operations required to convert str1 
// to str2
#define MIN(a,b) ((a)>(b)?(b):(a))

string str1 = "SUNDAYSUNDAYSUNDAYSUNDAYSUNDAYSUNDAYSUNDAYSUNDAYSUNDAYSUNDAY";
string str2 = "SATURDAYSATURDAYSATURDAYSATURDAYSATURDAYSATURDAYSATURDAYSATURDAY";

// strl <= 100;

//only 1 variable varying, 1d;
//2 variable 2d;
//3 vraialbe then we 3d cached; int cahce[100][100][100]

int cache[101][101];//2d cache;
void initCache() {
	for (int i = 0; i < 101; i++)
		for (int j = 0; j < 101; j++)
			cache[i][j] = -1;

}


int editDistance(int s1Len, int s2Len) {

	if (s1Len == 0)
		return s2Len;

	if (s2Len == 0)
		return s1Len;

	if (cache[s1Len][s2Len] != -1)
		return cache[s1Len][s2Len];

	if (str1[s1Len - 1] == str2[s2Len - 1])
		return editDistance(s1Len - 1, s2Len - 1);

	int option1 = editDistance(s1Len - 1, s2Len - 1);//replacing
	int option2 = editDistance(s1Len - 1, s2Len);//deleting
	int option3 = editDistance(s1Len, s2Len - 1);//inserting

	return cache[s1Len][s2Len] = 1 + MIN(MIN(option1, option2), option3);
}

int main()
{
	initCache();
	cout << editDistance(str1.length(), str2.length());
}


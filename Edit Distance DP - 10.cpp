// function calling.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

//edit distance, 
#include <iostream>
#include <string>
using namespace std;

string str1 = "SUNDAYSUNDAYSUNDAYSUNDAYSUNDAYSUNDAYSUNDAYSUNDAYSUNDAY";
string str2 = "SATURDAYSATURDAYSATURDAYSATURDAYSATURDAYSATURDAYSATURDAY";

int cache[101][101];
void initCache() {
	for (int i = 0; i < 101; i++)
		for (int j = 0; j < 101; j++)
			cache[i][j] = -1;
}

#define MIN(a,b) ((a)>(b)?(b):(a))

//variable paramenters in the function.
//define cache dimension based on variable paremeters.
int editDistance(int s1Len, int s2Len) {
	if (s1Len == 0)
		return s2Len;

	if (s2Len == 0)
		return s1Len;

	if (cache[s1Len][s2Len] != -1)
		return cache[s1Len][s2Len];

	if (str1[s1Len - 1] == str2[s2Len - 1])
		return editDistance(s1Len - 1, s2Len - 1);

	int option1 = editDistance(s1Len - 1, s2Len - 1);//replacing;
	int option2 = editDistance(s1Len - 1, s2Len);//deleting.
	int option3 = editDistance(s1Len, s2Len - 1);//insertion,

	return cache[s1Len][s2Len] = MIN(MIN(option1, option2), option3) + 1;
}


int main()
{
	initCache();
	printf("%d ", editDistance(str1.length(), str2.length()));
    return 0;
}


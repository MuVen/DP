// function calling.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

//edit distance, 
#include <iostream>
#include <string>
using namespace std;

string str1 = "SUNDAY";
string str2 = "SATURDAY";

#define MIN(a,b) ((a)>(b)?(b):(a))

int editDistance(int s1Len, int s2Len) {
	if (s1Len == 0)
		return s2Len;

	if (s2Len == 0)
		return s1Len;

	if (str1[s1Len - 1] == str2[s2Len - 1])
		return editDistance(s1Len - 1, s2Len - 1);

	int option1 = editDistance(s1Len - 1, s2Len - 1);//replacing;
	int option2 = editDistance(s1Len - 1, s2Len);//deleting.
	int option3 = editDistance(s1Len, s2Len - 1);//insertion,

	return MIN(MIN(option1, option2), option3) + 1;
}


int main()
{
	printf("%d ", editDistance(str1.length(), str2.length()));
    return 0;
}


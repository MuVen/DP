// function calling.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

void printNumbers(int N) {
	if (N == 0)
		return;

	printf("%d ", N);
	printNumbers(N - 1);
}

int main()
{
	printNumbers(5);
    return 0;
}


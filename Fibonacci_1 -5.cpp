// function calling.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

//write a function which returns nth febo.

int F(int N) {
	if (N == 0 || N == 1)
		return N;

	return F(N - 1) + F(N - 2);
}

int main()
{
	printf("%d ", F(5));
	printf("%d ", F(45));
    return 0;
}


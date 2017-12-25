// function calling.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

void F2() {
	printf("Hello World by F2\n");
}

void F1() {
	int c = 30, d = 40;
	F2();
	printf("c+d %d\n", c + d);
}

int main()
{
	int a = 10, b = 20;
	F1();
	printf("a+b %d\n", a + b);
    return 0;
}


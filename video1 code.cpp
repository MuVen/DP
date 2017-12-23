// DP.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
// Dynamic Programming !!!
// smart recurssion.

// recurssion - a function calling itself.
// there should base or terminating condition to avoid stack overflow.

// write a program to print 5 to 1.
void printNumbers(int N) {
	if (N == 0)
		return;

	printf("%d ", N);
	printNumbers(N - 1);
}

//write a program to prnt 10^5;
/*
    10 ^ 5 = 10 * 10 ^ 4
	              10 * 10 ^ 3
				         10 * 10 ^ 2
						      10 * 10 ^ 1
							        10 * 10 ^ 0
	*/

int power10(int N) {
	if (N == 0)
		return 1;

	return 10 * power10(N - 1);
}

// write a program to print a ^ b.
/*    5 ^ 3 = 5 * 5 ^ 2
                  5 * 5 ^ 1
				       5 * 5 ^ 0
*/

int apowerb(int a, int b)
{
	if (b == 0)
		return 1;

	return a * apowerb(a, b - 1);
}

// write a program for gcd.
/*
    GCD of 12, 42
	    12 ) 42 ( 3
		     36
			 __
			 6 ) 12 ( 2
			     12
				 __
				  0
*/

int GCD(int a, int b) {
	if (a == 0)
		return b;

	return GCD(b%a, a);
}

// write a recursive function which returns sum of all numbers 
// from 1 to N
int sum(int N) {
	if (N == 1)
		return 1;

	return N + sum(N - 1);
}

// write a recursive function which returns product of all numbers
// from 1 to N.
int prod(int N) {
	if (N == 1)
		return 1;

	return N * prod(N - 1);
}

int main()
{
	for (int i = 5; i > 0; i--)
		printf("%d ", i);
	printf("\nPrinting using recurssion\n");
	printNumbers(5);
	printf("\n10^5 is %d\n", power10(5));
	printf("\n5^3s is %d\n", apowerb(5,3));
	printf("\n12, 42 GCD is %d\n", GCD(12, 42));
	printf("\nsum is %d\n", sum(5));
	printf("\nprod is %d\n", prod(5));
    return 0;
}


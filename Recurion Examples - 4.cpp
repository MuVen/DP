// function calling.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

/*
  10 ^ 5 = 10 * 10 ^ 4
                10 * 10 ^ 3
				      10 * 10 ^ 2
					        10 * 10 ^ 1
							      10 * 10 ^ 0
								          1
*/

int tenpowerx(int N) {
	if (N == 0)
		return 1;

	return 10 * tenpowerx(N - 1);
}

/*
    a ^ b ; 5 ^ 3 = 5 * 5 ^ 2
	                    5 * 5 ^ 1
						     5 * 5 ^ 0
							       1
*/

int apowerb(int a, int b) {
	if (b == 0)
		return 1;

	return a * apowerb(a, b - 1);
}


/*
    GCD of a, b; 12, 42
	12 ) 42 ( 3
	     36
		 __
		 6 ) 12 ( 2
		     12
			 __
			 0 ) 6 ( 

*/

int gcd(int a, int b) {
	if (a == 0)
		return b;

	return gcd(b%a, a);
}

int sumofN(int N) {
	if (N == 1)
		return 1;

	return N + sumofN(N - 1);
}

int prodofN(int N) {
	if (N == 1)
		return 1;

	return N * prodofN(N - 1);
}

int main()
{
	printf("%d \n", tenpowerx(5));
	printf("%d \n", apowerb(5,3));
	printf("%d \n", gcd(12, 42));
	printf("%d \n", sumofN(5));
	printf("%d \n", prodofN(5));
    return 0;
}


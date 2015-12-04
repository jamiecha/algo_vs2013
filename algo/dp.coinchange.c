/*
http://www.geeksforgeeks.org/dynamic-programming-set-7-coin-change/
*/
#include <stdio.h>

static int br;

static int coins[3] = {1,2,3};

static int solve(int amount){
	return 0;
}

void dp_coinchange(void){
	int r;
	r = solve(4);
	printf("possible cases are : %d\n",r);
	br = 1;
	return;
}
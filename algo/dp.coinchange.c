/*
http://www.geeksforgeeks.org/dynamic-programming-set-7-coin-change/
*/
#include <stdio.h>
#include <string.h>

static int br;

// case 1: 
//#define TYPE_COINS 3
//#define AMOUNT 4 
//static int coin[TYPE_COINS] = {1,2,3};

// case 2:
#define TYPE_COINS 4
#define AMOUNT 10
static int coin[TYPE_COINS] = { 2, 3, 5, 6 };


//====================================================================
static int callcount = 0;
static int solve_naive(int last_entry, int amount){

	callcount++;
	if (amount == 0){
		printf("found!\n");
		return 1;
	}

	if (amount < 0){
		return 0;
	}

	if (last_entry < 0){
		return 0;
	}

	/* include the last coin / do not include the last coin */
	return solve_naive(last_entry, amount - coin[last_entry]) + solve_naive(last_entry - 1, amount);
}


//====================================================================
static int dp_table[AMOUNT + 1][TYPE_COINS];
static int solve_dp(void){

	int a, t;
	int incl, excl;

	memset(dp_table, 0, sizeof(int)*TYPE_COINS*(AMOUNT + 1));

	// amount = 0 always has 1 solution : {}
	for (t = 0; t < TYPE_COINS; t++){
		dp_table[0][t] = 1;
	}

	for (a = 1; a <= AMOUNT; a++){
		for (t = 0; t < TYPE_COINS; t++){

			// include this coin
			if (a - coin[t] >= 0)
				incl = dp_table[a - coin[t]][t];
			else
				incl = 0;

			// exclude this coin
			if (t >= 1)
				excl = dp_table[a][t - 1];
			else
				excl = 0;

			dp_table[a][t] = incl + excl;
			br = 1;
		}
	}

	return dp_table[AMOUNT][TYPE_COINS - 1];
}



/*
N = 4 and S = {1,2,3} : {1,1,1,1},{1,1,2},{2,2},{1,3}
N = 10 and S = {2,3,5,6} : {2,2,2,2,2}, {2,2,3,3}, {2,2,6}, {2,3,5}, {5,5}
*/
void dp_coinchange(void){
	int r;
	//r = solve_naive(TYPE_COINS-1, AMOUNT);
	r = solve_dp();
	printf("possible cases are : %d (%d)\n", r, callcount);
	br = 1;
	return;
}

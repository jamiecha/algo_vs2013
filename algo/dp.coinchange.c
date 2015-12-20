/*
http://www.geeksforgeeks.org/dynamic-programming-set-7-coin-change/
*/
#include <stdio.h>
#include <string.h>

static int br;
static int count;

#define case 3

#if case==1
#define TYPE_COINS 3
#define AMOUNT 4 
static int coin[TYPE_COINS] = {1,2,3};
#elif case==2
#define TYPE_COINS 4
#define AMOUNT 10
static int coin[TYPE_COINS] = { 2, 3, 5, 6 };
#elif case==3
#define TYPE_COINS 4
#define AMOUNT 100
static int coin[TYPE_COINS] = { 5, 10, 20, 50 };
#else
#error "no matching case"
#endif

//====================================================================

static int stack[AMOUNT];
static int sp;

static void print_stack(void){
	int i;
	for (i = 0; i < sp; i++){
		printf("%d-", stack[i]);
	}
	printf("\n");
}

static int callcount = 0;
static void solve_naive(int idx, int amount){

	callcount++;
	if (amount == 0){
		count++;
		print_stack();
		return;
	}

	if (amount < 0){
		return;
	}

	if (idx == TYPE_COINS){
		return;
	}

	/* include coin[idx] */
	stack[sp++] = coin[idx];
	solve_naive(idx, amount - coin[idx]);
	sp--;

	/* do not include coin[idx] */
	solve_naive(idx + 1, amount);

	return;
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
	count = 0; sp = 0;
	solve_naive(0, AMOUNT);
	//count = solve_dp();
	printf("possible cases are : %d (%d)\n", count, callcount);
	br = 1;
	return;
}

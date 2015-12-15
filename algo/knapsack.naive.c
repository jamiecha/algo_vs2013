/* from http://www.geeksforgeeks.org/dynamic-programming-set-10-0-1-knapsack-problem/ */

#include <stdio.h>
static int br;

static int val[] = { 30, 40, 50, 80, 100 };
static int wei[] = { 1, 3, 6, 7, 9 };
static int W = 20;
static int N = sizeof(val) / sizeof(val[0]);


static int max(int a, int b){
	if (a > b)
		return a;
	else
		return b;
}

static int callcount = 0;

// Returns the "maximum value" that can be put in a knapsack of (remaining) capacity W
static int knapsack(int W, int n){

	int v_include, v_exclude;
	printf("n=%d, W=%d\n", n, W);

	callcount++;

	// base case
	if (n == 0 || W <= 0)
		return 0;

	// If weight of the nth item is more than (remaining) Knapsack capacity W, then
	// this item cannot be included in the optimal solution
	if (wei[n - 1] > W)
		return knapsack(W, n - 1);
	// Return the maximum of two cases: (1) nth item included (2) not included
	else{
		v_include = val[n - 1] + knapsack(W - wei[n - 1], n - 1);
		v_exclude = knapsack(W, n - 1);
		return max(v_include, v_exclude);
	}

}


void knapsack_naive(void){

	int r;
	r = knapsack(W, N);
	printf("val=%d,(call=%d)\n", r, callcount);

	br = br;
	return;
}


/*

In the following recursion tree, K() refers to knapSack().  The two
parameters indicated in the following recursion tree are n and W.
The recursion tree is for following sample inputs.

W = 2,
wt[] = {1, 1, 1},
val[] = {10, 20, 30}

K ( 3 , 2 )  ---------> K(n, W)
/             \
/                 \
K(2,2)                    K(2,1)
/     \                   /    \
/       \                 /      \
K(1,2)      K(1,1)          K(1,1)     K(1,0)
/  \        /   \          /  \
/    \      /     \        /    \
K(0,2) K(0,1) K(0,1) K(0,0) K(0,1) K(0,0)

Recursion tree for Knapsack capacity 2 units and 3 items of 1 unit weight.

*/
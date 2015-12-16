/* from http://www.geeksforgeeks.org/dynamic-programming-set-10-0-1-knapsack-problem/ */

#include <stdio.h>
static int br;

static int val[] = { 30, 40, 50, 80, 100 };
static int wei[] = { 1, 3, 6, 7, 9 };
static int W = 20;
static int N = sizeof(val) / sizeof(val[0]);
static int callcount = 0;
static int maxvsum = 0;



static int max(int a, int b){
	if (a > b)
		return a;
	else
		return b;
}


static int knapsack(int idx, int wsum, int vsum){

	callcount++;

	if (wsum > W)
		return 0;

	if (vsum > maxvsum){
		maxvsum = vsum;
		printf("new=%d\n", maxvsum);
	}

	if (idx == N)
		return 0;

	return max(maxvsum, max(knapsack(idx + 1, wsum, vsum),
		knapsack(idx + 1, wsum + wei[idx], vsum + val[idx]))
		);

}


void knapsack_naive(void){

	int r;
	r = knapsack(0, 0, 0);
	printf("val=%d,(call=%d)\n", r, callcount);

	br = 1;
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
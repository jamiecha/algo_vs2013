/*
http://www.geeksforgeeks.org/dynamic-programming-set-13-cutting-a-rod/

length   | 1   2   3   4   5   6   7   8
--------------------------------------------
price    | 1   5   8   9  10  17  17  20

max price = price of 2 + price of 6 = 22
*/

#include <stdio.h>
static int br;

#define L 8
static int P[L + 1] = { 0, 1, 5, 8, 9, 10, 17, 17, 20 };
static int pmax;

static int stack_l[L];
static int stack_p[L];
static int sp;

static int max(int a, int b){ if (a > b)return a; else return b; }


static void cut_dp(void){
	int len, cut, max_value;
	int mv[L+1]; // dp table

	mv[0] = 0;

	for(len=1;len<=L;len++){
		// find the maximum price sum for this length
		max_value = -1;
		for(cut=1;cut<=len;cut++){
			max_value = max( max_value, P[cut] + mv[len-cut] );
		}
		mv[len] = max_value;
	}
	pmax = mv[L];
	return;
}


static void cut_naive(int remain, int psum){
	int i;
	if (remain == 0){
		if (psum > pmax){
			pmax = psum;
			for (i = 0; i < sp; i++)
				printf("%d(%d)->", stack_l[i], stack_p[i]);
			printf("%d\n", psum);
		}
		return;
	}
	else{
		for (i = 1; i <= remain; i++){
			stack_l[sp] = i;
			stack_p[sp++] = P[i];
			cut_naive(remain - i, psum + P[i]);
			sp--;
		}
	}
	return;
}

void dp_cutting_a_rod(void){
	pmax = 0;
	sp = 0;
	cut_naive(L, 0);
	printf("max price sum (naive) : %d\n", pmax);
	pmax = 0;
	cut_dp();
	printf("max price sum (dp) : %d\n", pmax);
	br = 1;
	return;
}
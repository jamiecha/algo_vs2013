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
	//TODO
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
	printf("max price sum : %d\n", pmax);
	br = 1;
	return;
}
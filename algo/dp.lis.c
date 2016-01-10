/*
< Longest Increasing Subsequence >
http://www.geeksforgeeks.org/dynamic-programming-set-3-longest-increasing-subsequence/
*/

#include <stdio.h>

static int br;

#define N 20
static int arr[N] = {
	10, 20, 1, 9, 11, 19, 2, 8, 12, 18,
	5, 15, 4, 6, 14, 16, 3, 7, 13, 17
};

static int stack[N + 1];
static int sp;
static int max_len;

static int max(int a, int b){
	if (a > b)
		return a;
	else
		return b;
}

static void print_stack(void){
	int i;
	for (i = 0; i < sp; i++)
		printf("%d ", stack[i]);
	printf("\n");
}


static int rec(int pos, int prev_val, int len){

	int r, r1, r2;

	if (pos >= N - 1){
		if (len > max_len){
			max_len = len;
			print_stack();
		}
		return len;
	}

	if (arr[pos + 1] > prev_val){
		stack[sp++] = arr[pos + 1];
		r1 = rec(pos + 1, arr[pos + 1], len + 1);   // include this
		sp--;
		r2 = rec(pos + 2, prev_val, len);           // exclude this
		r = max(r1, r2);
	}
	else{
		r = rec(pos + 1, prev_val, len);            // cannot include this
	}
	return r;
}


static int lis_naive(int n){

	int i, r;
	max_len = 1;

	for (i = 0; i < n; i++){
		sp = 0;
		stack[sp++] = arr[i];
		r = rec(i, arr[i], 1);
	}

	return max_len;
}



//===========================================================

static int lis[N];

int lis_dp(int n)
{
	int end, start, max_lis = 1;

	/* base case : lis of each is always 1 */
	for (end = 0; end < n; end++)
		lis[end] = 1;

	/* 0~1, 0~2, 0~3, ... 0~n - keep updating lis[end] */
	for (end = 1; end < n; end++)
		for (start = 0; start < end; start++)
			if (arr[end] > arr[start] && lis[end] < lis[start] + 1)
				lis[end] = lis[start] + 1;

	for (end = 0; end < n; end++)
		max_lis = max(max_lis, lis[end]);

	return max_lis;
}

void dp_lis(void){
	sp = 0;
	printf("lis-dp:%d\n", lis_dp(N));
	printf("lis-naive:%d\n", lis_naive(N));
	br = 1;
}

/* http://www.geeksforgeeks.org/dynamic-programming-set-1/ */

#include <stdio.h>

static int br;

#define MAXN 100
static int cache[MAXN];

static int fibo_dp(int n){

	if (n == 0 || n == 1)
		return n;

	if (cache[n] == -1){
		cache[n] = fibo_dp(n-1) + fibo_dp(n-2);
	}

	return cache[n];

}


static int fibo_naive(int n){
	if (n == 0 || n == 1)
		return n;

	return fibo_naive(n - 1) + fibo_naive(n - 2);

}


static int fibo_tabulation(int n){
	int i;
	cache[0] = 0;
	cache[1] = 1;
	for (i = 2; i <= n; i++){
		cache[i] = cache[i-1] + cache[i-2];
	}
	return cache[n];
}

void fibo(void){
	int r;

	for (r = 0; r < MAXN; r++)
		cache[r] = -1;
	
	//r = fibo_dp(40);
	//r = fibo_naive(30);
	r = fibo_tabulation(40);

	printf("fibo=%d\n",r);
	br = 1;
	return;
}
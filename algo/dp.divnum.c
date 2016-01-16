/*
수 분할 문제
*/
#include <stdio.h>
static int br;

/*
divnum(5,3) =
1+1+1+1+1
2+1+1+1
2+2+1
...
4+1
5
*/

#define N 50
#define M 30
#define N2 30

static int cache[N + 1][M + 1];
static int divnum_dp(int n, int m){

	int i, r = 0;

	if (n < m)
		m = n;

	if (cache[n][m] != -1)
		return cache[n][m];

	if (n == 0){
		return cache[n][m] = 1;
	}

	for (i = 1; i <= m; i++){
		r += divnum_dp(n - i, i);
	}
	return cache[n][m] = r;
}


static int divnum_naive(int n, int m){

	int i, r = 0;

	if (n < m)
		m = n;

	if (n == 0)
		return 1;

	for (i = 1; i <= m; i++){
		r += divnum_naive(n - i, i);
	}
	return r;
}


/* get all permutation of partition ( 1+2, 2+1 are different )
   divnum_permu_naive(3)=3, divnum_permu_naive(4)=8
   */
static int divnum_permu_naive(int n){
	int i;
	int r = 0;

	if (n == 0)
		return 1;

	for (i = 1; i <= n; i++){
		if (n >= i)
			r += divnum_permu_naive(n - i);
	}
	return r;
}

static int cache2[N2 + 1];
static int divnum_permu_dp(int n){
	int i;
	int r = 0;

	if (n == 0){
		return 1;
	}

	if (cache2[n] != -1)
		return cache2[n];

	for (i = 1; i <= n; i++){
		if (n >= i)
			r += divnum_permu_naive(n - i);
	}
	return cache2[n] = r;
}



void dp_divnum(void){
	int r;
	int n, m;

	// naive recursive
	r = divnum_naive(N, M);
	printf("divnum(%d,%d)=%d\n", N, M, r);

	// DP
	for (n = 0; n < N + 1; n++)
		for (m = 0; m < M + 1; m++)
			cache[n][m] = -1;
	r = divnum_dp(N, M);
	printf("divnum(%d,%d)=%d\n", N, M, r);

	// permutation version - naive
	r = divnum_permu_naive(N2);
	printf("divnum_permu(%d)=%d\n", N2, r);

	// permutation version - DP
	for (n = 0; n < N2 + 1; n++)
		cache2[n] = -1;
	r = divnum_permu_dp(N2);
	printf("divnum_permu_dp(%d)=%d\n", N2, r);

	br = 1;
	return;
}
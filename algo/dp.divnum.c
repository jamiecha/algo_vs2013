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

#define N 80
#define M 30

int cache[N+1][M+1];
int divnum_dp(int n, int m){

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


int divnum_naive(int n, int m){

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


void dp_divnum(void){
	int r;
	int n, m;

	r = divnum_naive(N, M);
	printf("divnum(%d,%d)=%d\n", N, M, r);

	for (n = 0; n < N + 1; n++)
		for (m = 0; m < M + 1; m++)
			cache[n][m] = -1;

	r = divnum_dp(N, M);
	printf("divnum(%d,%d)=%d\n", N, M, r);

	br = 1;
	return;
}
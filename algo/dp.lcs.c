/*
< Longest Common Subsequence >
http://www.geeksforgeeks.org/dynamic-programming-set-4-longest-common-subsequence/
*/

#include <stdio.h>
static int br;
static int callcount = 0;

static char s1[] = "AGGTAB";
static char s2[] = "GXTXAYB";
#define L1 6
#define L2 7


static int max(int a, int b){
	if (a > b)
		return a;
	else
		return b;
}


static int cache[L1 + 1][L2 + 1];
static int solve_dp(char s1[], char s2[], int len1, int len2){
	callcount++;
	if (len1 == 0 || len2 == 0)
		return 0;

	if (s1[len1 - 1] == s2[len2 - 1]){
		if (cache[len1][len2] == -1)
			cache[len1][len2] = 1 + solve_dp(s1, s2, len1 - 1, len2 - 1);
		printf("%c(%d)[%d,%d] ", s1[len1 - 1], cache[len1][len2], len1, len2);
		return cache[len1][len2];
	}
	else{

		if (cache[len1 - 1][len2] == -1)
			cache[len1 - 1][len2] = solve_dp(s1, s2, len1 - 1, len2);

		if (cache[len1][len2 - 1] == -1)
			cache[len1][len2 - 1] = solve_dp(s1, s2, len1, len2 - 1);

		// guess why MAX here !!!
		return max(cache[len1 - 1][len2], cache[len1][len2 - 1]);
	}

}


static int solve_naive(char s1[], char s2[], int len1, int len2){

	callcount++;
	if (len1 == 0 || len2 == 0)
		return 0;

	if (s1[len1 - 1] == s2[len2 - 1]){
		return 1 + solve_naive(s1, s2, len1 - 1, len2 - 1);
	}
	else{
		// guess why MAX here !!!
		return max(solve_naive(s1, s2, len1 - 1, len2), solve_naive(s1, s2, len1, len2 - 1));
	}
}


void dp_lcs(void){

	int r;
	int l1, l2;

	// naive
	callcount = 0;
	r = solve_naive(s1, s2, L1, L2);
	printf("common=%d, callcnt=%d\n", r, callcount);

	// DP
	for (l1 = 0; l1 <= L1; l1++)
		for (l2 = 0; l2 <= L2; l2++)
			cache[l1][l2] = -1;
	callcount = 0;
	r = solve_dp(s1, s2, L2, L2);
	printf("common=%d, callcnt=%d\n", r, callcount);

	br = 1;
	return;
}

/*
http://www.geeksforgeeks.org/dynamic-programming-subset-sum-problem/
백트래킹 연습
배열 a[] 의 원소들을 조합하여 총 합이 N 이 되는 부분집합의 갯수를 구해라
*/

#include <stdio.h>

static int br;

#define N 25
static int a[N] =
{
	10, 7, 5, 18, 12, 20, 15, 10, 7, 5, 
	18, 12, 20, 15, 10, 7, 5, 18, 12, 20, 
	36, 37, 38, 40, 41
};

#define TARGET 219
static int anscount = 0;
static int callcount = 0;

static int stack[N];
static int sp;

static void subsetsum(int idx, int sum){
	callcount++;
	if (sum == TARGET){
		anscount++;
		return;
	}
	else if (sum > TARGET || idx == N){
		return;
	}
	else{
		// exclude this item
		subsetsum(idx + 1, sum);

		// include this item
		stack[sp++] = a[idx];
		subsetsum(idx + 1, sum + a[idx]);
		sp--;
	}
	return;
}


void backtrack_subsetsum(void){

	anscount = 0;
	callcount = 0;
	sp = 0;

	subsetsum(0, 0);
	printf("# of answers=%d, callcount=%d\n", anscount, callcount);
	br = 1;
	return;

}
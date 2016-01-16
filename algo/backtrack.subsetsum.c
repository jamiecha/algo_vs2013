/*
http://www.geeksforgeeks.org/dynamic-programming-subset-sum-problem/
��Ʈ��ŷ ����
�迭 a[] �� ���ҵ��� �����Ͽ� �� ���� N �� �Ǵ� �κ������� ������ ���ض�
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
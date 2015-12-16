/* from http://www.geeksforgeeks.org/dynamic-programming-set-10-0-1-knapsack-problem/ */

#include <stdio.h>

static int br;

#define W 20
#define N 5

// index 0 에 가라값 주의
static int val[] = { 0, 30, 40, 50, 80, 100 };
static int wei[] = { 0, 1, 3, 6, 7, 9 };
static int matrix[N + 1][W + 1];

#define MAX(a,b) (((a)>(b))?(a):(b))

// W : max weight
// w : 0..W ( every possible weight )
// n : 0..N ( number of possible items )

void knapsack_dp(void){
	int w, n;
	int value_a, value_b;

	for (n = 0; n <= N; n++){
		for (w = 0; w <= W; w++){
			if (n == 0 || w == 0){
				matrix[n][w] = 0;
			}
			// 현재의 무게 (wei[n]) 가 현재의 무게합(w) 를 넘어서는 경우는 이전결과 재활용.
			else if (wei[n] > w){
				matrix[n][w] = matrix[n - 1][w];
			}
			else{
				// 현재의 value (val[n] (무게는 wei[n])) 를 포함하는 경우와 그렇지 않은 경우 (이전matrix값) 중 큰 것.
				value_a = val[n] + matrix[n - 1][w - wei[n]]; // 무게의 합은 w !!
				value_b = matrix[n - 1][w];                 // 무게의 합은 w !!
				matrix[n][w] = MAX(value_a, value_b);
			}
		}
	}

	//print matrix
	for (n = 0; n <= N; n++){
		for (w = 0; w <= W; w++){
			printf("%3d ", matrix[n][w]);
		}
		printf("\n");
	}

	printf("max value = %d", matrix[N][W]);
	br = 1;
	return;
}

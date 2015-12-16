/* from http://www.geeksforgeeks.org/dynamic-programming-set-10-0-1-knapsack-problem/ */

#include <stdio.h>

static int br;

#define W 20
#define N 5

// index 0 �� ���� ����
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
			// ������ ���� (wei[n]) �� ������ ������(w) �� �Ѿ�� ���� ������� ��Ȱ��.
			else if (wei[n] > w){
				matrix[n][w] = matrix[n - 1][w];
			}
			else{
				// ������ value (val[n] (���Դ� wei[n])) �� �����ϴ� ���� �׷��� ���� ��� (����matrix��) �� ū ��.
				value_a = val[n] + matrix[n - 1][w - wei[n]]; // ������ ���� w !!
				value_b = matrix[n - 1][w];                 // ������ ���� w !!
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

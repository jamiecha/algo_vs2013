#include <stdio.h>

extern void sort_bubble(void);
extern void backtrack_basic(void);
extern void knapsack_naive(void);
extern void knapsack_dp(void);
extern void fibo(void);
extern void lis(void);
extern void test_malloc(void);
extern void backtrack_subsetsum(void);

int main(void){

	//sort_bubble();
	//backtrack_basic();
	//knapsack_naive();
	//knapsack_dp();
	//fibo();
	//lis();
	//test_malloc();

	backtrack_subsetsum();

	return 0;
}
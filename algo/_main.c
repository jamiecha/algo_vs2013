#include <stdio.h>

extern void backtrack_basic(void);
extern void backtrack_subsetsum(void);
extern void backtrack_nqueen(void);

extern void knapsack_naive(void);
extern void knapsack_dp(void);

extern void dp_fibo(void);
extern void dp_lis(void);

extern void sort_bubble(void);

extern void util_malloc(void);



int main(void){

	//sort_bubble();
	//backtrack_basic();
	//knapsack_naive();
	//knapsack_dp();
	//dp_fibo();
	//dp_lis();
	//backtrack_subsetsum();

	backtrack_nqueen();

	//util_malloc();
	return 0;
}
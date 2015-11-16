#include <stdio.h>

//
// find combination of array that sum > THR
//

#define N 4
#define THR 9
static int array[N] = { 1, 2, 4, 8 };
static int answer[N] = { 0};
static int callcount = 0;

static void process_solution(int ans[], int k){
	int i;
	for (i = 0; i<k; i++){
		if (ans[i])
			printf("%3d ", array[i]);
	}
	printf("\n");
}

static int sum(int k){

	int i, s = 0;
	for (i = 0; i < k; i++){
		if (answer[i])
			s += array[i];
	}
	return s;
}

static void backtrack(int ans[], int k){

//	int i;
	callcount++;
	if (sum(k)>=THR){ // is_a_solution()
		process_solution(ans, k);
	}
	else if (k == N){
		//do nothing
	}
	else{
#if 0
		for (i = 1; i >= 0; i--){
			ans[k] = i;
			backtrack(ans, k + 1);
		}
#else
		ans[k] = 1;
		backtrack(ans, k + 1);
		ans[k] = 0;
		backtrack(ans, k + 1);
#endif
	}
}


void backtrack_basic(void){

	backtrack(answer, 0);
	printf("callcount=%d\n", callcount);

}
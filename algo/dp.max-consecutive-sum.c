/*
 find maximum sum of "consecutive numbers" in an array N long
 this could have been done by all combination of 
 start ~ end but it takes too long if N is very large.
*/

#include <stdio.h>
#include <stdlib.h> // for rand()

static int br;

#define N 10
static int array[N];
static int cache[N];


static void generate_int(int n){
	int i;
	for (i = 0; i < n; i++){
		array[i] = rand() % 200 - 100;  // -100 ~ 99
	}
}



static int find_csum(int n){
	int i, max_sum;
	cache[0] = array[0];

	for (i = 1; i < n; i++){
		cache[i] = max(array[i], array[i] + cache[i - 1]);
	}

	max_sum = 0;
	for (i = 0; i < n; i++){
		max_sum = max(cache[i], max_sum);
	}

	return max_sum;
}


void dp_max_consecutive_sum(void){
	generate_int(N);
	printf("%d\n",find_csum(N));
	br = 1;
	return;
}


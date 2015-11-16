#include <stdio.h>
#include <malloc.h>
#include <time.h>

static int br;

static void _test_malloc(void){

	int i;
	int *p = malloc(sizeof(int) * 100);

	for (i = 0; i < 100; i++){
		p[i] = i;
	}

	free(p);
	return;
}

void test_malloc(void){

	int i;
	clock_t start, end;
	float seconds;
	
	start = clock();

	for (i = 0; i < 1000*1000; i++){
		_test_malloc();
	}

	end = clock();
	seconds = (float)(end - start) / CLOCKS_PER_SEC;
	printf("time=%f\n", seconds);

	br = 1;
	return;

}
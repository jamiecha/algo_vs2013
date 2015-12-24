#include <stdio.h>
static int br;
/*
greycode : only 1 bit flips to the next move
000
001
011
010
110
111
101
100
*/

#define MAXN 10
static int code[MAXN] = { 0, };

static int mypow(int x, int y){
	int r = x;
	while (--y){
		r = r*x;
	}
	return r;
}


static void print_code(int n){
	int i;
	for (i = n - 1; i >= 0; i--){
		printf("%d", code[i]);
	}
	printf("\n");
}


static void greycode(int n){

	int idx;
	int count = 0;
	while (count < mypow(2, n)){
		count++;
		print_code(n);
		for (idx = 1; idx <= n; idx++){
			if (count % (mypow(2, idx) / 2) == 0){
				if (count%mypow(2, idx) == 0){
					// skip flip
				}
				else{
					// flip
					code[idx - 1] = (code[idx - 1] + 1) % 2;
				}
			}
		}
	}

}


void etc_greycode(void){
	greycode(4);
	br = 1;
	return;
}
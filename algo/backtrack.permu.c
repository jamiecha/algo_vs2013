/*
list permutaion of a given string "ABC"
http://www.geeksforgeeks.org/write-a-c-program-to-print-all-permutations-of-a-given-string/
*/

#include <stdio.h>
static int br;

#define L 3
static char *str = "ABC";
static int used[L];
static char stack[L];
static int sp = 0;
static int callcount;

static void push(char c){
	stack[sp] = c;
	sp++;
}

static void pop(void){
	sp--;
}

static void permu(char s[], int len){
	int i;
	callcount++;
	if (len == 0){
		for (i = 0; i < L; i++)
			printf("%c", stack[i]);
		printf("\n");
		return;
	}

	for (i = 0; i < L; i++){
		if (!used[i]){
			used[i] = 1; push(s[i]);
			permu(s, len - 1);
			used[i] = 0; pop();
		}
	}
	return;
}

void backtrack_permu(void){
	int i;
	for (i = 0; i < L; i++)
		used[i] = 0;
	sp = 0; callcount = 0;
	permu(str, L);
	printf("callcount=%d\n",callcount);
	br = 1;
	return;
}
/*
http://www.geeksforgeeks.org/dynamic-programming-set-5-edit-distance/
*/
#include <stdio.h>

static int br;

static int solve(char *s1, char *s2, int ls1, int ls2){
	int i;

	for (i = 0; i < ls1; i++)
		printf("%c", s1[i]);

	printf("\n");

	for (i = 0; i < ls2; i++)
		printf("%c", s2[i]);

	printf("\n");
	return 1;
}

void dp_edit_distance(void){

	char s1[] = "saturday";
	char s2[] = "sunday";

	solve(s1, s2, 8, 6);

	br = 1;
	return;
}
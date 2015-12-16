/*
http://www.geeksforgeeks.org/dynamic-programming-set-6-min-cost-path/
*/
#include <stdio.h>
static int br;

#define X 3
#define Y 3
/*
static int map[Y][X] = {
	{ 1, 2, 3 },
	{ 4, 8, 2 },
	{ 1, 5, 3 }
};
*/

static int solve(int x, int y, int ex, int ey){
	return 1;
}

void dp_mincostpath(void){
	int r;
	r = solve(0, 0, X - 1, Y - 1);
	printf("min cost = %d\n", r);
	br = 1;
	return;
}

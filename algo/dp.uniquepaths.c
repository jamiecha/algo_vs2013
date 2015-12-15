/* find cases of shortest paths in 5x6 matrics (1,1) to (5,4) 
http://articles.leetcode.com/2010/11/unique-paths.html
*/

#include <stdio.h>
static int br;

#define X 6
#define Y 5

static int ways;
static int callcount;


// DP
static int cache[Y][X];
static int dp_unique_paths_impl(void){

	int x, y;

	for (x = 0; x < X; x++)
		cache[0][x] = 1;

	for (y = 0; y < Y; y++)
		cache[y][0] = 1;

	for (y = 1; y < Y;y++){
		for (x = 1; x < X;x++){
			cache[y][x] = cache[y][x-1] + cache[y-1][x];
		}
	}

	return cache[Y-1][X-1];
}

// memoization
static int memo[Y+1][X+1];
static int recur_memo(int x, int y){
	callcount++;

	printf("x=%d y=%d\n", x, y);
	if (x > X || y > Y)
		return 0;

	if (x == X && y == Y)
		return 1;

	if (memo[y+1][x] == -1)
		memo[y+1][x] = recur_memo(x,y+1);

	if (memo[y][x+1] == -1)
		memo[y][x+1] = recur_memo(x+1, y);

	memo[y][x] = memo[y][x+1] + memo[y+1][x];
	return memo[y][x];
}

// naive recursive
static int recur_naive(int x, int y){
	callcount++;
	if (x > X || y > Y)
		return 0;
	if (x == X && y == Y)
		return 1;
	return recur_naive(x + 1, y) + recur_naive(x, y + 1);
}



void dp_unique_paths(void){

	int x, y;

	// naive

	callcount = 0;
	ways = recur_naive(1, 1);
	printf("ways=%d, callcount=%d\n", ways, callcount);


	// memo

	for (y = 0; y <= Y; y++)
		for (x = 0; x <= X; x++)
			memo[y][x] = -1;
	callcount = 0;
	ways = recur_memo(1, 1);
	printf("ways=%d, callcount=%d\n", ways, callcount);


	// DP

	ways = dp_unique_paths_impl();
	printf("ways=%d\n", ways);

	br = 1;
	return;
}




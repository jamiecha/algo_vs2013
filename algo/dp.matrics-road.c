#include <stdio.h>
static int br;

/* find cases of shortest paths in 5x6 matrics x:0~4, y:0~5 
   (0,0) to (5,4)
*/

#define X 6
#define Y 5

// DP
static int cache[Y][X];
void dp_matrics_road(void){

	int x, y;

	for (x = 0; x < X; x++)
		cache[0][x] = 1;

	for (y = 0; y < Y; y++)
		cache[y][0] = 1;

	for (y = 1; y < Y;y++){
		for (x = 1; x < X;x++){
			cache[y][x] = cache[y][x - 1] + cache[y - 1][x];
		}
	}

	printf("ways=%d\n",cache[Y-1][X-1]);
	br = 1;
	return;
}

static int ways;
static int callcount;

static int memo[Y][X];
static void recur_memo(int x, int y){
	callcount++;
	if (x > X - 1 || y > Y - 1)
		return;
	if (x == X - 1 && y == Y - 1){
		//found solution
		ways++;
		return;
	}
	memo[y][x] = 1;
	if (memo[y][x+1]==0)
		recur_memo(x+1, y);
	if (memo[y+1][x]==0)
		recur_memo(x, y+1);
	return;
}

static void recur(int x, int y){
	callcount++;
	if (x > X - 1 || y>Y - 1)
		return;
	if (x == X - 1 && y == Y - 1){
		//found solution
		ways++;
		return;
	}
	recur(x + 1, y);
	recur(x, y + 1);
	return;
}

void bfs_matrics_road(void){

	int x, y;
	for (y = 0; y < Y; y++)
		for (x = 0; x < X; x++)
			memo[y][x] = 0;
	ways = 0; 
	callcount = 0;
	//recur(0, 0);
	recur_memo(0, 0);
	printf("ways=%d, callcnt=%d\n",ways,callcount);
	br = 1;
	return;
}







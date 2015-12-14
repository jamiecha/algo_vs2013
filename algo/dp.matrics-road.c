#include <stdio.h>
static int br;

/* find cases of shortest paths in 5x6 matrics x:0~4, y:0~5 
   (0,0) to (5,4)
*/

#define X 6
#define Y 5
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
/*
1) find the number of ways to reach pyramid bottom

2) find the minimum cost path from the top to bottom
4
3 8
3 2 1
6 4 3 2
1 3 2 6 1

*/

#include <stdio.h>
static int br;

#define H 5
static int py[H][H];
static int cache[H][H];
static int cost[H*H] = { 4, 3, 8, 3, 2, 1, 6, 4, 3, 2, 1, 3, 2, 6, 1 };

static int min(int a, int b){
	if (a < b)
		return a;
	else
		return b;
}

static void print_pyramid(int arr[][H]){
	int x, y;
	for (y = 0; y < H; y++){
		for (x = 0; x < H; x++){
			printf("%d ", arr[y][x]);
		}
		printf("\n");
	}
	printf("\n");
}

static void pyramid_cases(void){
	int x, y;

	for (y = 0; y < H; y++){
		py[y][0] = 1;  // left edge
	}

	for (y = 0; y < H; y++){
		py[y][y] = 1;  // right edge
	}

	for (y = 2; y < H; y++){
		for (x = 1; x < y; x++){
			py[y][x] = py[y - 1][x - 1] + py[y - 1][x];
		}
	}
	print_pyramid(py);
}

static void pyramid_minsum(void){
	int x, y, i = 0;

	for (y = 0; y < H; y++){
		for (x = 0; x <= y; x++){
			py[y][x] = cost[i++];
		}
	}

	cache[0][0] = py[0][0];

	for (y = 1; y < H; y++){
		cache[y][0] = cache[y - 1][0] + py[y][0];  // left edge
	}

	for (y = 1; y < H; y++){
		cache[y][y] = cache[y - 1][y - 1] + py[y][y]; // right edge
	}

	for (y = 2; y < H; y++){
		for (x = 1; x < y; x++){
			cache[y][x] = py[y][x] + min(cache[y - 1][x - 1], cache[y - 1][x]);
		}
	}

	print_pyramid(cache);

}

void dp_number_pyramid(void){
	pyramid_cases();
	pyramid_minsum();
	br = 1;
	return;
}
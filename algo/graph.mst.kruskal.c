/*
http://www.geeksforgeeks.org/greedy-algorithms-set-2-kruskals-minimum-spanning-tree-mst/
http://scanftree.com/Data_Structure/kruskal's-algorithm
목적 : 그래프상의 모든점을 연결하는 tree 이되 edge 의 총 합이 최소
*/
#include <stdio.h>

static int br;
#define INF 0xffff
#define N 6
static int G[N][N] = {
     /* 0  1  2  3  4  5  */
/*0*/ { 0, 3, 1, 6, 0, 0 },
/*1*/ { 3, 0, 5, 0, 3, 0 },
/*2*/ { 1, 5, 0, 5, 6, 4 },
/*3*/ { 6, 0, 5, 0, 0, 2 },
/*4*/ { 0, 3, 6, 0, 0, 6 },
/*5*/ { 0, 0, 4, 2, 6, 0 }
};

static int parent_of[N];

static int root_of(int v){

	while (parent_of[v] != -1){
		v = parent_of[v];
	}
	return v;
}

static int solve(void){

	int n = 0;
	int min_dist;
	int total_dist = 0;
	int x, y, minx, miny;

	// adjust graph ( 0 to infinity )
	for (y = 0; y < N; y++){
		for (x = 0; x < N; x++){
			if (G[y][x] == 0)
				G[y][x] = INF;
		}
	}

	// everyone is orphan at the beginning
	for (y = 0; y < N;y++)
		parent_of[y] = -1;

	// connect N-1 edges for N vertices
	while (n < N-1){

		// find the shortest edge 
		// --> this could have been done by having sorted edge list beforehand
		min_dist = INF;
		for (y = 0; y < N; y++){
			for (x = 0; x < N; x++){
				if (G[y][x] < min_dist){
					min_dist = G[y][x];
					minx = x; miny = y;
				}
			}
		}
		G[miny][minx] = G[minx][miny] = INF;

		// makjang scenario ?
		x = root_of(minx);
		y = root_of(miny);

		// if they are not family yet, connect them.
		if (x!=y){
			parent_of[x] = y;
			total_dist += min_dist;
			printf("adding %d %d (%d)\n",minx,miny,min_dist);
			n++;
		}

	}

	return total_dist;
}


void graph_mst_kruskal(void){

	int r;
	r = solve();
	printf("mincost=%d\n",r);
	br = 1;
	return;
}
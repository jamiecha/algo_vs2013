/*
http://www.geeksforgeeks.org/greedy-algorithms-set-6-dijkstras-shortest-path-algorithm
http://blog.naver.com/jojoldu/90184758192
https://compprog.wordpress.com/2007/12/01/one-source-shortest-path-dijkstras-algorithm

목적 : 그래프상의 임의의 두 점간 최단거리
*/

#include <stdio.h>
static int br;

/*
            8        7
       (1)-----(2)-----(3)
     4/  |      |\      | \
     /   |     2| \     |  \9
   (0)   |11   (8) \    |   \
     \   |    / |   \4  |14 (4)
     8\  |  7/  |6   \  |  /
       \ |  /   |     \ | /10
        (7)----(6)----(5)
             1      2
*/

#define INFINITY 9999
#define MAX(a, b) ((a > b) ? (a) : (b))

#define V 9
#define GRAPHSIZE V
/* map[i][j] is the distance between node i and j; or 0 if there is no direct connection */
int map[V][V] = {
//  0  1  2  3  4  5  6  7  8
  { 0, 4, 0, 0, 0, 0, 0, 8, 0 }, // 0
  { 4, 0, 8, 0, 0, 0, 0,11, 0 }, // 1
  { 0, 8, 0, 7, 0, 4, 0, 0, 2 }, // 2
  { 0, 0, 7, 0, 9,14, 0, 0, 0 }, // 3
  { 0, 0, 0, 9, 0,10, 0, 0, 0 }, // 4
  { 0, 0, 4,14,10, 0, 2, 0, 0 }, // 5
  { 0, 0, 0, 0, 0, 2, 0, 1, 6 }, // 6
  { 8, 11,0, 0, 0, 0, 1, 0, 7 }, // 7
  { 0, 0, 2, 0, 0, 0, 6, 7, 0 }  // 8
};

static int n; /* The number of nodes in the graph */
static int dist[V]; /* dist[i] is the length of the shortest path between the source (s) and node i */
static int prev[V]; /* prev[i] is the node that comes right before i in the shortest path from the source to i*/
static int visited[V];

static void print_all_distance() {
	int i;

	printf("Distances:\n");
	for (i = 0; i < n; i++)
		printf("%3d", i);
	printf("\n");
	for (i = 0; i < n; i++) {
		printf("%3d", dist[i]);
	}
	printf("\n");
}

/*
* Prints the shortest path from the source to dest.
*
* dijkstra(int) MUST be run at least once BEFORE
* this is called
*/
static void print_path(int dest) {
	if (prev[dest] != -1)
		print_path(prev[dest]);
	printf("%d ", dest);
}

static void dijkstra(int start) {
	int i, k, min_index, min_dist;

	for (i = 0; i < n; i++) {
		dist[i] = INFINITY;
		prev[i] = -1; /* no path has yet been found to i */
		visited[i] = 0; /* the i-th element has not yet been visited */
	}

	dist[start] = 0;

	for (k = 0; k < n; k++) {

		min_dist = INFINITY;

		/* find the nearest vertex among non-visited ones */
		for (i = 0; i < n; i++){
			if (!visited[i]){
				if ( dist[i] <= min_dist ){
					min_index = i;
					min_dist = dist[min_index];
				}
			}
		}

		visited[min_index] = 1;

		for (i = 0; i < n; i++){
			if (map[min_index][i]) /* among neighbours of min_index node ... */
				/* which path is shorter between ( source ~ min_index ~ i ) and ( source ~ i ) ? */
				if (dist[min_index] + map[min_index][i] < dist[i]) { 
					dist[i] = dist[min_index] + map[min_index][i];
					prev[i] = min_index;
				}
		}

		br = 1;
	}
}

void graph_dijkstra(void){
	int i;
	n = V;

	dijkstra(0);
	print_all_distance();

	printf("\n");
	for (i = 0; i < n; i++) {
		printf("Path to %d: ", i);
		print_path(i);
		printf("\n");
	}

	br = 1;
	return;
}
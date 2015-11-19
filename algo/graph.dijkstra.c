/*
	http://www.geeksforgeeks.org/greedy-algorithms-set-6-dijkstras-shortest-path-algorithm
	http://blog.naver.com/jojoldu/90184758192
	https://compprog.wordpress.com/2007/12/01/one-source-shortest-path-dijkstras-algorithm
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

#define INFINITY 2^31
#define MAX(a, b) ((a > b) ? (a) : (b))


#define V 9
#define GRAPHSIZE V
/* map[i][j] is the distance between node i and j; or 0 if there is no direct connection */
int map[V][V] = {
	{ 0, 4, 0, 0, 0, 0, 0, 8, 0 },
	{ 4, 0, 8, 0, 0, 0, 0, 11, 0 },
	{ 0, 8, 0, 7, 0, 4, 0, 0, 2 },
	{ 0, 0, 7, 0, 9, 14, 0, 0, 0 },
	{ 0, 0, 0, 9, 0, 10, 0, 0, 0 },
	{ 0, 0, 4, 0, 10, 0, 2, 0, 0 },
	{ 0, 0, 0, 14, 0, 2, 0, 1, 6 },
	{ 8, 11, 0, 0, 0, 0, 1, 0, 7 },
	{ 0, 0, 2, 0, 0, 0, 6, 7, 0 }
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
	int i, k, mini;

	for (i = 0; i < n; i++) {
		dist[i] = INFINITY;
		prev[i] = -1; /* no path has yet been found to i */
		visited[i] = 0; /* the i-th element has not yet been visited */
	}

	dist[start] = 0;

	for (k = 0; k < n; k++) {
		mini = -1;
		for (i = 0; i < n; i++)
			if (!visited[i] && ((mini == -1) || (dist[i] < dist[mini])))
				mini = i;

		visited[mini] = 1;

		for (i = 0; i < n; i++)
			if (map[mini][i])
				if (dist[mini] + map[mini][i] < dist[i]) {
					dist[i] = dist[mini] + map[mini][i];
					prev[i] = mini;
				}
	}
}

void graph_dijkstra(void){
	int i;
	n = V;

	dijkstra(5);
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
/* http://www.geeksforgeeks.org/greedy-algorithms-set-6-dijkstras-shortest-path-algorithm/ */
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

#define V 9
static int graph[V][V] = {
{0, 4, 0, 0, 0, 0, 0, 8, 0},
{4, 0, 8, 0, 0, 0, 0, 11, 0},
{0, 8, 0, 7, 0, 4, 0, 0, 2},
{0, 0, 7, 0, 9, 14, 0, 0, 0},
{0, 0, 0, 9, 0, 10, 0, 0, 0},
{0, 0, 4, 0, 10, 0, 2, 0, 0},
{0, 0, 0, 14, 0, 2, 0, 1, 6},
{8, 11, 0, 0, 0, 0, 1, 0, 7},
{0, 0, 2, 0, 0, 0, 6, 7, 0}
};


// distance from vertex 0
static int dist[V];


static void dijkstra(void){


}


void graph_dijkstra(void){
	dijkstra();
	br=1;
	return;
}
#include <stdio.h>

extern void backtrack_basic(void);
extern void backtrack_subsetsum(void);
extern void backtrack_nqueen(void);
extern void backtrack_permu(void);

extern void knapsack_naive(void);
extern void knapsack_dp(void);

extern void dp_fibo(void);
extern void dp_lis(void);
extern void dp_edit_distance(void);
extern void dp_mincostpath(void);
extern void dp_unique_paths(void);
extern void bfs_matrics_road(void);
extern void dp_lcs(void);

extern void graph_dijkstra(void);
extern void graph_mst_kruskal(void);

extern void sort_bubble(void);
extern void temp(void);



int main(void){

	//sort_bubble();
	//backtrack_basic();
	//backtrack_subsetsum();
	//backtrack_nqueen();

	//knapsack_naive();
	knapsack_dp();
	//dp_fibo();
	//dp_lis();
	//dp_edit_distance();
	//dp_coinchange();

	//graph_dijkstra();

	//graph_mst_kruskal();
	//dp_unique_paths();
	//dp_lcs();
	//backtrack_permu();

	return 0;
}
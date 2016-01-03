#include <stdio.h>
static int br;

#define C 3
#define M 4

static int r[C][M + 1] = {
	{ 0, 2, 4, 7, 9 },
	{ 0, 3, 5, 6, 8 },
	{ 0, 1, 3, 7, 9 }
};

static int max_return[C][M + 1];

static void calculate_return(int n, int m){
	int i, j, k, max, t;

	for (i = 0; i <= m; i++)
		max_return[0][i] = r[0][i];

	for (i = 1; i < n; i++){
		for (j = 1; j <= m; j++){
			max = -1;
			for (k = 0; k <= j; k++){
				br = 1;
				t = max_return[i - 1][k] + r[i][j - k];
				if (t > max)
					max = t;
			}
			max_return[i][j] = max;
		}
	}
}

void dp_max_return(void){
	int n, m, i;

	n = C;
	m = M;

	for (i = 0; i < n; i++){
		r[i][0] = 0;
	}

	calculate_return(n, m);

	printf("max return: %d\n", max_return[n - 1][m]);
	br = 1;
	return;
}
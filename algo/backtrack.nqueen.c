#include <stdio.h>
extern double now(void);
extern double took(double a, double b);
int br;


#define NMAX 14
int board[NMAX][NMAX];
int ans = 0;


int diff(int a, int b){
	if (a > b)
		return a - b;
	else
		return b - a;
}


void print_board(int n){
	int x, y;
	for (y = 0; y < n; y++){
		for (x = 0; x < n; x++){
			printf("%d ", board[y][x]);
		}
		printf("\n");
	}
}


void init_board(int n){
	int x, y;
	for (y = 0; y < n; y++)
		for (x = 0; x < n; x++)
			board[y][x] = 0;
}


int is_safe1(int row, int col, int n){
	int x, y;

	// the first row
	if (row == 0){
		return 1;
	}

	// column collision
	for (y = 0; y < row; y++){
		if (board[y][col]){
			return 0;
		}
	}

	// diagonal collision
	for (y = 0; y < row; y++){
		for (x = 0; x < n; x++){
			if (board[y][x])
				if (diff(row, y) == diff(col, x)){
					return 0;
				}
		}
	}

	// everything is okay
	return 1;

}


int is_safe2(int row, int col, int n){
	int x, y;

	// the first row
	if (row == 0){
		return 1;
	}

	// column collision
	for (y = 0; y < row; y++){
		if (board[y][col]){
			return 0;
		}
	}

	// diagonal left-back collision
	x = col - 1;
	y = row - 1;
	while (x >= 0 && y >= 0){
		if (board[y][x])
			return 0;
		x--; y--;
	}

	// diagonal right-back collision
	x = col + 1;
	y = row - 1;
	while (x < n && y >= 0){
		if (board[y][x])
			return 0;
		x++; y--;
	}

	// everything is okay
	return 1;

}



void nqueen(int row, int n){

	int col;

	if (row == n){
		//printf("nqueen:%d\n",row);
		//print_board(n);
		ans++;
		return;
	}

	for (col = 0; col < n; col++){
		if (is_safe2(row, col, n)){      // compare safe1 & safe2
			board[row][col] = 1;
			nqueen(row + 1, n);
			board[row][col] = 0;
		}
	}

	return;

}


void backtrack_nqueen(void){
	int n;
	double s, e;
	for (n = 4; n <= NMAX; n++){
		s = now();
		init_board(n);
		ans = 0;
		nqueen(0, n);
		e = now();
		printf("%d %d took=%f\n", n, ans, took(s, e));
	}

	br = 1;
	return;
}

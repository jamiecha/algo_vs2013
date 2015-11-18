#include <stdio.h>
int br;

#define NMAX 15

int board[NMAX][NMAX];
int ans = 0;


int diff(int a, int b){
	if(a>b)
		return a-b;
	else
		return b-a;
}


void print_board(int n){
	int x,y;
	for(y=0;y<n;y++){
		for(x=0;x<n;x++){
			printf("%d ",board[y][x]);
		}
		printf("\n");
	}
}


void init_board(int n){
	int x,y;
	for(y=0;y<n;y++)
		for(x=0;x<n;x++)
			board[y][x]=0;	
}


int is_safe(int row, int col, int n){
	int x,y;

	// the first row
	if(row==0){
		return 1;
	}

	// column collision
	for(y=0;y<row;y++){
		if(board[y][col]){
			return 0;
		}
	}

	// diagonal collision
	for(y=0;y<row;y++){
		for(x=0;x<n;x++){
			if(board[y][x])
				if(diff(row,y)==diff(col,x)){
					return 0;
				}
		}
	}

	// everything is okay
	return 1;

}


void nqueen(int row, int n){

	int col;

	if(row == n){
		//printf("nqueen:%d\n",row);
		//print_board(n);
		ans++;
		return;
	}

	for(col=0;col<n;col++){
		if(is_safe(row,col,n)){
			board[row][col] = 1;
			nqueen(row+1,n);
			board[row][col] = 0;
		}
	}

	return;

}


void backtrack_nqueen(void){
	int n;
	for(n=4;n<=NMAX;n++){
		init_board(n);
		ans = 0;
		nqueen(0,n);
		printf("%d %d\n",n,ans);
	}

	br = 1;
	return;
}

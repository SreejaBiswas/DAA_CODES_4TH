#include <stdio.h>
#include <stdlib.h>
void initialise(int n, int board[n][n]){
	int i = 0;
	while(i<n){
		int j = 0;
		while(j<n){
			board[i][j] = 0;
			j += 1;
		}
		i += 1;
	}
}
void printBoard(int n, int board[n][n]){
	int i = 0;
	while(i<n){
		int j = 0;
		while(j<n){
			printf("%d ", board[i][j]);
			j += 1;
		}
		i += 1;
		printf("\n");
	}
	printf("\n");
}
void swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}
void horizontal(int n, int board[n][n]){
	int i, j, k, mid = n/2;
	for(i = 0; i<n; i+=1){
		for(j = 0, k = n-1; j<=mid && k>=mid; j+=1, k-=1){
			if(board[i][j] || board[i][k])
				swap(&(board[i][j]), &(board[i][k]));
		}
	}
}
void vertical(int n, int board[n][n]){
	int i, j, k, mid = n/2;
	for(j = 0; j<n; j+=1){
		for(i = 0, k = n-1; i<=mid && k>=mid; i+=1, k-=1){
			if(board[i][j] || board[k][j])
				swap(&(board[i][j]), &(board[k][j]));
		}
	}
}
int isSafe(int n, int board[n][n], int r, int c){
	int i, j;
	for(i = 0; i<n; i+=1){
		if(board[i][c])
			return 0;
	}
	for(j = 0; j<n; j+=1){
		if(board[r][j])
			return 0;
	}
	for(i = r, j = c; i>=0 && j>=0; i-=1, j-=1){
		if(board[i][j])
			return 0;
	}
	for(i = r, j = c; i<n && j<n; i+=1, j+=1){
		if(board[i][j])
			return 0;
	}
	for(i = r, j = c; i>=0 && j<n; i-=1, j+=1){
		if(board[i][j])
			return 0;
	}
	for(i = r, j = c; i<n && j>=0; i+=1, j-=1){
		if(board[i][j])
			return 0;
	}
	return 1;
}
int n_queens(int n, int board[n][n], int r){
	if(r==n)
		return 1;
	int c = 0;
	while(c<n){
		if(isSafe(n, board, r, c)){
			board[r][c] = 1;
			if(n_queens(n, board, r+1))
				return 1;
			board[r][c] = 0;
		}
		c += 1;
	}
	return 0;
}
int main(){
	int n;
	printf("Enter the number of queens -> ");
	scanf("%d", &n);
	int board[n][n];
	initialise(n, board);
	if(n_queens(n, board, 0)){
		printBoard(n, board);
		horizontal(n, board);
		printBoard(n, board);
		vertical(n, board);
		printBoard(n, board);
		horizontal(n, board);
		printBoard(n, board);
	}
	else
		printf("No solution found\n");
	return 0;
}
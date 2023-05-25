#include <stdio.h>
#include<stdlib.h>
int** createMatrix(int rows, int cols) {
	int** matrix = (int**)malloc(rows * sizeof(int*));
	for (int i = 0; i < rows; i++) {
		matrix[i] = (int*)malloc(cols * sizeof(int));
	}
	return matrix;
}
void freeMatrix(int** matrix, int rows) {
	for (int i = 0; i < rows; i++) {
		free(matrix[i]);
	}
	free(matrix);
}
void add(int** a, int** b, int n, int** c) {
	int i, j;
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			c[i][j] = a[i][j] + b[i][j];
		}
	}
}
void sub(int** a, int** b, int n, int** c) {
	int i, j;
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			c[i][j] = a[i][j] - b[i][j];
		}
	}
}
void strassen(int n, int** a, int** b, int** c) {
	if (n == 1) {
		c[0][0] = a[0][0] * b[0][0];
		return;
	}
	int i, j;
	int** a11 = createMatrix(n/2, n/2);
	int** a12 = createMatrix(n/2, n/2);
	int** a21 = createMatrix(n/2, n/2);
	int** a22 = createMatrix(n/2, n/2);
	int** b11 = createMatrix(n/2, n/2);
	int** b12 = createMatrix(n/2, n/2);
	int** b21 = createMatrix(n/2, n/2);
	int** b22 = createMatrix(n/2, n/2);
	int** c11 = createMatrix(n/2, n/2);
	int** c12 = createMatrix(n/2, n/2);
	int** c21 = createMatrix(n/2, n/2);
	int** c22 = createMatrix(n/2, n/2);
	int** p1 = createMatrix(n/2, n/2);
	int** p2 = createMatrix(n/2, n/2);
	int** p3 = createMatrix(n/2, n/2);
	int** p4 = createMatrix(n/2, n/2);
	int** p5 = createMatrix(n/2, n/2);
	int** p6 = createMatrix(n/2, n/2);
	int** p7 = createMatrix(n/2, n/2);
	int** tmp1 = createMatrix(n/2, n/2);
	int** tmp2 = createMatrix(n/2, n/2);
	for (i = 0; i < n/2; i++) {
		for (j = 0; j < n/2; j++) {
			a11[i][j] = a[i][j];
			a12[i][j] = a[i][j + n/2];
			a21[i][j] = a[i + n/2][j];
			a22[i][j] = a[i + n/2][j + n/2];
			b11[i][j] = b[i][j];
			b12[i][j] = b[i][j + n/2];
			b21[i][j] = b[i + n/2][j];
			b22[i][j] = b[i + n/2][j + n/2];
		}
	}
	sub(b12, b22, n/2, tmp1);
	strassen(n/2, a11, tmp1, p1);
	add(a11, a12, n/2, tmp1);
	strassen(n/2, tmp1, b22, p2);
	add(a21, a22, n/2, tmp1);
	strassen(n/2, tmp1, b11, p3);
	sub(b21, b11, n/2, tmp1);
	strassen(n/2, a22, tmp1, p4);
	add(a11, a22, n/2, tmp1);
	add(b11, b22, n/2, tmp2);
	strassen(n/2, tmp1, tmp2, p5);
	sub(a12, a22, n/2, tmp1);
	add(b21, b22, n/2, tmp2);
	strassen(n/2, tmp1, tmp2, p6);
	sub(a11, a21, n/2, tmp1);
	add(b11, b12, n/2, tmp2);
	strassen(n/2, tmp1, tmp2, p7);
	add(p5, p4, n/2, tmp1);
	sub(tmp1, p2, n/2, tmp2);
	add(tmp2, p6, n/2, c11);
	add(p1, p2, n/2, c12);
	add(p3, p4, n/2, c21);
	add(p5, p1, n/2, tmp1);
	sub(tmp1, p3, n/2, tmp2);
	sub(tmp2, p7, n/2, c22);
	for (i = 0; i < n/2; i++) {
		for (j = 0; j < n/2; j++) {
			c[i][j] = c11[i][j];
			c[i][j + n/2] = c12[i][j];
			c[i + n/2][j] = c21[i][j];
			c[i + n/2][j + n/2] = c22[i][j];
		}
	}
	freeMatrix(a11, n/2);
	freeMatrix(a12, n/2);
	freeMatrix(a21, n/2);
	freeMatrix(a22, n/2);
	freeMatrix(b11, n/2);
	freeMatrix(b12, n/2);
	freeMatrix(b21, n/2);
	freeMatrix(b22, n/2);
	freeMatrix(c11, n/2);
	freeMatrix(c12, n/2);
	freeMatrix(c21, n/2);
	freeMatrix(c22, n/2);
	freeMatrix(p1, n/2);
	freeMatrix(p2, n/2);
	freeMatrix(p3, n/2);
	freeMatrix(p4, n/2);
	freeMatrix(p5, n/2);
	freeMatrix(p6, n/2);
	freeMatrix(p7, n/2);
	freeMatrix(tmp1, n/2);
	freeMatrix(tmp2, n/2);
}

int main() {
	int a[4][4] = {{4, 2, 0, 1},
			{8, 1, 2, 5},
			{3, 2, 1, 4},
			{5, 2, 6, 7}};

	int b[4][4] = {{2, 1, 3, 2},
			{5, 4, 2, 3},
			{1, 4, 0, 2},
			{3, 2, 4, 1}};

	int c[4][4];

	int** a_ptr = createMatrix(4, 4);
	int** b_ptr = createMatrix(4, 4);
	int** c_ptr = createMatrix(4, 4);

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			a_ptr[i][j] = a[i][j];
			b_ptr[i][j] = b[i][j];
		}
	}
	strassen(4, a_ptr, b_ptr, c_ptr);
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			c[i][j] = c_ptr[i][j];
			printf("%d ", c[i][j]);
		}
		printf("\n");
	}
	freeMatrix(a_ptr, 4);
	freeMatrix(b_ptr, 4);
	freeMatrix(c_ptr, 4);
	return 0;
}

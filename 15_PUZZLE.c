#include <stdio.h>
#include <stdlib.h>
#define ES 16
int *initialise(int n){
int *puzzle = (int *) malloc(sizeof(int)*n);
int memory[16] = {0};
int i;
puzzle[1] = 12;
puzzle[2] = 1;
puzzle[3] = 2;
puzzle[4] = 15;
puzzle[5] = 11;
puzzle[6] = 6;
puzzle[7] = 5;
puzzle[8] = 8;
puzzle[9] = 7;
puzzle[10] = 10;
puzzle[11] = 9;
puzzle[12] = 4;
puzzle[13] = ES;
puzzle[14] = 13;
puzzle[15] = 14;
puzzle[16] = 3;
return puzzle;
}
void printPuzzle(int n, int *puzzle){
int i;
for(i = 1; i<=n; i+=1){
 printf("%9d ", puzzle[i]);
 if(i%4 == 0)
 printf("\n");
}
printf("\n");
}
int pos(int i, int n, int *puzzle){
int j;
for(j = 1; j<=n; j+=1){
 if(puzzle[j] == i)
 return j;
}
return -1;
}
int g(int n, int *puzzle){
if(puzzle == NULL)
 return 999;
int i, count = 0;
for(i = 1; i<=n; i+=1){
 if(puzzle[i] == i)
 continue;
 count += 1;
}
return count;
}
int less(int i, int n, int *puzzle){
int j, count = 0;
int position = pos(i, n, puzzle);
for(j = position; j<=n; j+=1){
 if(puzzle[j] >= i)
 continue;
 count += 1;
}
return count;
}
int positionES(int n, int *puzzle){
int position = pos(ES, n, puzzle);
switch(position){
 case 2:
 case 4:
 case 5:
 case 7:
 case 10:
 case 12:
 case 13:
 case 15:
 return 1;
}
return 0;
}
int solvable(int n, int *puzzle){
int x = positionES(n, puzzle);
int i, count = x;
for(i = 1; i<=n; i+=1){
 count += less(i, n, puzzle);
}
return count%2 == 0;
}
int isFinalState(int n, int *puzzle){
int i;
for(i = 1; i<n ; i+=1){
 if(pos(i, n, puzzle) != i)
 return 0;
}
return 1;
}
int *copy(int n, int *puzzle){
int i;
int *copyPuzzle = (int *) malloc(sizeof(int)*n);
for(i = 0; i<=n; i+=1){
 copyPuzzle[i] = puzzle[i];
}
return copyPuzzle;
}
int isSame(int n, int *puzzle, int *copy){
int i;
for(i = 1; i<=n; i+=1){
 if(puzzle[i] != copy[i])
 return 0;
}
return 1;
}
void swap(int *a, int *b){
int temp = *a;
*a = *b;
*b = temp;
}
int *upES(int n, int *puzzle){
int posES = pos(ES, n, puzzle);
if(posES >= 1 && posES <= 4)
 return NULL;
int i, *up = copy(n, puzzle);
swap(up+posES, up+posES-4);
return up;
}
int *downES(int n, int *puzzle){
int posES = pos(ES, n, puzzle);
if(posES >= 13 && posES <= 16)
 return NULL;
int i, *down = copy(n, puzzle);
swap(down+posES, down+posES+4);
return down;
}
int *leftES(int n, int *puzzle){
int posES = pos(ES, n, puzzle);
if(posES%4 == 1)
 return NULL;
int i, *left = copy(n, puzzle);
swap(left+posES, left+posES-1);
return left;
}
int *rightES(int n, int *puzzle){
int posES = pos(ES, n, puzzle);
if(posES%4 == 0)
 return NULL;
int i, *right = copy(n, puzzle);
swap(right+posES, right+posES+1);
return right;
}
int solve(int n, int *puzzle, int *previous){
if(isFinalState(n, puzzle)){
 printf("final state\n");
 printPuzzle(n, puzzle);
 return 1;
}
if(!(solvable(n, puzzle))){
 printf("dead state\n");
 printf("Configuration Unsolvable!\n");
 return 0;
}
int *up = upES(n, puzzle);
int *down = downES(n, puzzle);
int *left = leftES(n, puzzle);
int *right = rightES(n, puzzle);
if(up != NULL && g(n, up) <= g(n, down) && g(n, up) <= g(n, left) && g(n, 
up) <= g(n, right) && !(isSame(n, previous, up))){
 printf("up -> ");
 return solve(n, up, puzzle);
}
else if(down != NULL && g(n, down) <= g(n, left) && g(n, down) <= g(n, 
right) && !(isSame(n, previous, down))){
 printf("down -> ");
 return solve(n, down, puzzle);
}
else if(left != NULL && g(n, left) <= g(n, right) && !(isSame(n, previous, 
left))){
 printf("left -> ");
 return solve(n, left, puzzle);
}
else if(right != NULL && !(isSame(n, previous, right))) {
 printf("right -> ");
 return solve(n, right, puzzle);
}
return 0;
}
int main(){
int n = 16;
int *puzzle = initialise(n);
printPuzzle(n, puzzle);
solve(n, puzzle, puzzle);
return 0;
}
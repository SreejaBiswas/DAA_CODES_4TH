#include <stdio.h>
#include <stdlib.h>
int minimum_drops(int eggs, int floors){
	int i;
	for(i = 1; i<=floors; i+=1){
		if((i*(i+1))/2 >= floors)
			return i;
	}
	return -1;
}
int main(){
	int eggs, floors;
	printf("Enter number of eggs and floors -> ");
	scanf("%d%d", &eggs, &floors);
	int answer = minimum_drops(eggs, floors);
	printf("The minimum number of drops is %d\n", answer);
	return 0;
}

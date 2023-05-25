#include <stdio.h>
#include <stdlib.h>

int non_zero(int x){
	int non_zero_count = 0;
	while(x>0){
		if(x%10 != 0)
			non_zero_count += 1;
		x /= 10;
	}
	return non_zero_count;
}

void k_non_zero(int n, int k){
	int i = 1, count = 0;
	printf("The required number are ");
	while(i<=n){
		if(non_zero(i) == k){
			count += 1;
			printf("%d ", i);
		}
		i += 1;
	}
	printf("\nThe count is %d\n", count);
}

int main(){
	int n, k;
	printf("Enter N and K -> ");
	scanf("%d%d", &n, &k);
	k_non_zero(n, k);
	return 0;
}

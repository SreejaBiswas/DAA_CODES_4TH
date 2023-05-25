#include<stdio.h>
#include<limits.h>

int max(int a, int b) {
	return (a>b) ? a : b;
}

int max3(int a, int b, int c) {
	return max(max(a, b), c);
}

int maxMidSum(int arr[], int lb, int m, int ub) {
	int sum=0,i;
	int leftSum=INT_MIN;
	for(i=m; i>=lb; i--) {
		sum+=arr[i];
		if(sum>leftSum)
		leftSum=sum;
	}

	sum=0;
	int rightSum=INT_MIN;
	for(i=m; i<=ub; i++) {
		sum+=arr[i];
		if(sum>rightSum)
		rightSum=sum;
	}
	return max3(leftSum + rightSum-arr[m], leftSum, rightSum);	
}

int maxSubSum(int arr[], int lb, int ub) {
	if(lb>ub)
	return INT_MIN;
	
	if(lb==ub)
	return arr[lb];
	
	int m=(lb+ub)/2;
	
	return max3(maxSubSum(arr, lb, m-1), maxSubSum(arr, m+1, ub), maxMidSum(arr, lb, m, ub));
}

int main() {
	FILE *fptr;
	fptr=fopen("file2.txt", "rt");
	if(fptr==NULL) {
		printf("File not found");
		return 0;
	}

	char size[1000];
	fgets(size, 1000, fptr);
	int len=atoi(size);
	int arr[len],i=0;
	while(fscanf(fptr, "%d", &arr[i])!=EOF) {
		i++;
	}
	fclose(fptr);
	int maxSum=maxSubSum(arr, 0, len-1);
	printf("Max sub array sum: %d\n", maxSum);
}


7
12 -13 -5 25 -20 30 10
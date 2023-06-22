#include <stdio.h>
#include<stdlib.h>

int p(int A[],int low,int high)
{
	int pivot=A[low];
	int i=low+1;
	int j=high;
	int temp;
	do
	{
		while(A[i]<=pivot)
		{
			i++;
		}
		while(A[j]>pivot)
		{
			j--;
		}
		if(i<j)
		{
			temp=A[i];
			A[i]=A[j];
			A[j]=temp;
		}
	}while(i<j);
	temp=A[low];
	A[low]=A[j];
	A[j]=temp;
	return j;
}
void display(int A[],int n)
{
	int i;
	for(i=0;i<n;i++)
{
	printf("%d ",A[i]);
}
}
void quicksort(int A[],int low,int high)
{
	int partitionindex;
	if(low<high)
	{	
		partitionindex=p(A,low,high);
		quicksort(A,low,partitionindex-1);
		quicksort(A,partitionindex+1,high);
}
}

int main()
{
	int n,i;
	printf("Enter the number of elements: ");
	scanf("%d",&n);
	int A[n];
	printf("Enter your elements: ");
	for(i=0;i<n;i++)
{
	scanf("%d",&A[i]);
}
	printf("The unsorted array is: ");
	display(A,n);
	printf("\n");
	quicksort(A,0,n-1);
	printf("The sorted array is: ");
	
	display(A,n);
	return 0;
}

	

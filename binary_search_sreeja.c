#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
int binarySearch(int ar[], int low, int high, int key){
          if(low <= high){
            int mid = (low+high)/2;
           if(ar[mid] == key){
            return mid;
           }
           else if(ar[mid] < key)
            return binarySearch(ar,mid+1,high,key);
           else
            return binarySearch(ar,low,mid-1,key);
          }
          else 
            return -1;
      }
  
bool issorted(int ar[],int n)
{
		int i;

	for( i=0;i<n-1;i++)
	{
		if(ar[i]>ar[i+1])
			return false;
	}
	return true;
}

void sort(int ar[],int n)
{
int i;
int j;
for(i=0;i<n;i++)
{
		for(j=0;j<n-i-1;j++)
		{
			if(ar[j]>ar[j+1])
			{
				int temp= ar[j];
				ar[j]=ar[j+1];
				ar[j+1]=temp;
			}
		}
	}
}
int main(){
         int n,key,r,i,*ar,j,temp;
	printf("\nEnter the size of the array: ");
	scanf("%d",&n);
	ar=(int*)malloc(sizeof(int)*n);
	printf("Enter the data in array:\n");
	for(i=0;i<n;i++)
	scanf("%d",&ar[i]);
	
	if(!issorted(ar,n)){
	sort(ar,n);
	printf("Sorted :");
	for(i=0;i<n;i++) 
	printf(" %d",ar[i]);
	}
         printf("\nEnter the key to be searched: ");
         scanf("%d",&key);
         r=binarySearch(ar,0,n-1,key);
         if(r == -1)
         printf("Element not found\n");
         else
         printf("Element found at %dth index:\n",r);
         return 0;
   }
         

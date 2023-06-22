#include<stdio.h>

void swap(int *a,int *b)
{
  int t=*a;
      *a=*b;
       *b=t;
}
void Heapify(int arr[],int i,int size)
{
  int left=2*i+1;
  int right=left+1;
  int max=i;
  if(left<=size && arr[left]>arr[max])
       max=left;
  if(right<=size && arr[right]>arr[max])
       max=right;
  if(max!=i)
  {
    swap(&arr[max],&arr[i]);
    Heapify(arr,max,size);
  }

}

void buildheap(int arr[],int size)
{
  int i;
  for(i=size/2;i>=0;i--)
     Heapify(arr,i,size); 
}

void heapsort(int arr[],int size)
{
  buildheap(arr,size);
  while(size>0)
  {
     swap(&arr[0],&arr[size--]);
     Heapify(arr,0,size);
  }
}

int main()
{
  int n,i,k,f;
  printf("enter number of element you want to insert");
  scanf("%d",&n);
  int arr[n];
  printf("Enter elements\n");
  for(i=0;i<n;i++)
    scanf("%d",&arr[i]);
  
  heapsort(arr,n-1);
  
  for(i=0;i<n;i++)
    printf("%d  ",arr[i]);
   
return 0;
}

#include<stdio.h>
#include<stdlib.h>

int max(int ar[],int l,int h)
{
	if(l<=h)
	{
	int m= (l+h)/2,a,b;
	if(l==h) 
	return ar[m];
	a=max(ar,l,m);
	b=max(ar,m+1,h);
	return a>b?a:b;
	}
}

int min(int ar[],int l,int h)
{
	if(l<=h)
	{
	int m= (l+h)/2,a,b;
	if(l==h) 
	return ar[m];
	a=min(ar,l,m);
	b=min(ar,m+1,h);
	return a<b?a:b;
	}
}

int main()
{
	int n,mi,ma,i;
	printf("Enter the size of the array: ");
	scanf("%d",&n); int ar[n];
	printf("Enter the elements\n");
	for(i=0;i<n;i++) 
	scanf("%d",&ar[i]);
	ma=max(ar,0,n-1);
	mi=min(ar,0,n-1);
	printf("The min will be : %d",mi);
	printf("\n");
	printf("The max will be: %d",ma);
	printf("\n");
	return 0;
}

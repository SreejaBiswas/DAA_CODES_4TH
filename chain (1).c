#include<stdio.h>
#include<limits.h>
void iniM(int n,int M[n][n])
{
	int i,j;
	for(i=1;i<n;i++)
	{
		for(j=1;j<n;j++)
		{
			if(i==j)
			{
				M[i][j]=0;
			}
			else if(i>j)
			{
				M[i][j]= 1;
			}
			else if(i<j)
			{
				M[i][j]= INT_MAX;
			}
		}
	}
	
}
void MDisplay(int n,int M[n][n])
{

	int i,j;
	for(i=1;i<n;i++)
	{
		for(j=1;j<n;j++)
		printf("%d\t",M[i][j]);
		printf("\n");
	}
}
int chainvalue(int n,int M[n][n],int arr[],int K[n][n])
{
	int i,j,k,temp;
	for(i=n-2;i>=1;i--)
	{
		for(j=i+1;j<n;j++)
		{
			for(k=i;k<=j-1;k++)
			{
				temp=M[i][k]+M[k+1][j]+(arr[i-1]*arr[k]*arr[j]);
				if(temp<M[i][j])
				{
					M[i][j]=temp;
					K[i][j]=k;
				}
				
			}
		}
			
	}
	return M[1][n-1];
}
void parenthesize(int l,int h,int n,int K[n][n])
{
	if(l==h)
	{
		printf("A%d",l);
		return;
	}
	printf("(");
	parenthesize(l,K[l][h],n,K);
	printf("*");
	parenthesize(K[l][h]+1,h,n,K);
	printf(")");

}
int main()
{
	int i=0,n,v,Min;
	char x[25];
	printf("Enter the filename with extension: ");
	scanf("%s",x);
	FILE *file=fopen(x,"r");
	if(file==NULL)
	{
		printf("File not found.\n");
		return 0;
		
	}
	fscanf(file,"%d",&n);// No. of sequence
	int arr[n];
	printf("The sequence of the matrices are : ");
	while(fscanf(file,"%d",&arr[i])!=EOF)
	{
		printf("%d ",arr[i]);
		i++;
	}
	printf("\n");
	int M[i][i];//adjecency matrix ,so 2 i's
	int K[i][i];//for parenthesisation
	iniM(i,M);///i =7
	iniM(i,K);
	Min=chainvalue(i,M,arr,K);
	printf("MATRIX: \n");
	MDisplay(i,M);
	printf("Minimum number of multiplication required is: %d\n\n",Min);
	printf("K-Table: \n");
	MDisplay(i,K);
	printf("Optimal Parenthesis is: \n");
	parenthesize(1,i-1,i,K);
	printf("\n");
	return 0;
}



5 10 3 12 5 50 6
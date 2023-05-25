#include <stdio.h>
int freq(int *a, int x)
{
	int i, c = 0;
	for(i = 0; i < 10; i++)
	{
		if(a[i] == x)
			c++;
	}
	return c;
}
void main()
{
	int i, a=1;
	int ar[10]={0};
	while(a--)
	{
		for(i = 0; i < 10; i++)
		{
			if(ar[i] != freq(ar, i))
			{
				a++;
				ar[i] = freq(ar, i);
			}
		}
	}
	printf("The 10 digit number is: ");
	for(i = 0; i < 10; i++)
		printf("%d", ar[i]);
	printf("\n");
}



//Find the only 10 digit number where the digit at the ith position (i = 0, 1, 2, 3 etc.) from left specifies the number of occurrences of digit "i" in the given number.





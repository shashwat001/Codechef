#include <stdio.h>

int main()
{
	int n,k,i,sum;
	scanf("%d",&n);
	sum = 0;
	for(i = 0;i < n;i++)
	{
		scanf("%d",&k);
		sum+=k;
	}
	int count = 0;
	for(i = 1;i <=5;i++)
	{
		if((sum+i)%(n+1) != 1)
			count++;
	}
	printf("%d",count);
	return 0;
}

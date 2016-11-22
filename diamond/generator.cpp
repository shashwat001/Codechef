#include <cstdio>

int main()
{
	int t,n,k,i;
	t = 500;
	printf("%d\n",t);
	while(t--)
	{
		n = 2000;
		printf("%d\n",n);
		k = 1000;
		for(i = 0;i < n;i++)
		{
			printf("%d ",k);
		}
		printf("\n");
	}
	return 0;
}

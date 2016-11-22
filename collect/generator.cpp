#include <bits/stdc++.h>

int main()
{
	int n = rand()%100000 + 1;
	n = 100000;
	printf("%d\n",n);
	int i;
	for(i = 0;i < n;i++)
	{
		int m = rand()%30;
		printf("%d ",m);
	}
	int q = rand()%100000 + 1;
	q = 1;
	printf("%d\n",q);
	for(i = 0;i < q;i++)
	{
		printf("query 1 100000");
	}
	return 0;
}

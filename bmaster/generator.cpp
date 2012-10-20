#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	srand(time(NULL));
	int n,m,q,p1[6],p2[6],x,y,i,k;
	long long t;
	n = rand()%5+1;
	k = 34/n;
	//m = rand()%k+1;
	m = rand()%5+1;
	q = rand()%500+1;
	x = rand()%n + 1;
	y = rand()%m + 1;
	printf("%d %d %d\n%d %d\n",n,m,q,x,y);
	for(i = 0;i < 6;i++)
	{
		p1[i] = rand()%n+1;
		p2[i] = rand()%m+1;
		printf("%d %d\n",p1[i],p2[i]);
	}
	for(i = 0;i < q;i++)
	{
		t = rand()%10000000000000000+1;
		printf("%lld\n",t);
	}
	return 0;
}

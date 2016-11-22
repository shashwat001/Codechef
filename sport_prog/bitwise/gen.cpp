#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int d[1010001] = {0};
int main()
{
	srand(time(NULL));
	int i;
	int n = 500;

	int k = 1000;
	long long a,b,c;
	printf("1\n%d\n",k);
	n = rand()%k;
	printf("%d\n",n);
	
	for(i = 0;i < n;i++)
	{
		a = rand()%k+1;
		b = rand()%k+1;
		if(a==b)
		{
			i--;
			continue;
		}
		c =a*1000+b;
		if(d[c] == 1)
		{
			i--;
			continue;
		}
		d[c] = 1;
		c = b*1000 + a;
		d[c] = 1;
		printf("%lld %lld\n",a,b);
	}
	return 0;
}

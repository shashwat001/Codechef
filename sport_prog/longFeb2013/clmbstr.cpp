#include <stdio.h>

#define MOD 1000000007

int f[1000001],cn,g,k,i,t,n;

int main()
{
	f[1] = 1;
	f[2] = 2;
	for(i = 3;i <= 1000000;i++)
	{
		f[i] = (f[i-1]+f[i-2])%MOD;
	}
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d",&n,&g);
		k = f[n];
		cn = 0;
		while(k > 0)
		{
			if(k&1)
			{
				cn++;
			}
			k >>= 1;
		}
		if(cn==g)
		{
			printf("CORRECT\n");
		}
		else
			printf("INCORRECT\n");
	}
	return 0;
}

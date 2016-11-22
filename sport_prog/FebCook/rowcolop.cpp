#include <stdio.h>

int main()
{
	int r[1000000]={0},c[1000000] = {0},n,q,i,maxc = 0,maxr = 0,k,l;
	char str[100];
	scanf("%d %d",&n,&q);
	while(q--)
	{
		scanf("%s %d %d",str,&k,&l);
		if(str[0] == 'R')
		{
			r[k] += l;
			if(r[k] > maxr)
				maxr = r[k];
		}
		else
		{
			c[k] += l;
			if(c[k] > maxc)
				maxc = c[k];
		}
	}
	printf("%d",maxr+maxc);
}

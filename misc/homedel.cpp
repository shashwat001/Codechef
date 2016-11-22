#include <stdio.h>
#include <string.h>

int main()
{
	int n,a[251][251],m,s,g,d,i,j,k;
	scanf("%d",&n);
	for(i = 0;i < n;i++)
	{
		for(j = 0;j < n;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
	for(k = 0;k < n;k++)
	{
		for(i = 0;i < n;i++)
		{
			for(j = 0;j < n;j++)
			{
				if(a[i][j] > a[i][k]+a[k][j])
				{
					a[i][j] = a[i][k]+a[k][j];
				}
			}
		}
	}
	scanf("%d",&m);
	for(i =0;i < m;i++)
	{
		scanf("%d %d %d",&s,&g,&d);
		printf("%d %d\n",a[s][g]+a[g][d],a[s][g]+a[g][d]-a[s][d]);
	}
	return 0;
}

#include <cstdio>
#include <cstring>

int main()
{
	int Min[10000],i,j,min,m,n,INF = 100000000,R,d;
	int v[] = {1,4,5,7,8};
	n = 5;
	while(1)
	{
		scanf("%d",&m);
		memset(Min,0,sizeof(Min));
		for(i = 1;i<=m;i++)
		{
			min = INF;
			for(j = 0;j<n;j++)
			{
				R = i-v[j];
				if(R < 0)
					continue;
				d = Min[R]+1;
				if(d < min)
					min = d;
			}
			Min[i] = min;
		}
		printf("%d\n",Min[m]);
	}
	return 0;
}

#include <stdio.h>
#include <string.h>

using namespace std;






/********************************************************************************************/


#define MAXM 10000000
int i,j,k,cnt;
int a[1001] = {-2};
int b[1001],d[31][31],e[31][31],sum,x,y,t,n,p,px,py;
int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};
int check;
int inbds(int x,int y,int n)
{
	if(x>=0 && x<n && y>=0 && y<n)
		return 1;
	return 0;
}

int main()
{
	int cnt = 0,l;
	for(i = 2;i < MAXM;i++)
	{
		if(a[i]==(-1))
			continue;
		a[i] = cnt++;
		for(k = i+i; k <= MAXM;k+=i)
		{
			a[k] = -1;
		}
	}
	a[0] = -1;
	a[1] = -1;
	scanf("%d",&t);
	while(t--)
	{
		memset(e,0,sizeof(e));
		sum = 0;
		scanf("%d",&n);
		for(i = 0;i < n;i++)
		{
			for(j = 0;j < n;j++)
			{
				scanf("%d",&d[i][j]);
			}
		}
		
		
		for(i = 0;i < n;i++)
		{
			for(j = 0;j < n;j++)
			{
				if(a[d[i][j]]>=0)
				{
					sum+=a[d[i][j]];
					continue;
				}
				if((e[i][j] == 1) || (e[i][j] == 2))
					continue;
				if(d[i][j]&1)
				{
					for(k = 0;k < 4;k++)
					{
						x = i+dx[k];
						y = j+dy[k];
						if(inbds(x,y,n))
						{
							if(e[x][y] == 1)
								break;
						}
					}
					if(k==4)
					{
						sum+=(d[i][j]+3)/2;
						for(p = 0;p < 2;p++)
						{
							px = i+dx[p];
							py = j+dy[p];
							if(inbds(px,py,n))
							{
								if(a[d[px][py]]<0)
								{
									if(d[px][py]&1)
										e[px][py] = 1;
								}
							}
						}
						e[i][j] = 1;
					}
				}//dij odd
				else
				{
					for(k = 0;k < 4;k++)
					{
						x = i+dx[k];
						y = j+dy[k];
						if(inbds(x,y,n))
						{
							if(e[x][y] == 2)
								break;
						}
					}
					if(k==4)
					{
						sum+=d[i][j]/2;
						for(p = 0;p < 2;p++)
						{
							px = i+dx[p];
							py = j+dy[p];
							if((px>=0) && (px<n) && (py>=0) && (py<n))
							{
								if(a[d[px][py]]<0)
								{
									if(d[px][py]&1==0)
										e[px][py] = 2;
								}
							}
						}
						e[i][j] = 2;
					}
				}
			}
		}
		printf("%d\n",sum);
	}
	return 0;
}

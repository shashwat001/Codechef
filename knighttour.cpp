#include <cstdio>
#include <cstring>

inline bool inbounds(int i,int j,int m,int n)
{
	return (i>=0 && i<m && j>=0 && j<n);
}

int di[] = {-2,-1,-2,-1,+2,+1,+2,+1};
int dj[] = {-1,-2,+1,+2,-1,-2,+1,+2};

int main()
{
	int i,j,m,n,minm,mini,minj,count,r,c,p,q,ii,jj,tc = 0,t;
	bool visited[101][101];
	scanf("%d",&t);
	scanf("%d %d",&m,&n);
	//scanf("%d %d",&r,&c);
	while(t--)
	{
		tc = 0;
		r = 0;
		c = 0;
		//memset(moves,8,sizeof(moves));
		memset(visited,0,sizeof(visited));
		while(1)
		{
			tc++;
			//printf("%d %d\n",r,c);
			visited[r][c] = 1;
			minm = 9;
			for(p = 0;p < 8;p++)
			{
				i = r+di[p];
				j = c+dj[p];
				if(inbounds(i,j,m,n))
				{
					if(visited[i][j]==0)
					{
						count = 0;
						for(q = 0;q<8;q++)
						{
							ii = i+di[q];
							jj = j+dj[q];
							if(inbounds(ii,jj,m,n))
							{
								if(visited[i][j]==0)
									count++;
							}
						}
						if(count && count < minm)
						{
							minm = count;
							mini = i;
							minj = j;
						}
					}
				}
			}
			if(minm == 9)
				break;
			r = mini;
			c = minj;
		}
		for(i = 0;i < m;i++)
		{
			for(j = 0;j < n;j++)
			{
				if(visited[i][j] != 0)
				{
					printf("No\n");
					break;
				}
			}
			if(j!=n)
				break;
		}
		if(i==m)
			printf("Yes\n");
		//printf("%d\n",tc);
	}
	return 0;
}

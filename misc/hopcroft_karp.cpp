#include <cstdio>
#include <cstring>
#include <queue>

int x[] = {-2,-2,-1,-1,1,1,2,2};
int y[] = {-1,1,-2,2,-2,2,-1,1};

queue<pair<int,int> > q;

char seen[100][100] = {0};

bool inlimit(int r,int c)
{
	if(r>=0 && r<n && c>=0 && c<n)
		return true;
	return false;
}

bool DFS(int i,int j)
{
	for(p = 0;p <8;p++)
	{
		r = i+x[p];
		s = j+y[p];
	}
}

bool BFS()
{
	pair<int,int> pr;
	for(i = 0;i < n;i++)
	{
		for(j = 0;j < n;j++)
		{
			if((i&1) == (j&1))
			{
				if(seen[i][j]==0)
				{
					dist[v] = 0;
					q.push(make_pair(i,j));
				}
				else
				{
					dist[v] = INF;
				}
			}
		}
	}
	while(!q.empty)
	{
		pr = q.pop();
	}
}

int hopcroft()
{
	matching = 0,p,q;
	
	while(BFS())
	{
		for(i = 0;i < n;i++)
		{
			for(j = 0;j < n;j++)
			{
				if((i&1) == (j&1))
				{
					if(seen[i][j]==0)
						if(DFS(i,j))
							matching+=1;
				}
			}
		}
	}
}

int main()
{
	int a[100][100];
	memset(a,0,sizeof(a));
	hopcroft();
	return 0;
}

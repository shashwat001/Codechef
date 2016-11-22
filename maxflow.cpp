#include <bits/stdc++.h>
using namespace std;

bool inbounds(int x,int y,int m,int n)
{
	return (x>=0 && x<m && y>=0 && y<n);
}

int dx[] = {-2,-2,-1,-1,1,1,2,2};
int dy[] = {-1,1,-2,2,-2,2,-1,1};
int main()
{
	vector<int> g[1000];
	char str[35][35];
	int ax,ay,bx,by;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d",&m,&n);
		for(i = 0;i < m;i++)
		{
			scanf("%s",str);
		}
		
		/*for(i = 0;i < m;i++)
		{
			for(j = 0;j < n;j++)
			{
				if(str[i][j] == '.')
				{
					idx = i*m+j;
					for(k = 0;k < 8;k++)
					{
						rx = i+dx[k];
						ry = j+dy[k];
						if(inbounds(rx,ry,m,n))
						{
							if(str[rx][ry] == '.')
							{
								idx2 = rx*i+ry;
								g[idx].push_back(idx2);
							}
						}
					}
				}
			}
		}*/
		char a[905][905] = {0};
		for(i = 0;i < m;i++)
		{
			for(j = 0;j < n;j++)
			{
				if((i+j)%2==0 && str[i][j]=='.')
				{
					idx = i*m+j;
					a[901][idx] = 1;
					
					for(k = 0;k < 8;k++)
					{
						rx = i+dx[k];
						ry = j+dy[k];
						if(inbounds(rx,ry,m,n))
						{
							if(str[rx][ry] == '.')
							{
								idx2 = rx*i+ry;
								a[idx][idx2] = 1;
							}
							else
							{
								idx2 = rx*i+ry;
								a[idx][idx2] = -1;
							}
						}
					}
					
				}
				else
				{
					idx = i*m+j;
					a[idx][902] = 1;
					a[901][idx] = 1;
					
					for(k = 0;k < 8;k++)
					{
						rx = i+dx[k];
						ry = j+dy[k];
						if(inbounds(rx,ry,m,n))
						{
							if(str[rx][ry] == '#')
							{
								idx2 = rx*i+ry;
								a[idx][idx2] = -1;
							}
						}
					}
				}
			}
		}
		
		
	}
	return 0;
}

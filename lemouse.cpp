#include <bits/stdc++.h>
using namespace std;
int m,n,ml,mu;

bool inlimit(int i,int j)
{
	return (i>=0 && i<n && j>=0 && j<m);
}

int main()
{
	char s[105][105];
	int i,t,a[100][100],j;
	pair<bool,bool> p[105][105];
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d",&n,&m);
		for(i = 0;i < n;i++)
		{
			scanf("%s",s[i]);
		}
		for(i = 0;i < n;i++)
		{
			for(j = 0;j < m;j++)
			{
				if(i!=0 && j!=0)
				{
					a[i][j] = 0;
					if(inlimit(i+1,j) && s[i+1][j]=='1')
					{
						a[i][j]+=1;
					}
					if(inlimit(i,j+1) && s[i][j+1] == '1')
					{
						a[i][j]+=1;
					}
					if(s[i][j-1] == '1')
					{
						if(p[i-1][j].first == true)
						{
							mu = a[i-1][j];
						}
						else
						{
							mu = a[i-1][j]+1;
						}
					}
					else
					{
						mu = a[i-1][j];
					}

					if(s[i-1][j] == '1')
					{
						if(p[i][j-1].second == true)
						{
							ml = a[i][j-1];
						}
						else
						{
							ml = a[i][j-1]+1;
						}
					}
					else
					{
						ml = a[i][j-1];
					}
					
					
					if(ml < mu)
					{
						a[i][j]+= ml;
						p[i][j].first = true;
						p[i][j].second = false;
					}
					if(ml > mu)
					{
						a[i][j]+= mu;
						p[i][j].first = false;
						p[i][j].second = true;
					}
					if(ml == mu)
					{
						a[i][j]+= ml;
						p[i][j].first = true;
						p[i][j].second = true;
					}
				}
				else if(j!=0)
				{
					a[i][j] = 0;
					if(inlimit(i+1,j) && s[i+1][j]=='1')
					{
						a[i][j]+=1;
					}
					if(inlimit(i,j+1) && s[i][j+1] == '1')
					{
						a[i][j]+=1;
					}

					ml = a[i][j-1];

					a[i][j]+= ml;
					p[i][j].first = true;
					p[i][j].second = false;
				}
				else if(i!=0)
				{
					a[i][j] = 0;
					if(inlimit(i+1,j) && s[i+1][j]=='1')
					{
						a[i][j]+=1;
					}
					if(inlimit(i,j+1) && s[i][j+1] == '1')
					{
						a[i][j]+=1;
					}

					mu = a[i-1][j];

					a[i][j]+= mu;
					p[i][j].first = false;
					p[i][j].second = true;
				}
				else
				{
					a[i][j] = s[i][j] - '0';
					if(inlimit(i+1,j) && s[i+1][j]=='1')
					{
						a[i][j]+=1;
					}
					if(inlimit(i,j+1) && s[i][j+1] == '1')
					{
						a[i][j]+=1;
					}
					p[i][j] = make_pair(false,false);
				}
			}
		}
		printf("%d\n",a[n-1][m-1]);
	}
	return 0;
	
}


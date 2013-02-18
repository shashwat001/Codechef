#include <bits/stdc++.h>
 
using namespace std;
int ch[400000],stay[400000],s[400000],g[400000],maxm,x,y,z;
void setval(int a[],int n,int i)
{
	int j;
	for(j = 0;j < n;j++)
	{
		a[j] = i;
	}
}
 
int main()
{
	int t,i;
	scanf("%d", &t);

	 
	while(t--)
	{
		int R, N;
		scanf("%d %d", &R,&N);

		setval(ch,N,-1);
		setval(stay,N,-1);
		setval(g,R,-1);
		 
		for (i = 0; i < N; i++)
		{
			scanf("%d %d", &x,&y);
			 
			s[i] = x;
			if (i >= R)
			{
				ch[i] = 0;
				if (y < R)
				{
					z = g[y];					 
					stay[z] = x - s[z];
					g[y] = i;
				}
			}
			else
			{
				ch[i] = i - y;
				g[i] = i;
			}
		}
		 
		maxm = 31415926;
		for (i = 0; i < N; i++)
		{
			if (stay[i] == -1)
				printf("%d %d\n", ch[i], maxm);
			else
				printf("%d %d\n", ch[i], stay[i]);
		}
	}
	return 0;
}

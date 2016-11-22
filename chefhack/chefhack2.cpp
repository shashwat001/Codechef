#include <stdio.h>
#include <string.h>

#define MAXM 10000000

int a[10000001];
int d[351][351],visited[351][351];
int i,j,n,t;
long long sum;

int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};


#define BUF 4096
char ibuf[BUF];
int ipt = BUF;
 
int readInt()
{
	while (ipt < BUF && ibuf[ipt] < '0')
		ipt++;
 
	if (ipt == BUF)
	{
		fread(ibuf, 1, BUF, stdin);
		ipt = 0;
		while (ipt < BUF && ibuf[ipt] < '0')
			ipt++;
	}
 
	int n = 0;
	while (ipt < BUF && ibuf[ipt] >= '0')
		n = (n*10)+(ibuf[ipt++]-'0');
 
	if (ipt == BUF)
	{
		fread(ibuf, 1, BUF, stdin);
		ipt = 0;
		while (ipt < BUF && ibuf[ipt] >= '0')
			n = (n*10)+(ibuf[ipt++]-'0');
	}
	return n;
}


int inbds(int x,int y,int n)
{
	if(x>=0 && x<n && y>=0 && y<n)
		return 1;
	return 0;
}

void recurse(int i,int j,int type);
int main()
{


	int cnt = 0,k;
	for(i = 2;i <= MAXM;i++)
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
	
	t = readInt();
	while(t--)
	{
		sum = 0;
		memset(visited,0,sizeof(visited));
		n = readInt();
		for(i = 0;i < n;i++)
		{
			for(j = 0;j < n;j++)
				d[i][j] = readInt();
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
				if(!visited[i][j])
				{
					visited[i][j] = 1;
					if(d[i][j]&1)
					{
						sum+=(d[i][j]+3)/2;
						recurse(i,j,1);
					}
					else
					{
						sum+=(d[i][j])/2;
						recurse(i,j,0);
					}
				}
			}
		}
		printf("%lld\n",sum);
	}
}

inline void recurse(int ii,int jj,int type)
{
	int k;
	int x,y;
	for(k = 0;k < 4;k++)
	{
		x = ii+dx[k];
		y = jj+dy[k];
		if(inbds(x,y,n))
		{
			if(a[d[ii][jj]]<0)
				if((d[x][y]&1) == type)
				{
					if(!visited[x][y])
					{
						visited[x][y] = 1;
						recurse(x,y,type);
					}
				}
		}
		
	}
}

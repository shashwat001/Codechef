#include <stdio.h>


#define INF 2147483647
#define LLINF 9223372036854775807
#define mp make_pair
#define pb push_back

typedef long long int lli;
typedef unsigned int uint;
typedef unsigned long long int ulli;

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

/********************************************************************************************/


#define MAXM 10000000
int i,j,k,cnt;
int a[10000001] = {-2};
int b[10000001],d[351][351],e[351][351] = {0},sum,x,y,t,n;
int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};

int inbounds(int x,int y,int n)
{
	return (x>=0 && x<n && y>=0 && y<n);
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
	a[1] = -2;
	
	cnt = 2;
	b[0] = 0;
	b[4] = 1;
	for(i = 6;i <= MAXM;i+=2)
	{
		b[i] = cnt++;
	}
	cnt = 0;
	for(i = 1;i <= MAXM;i+=2)
	{
		if(a[i] >= 0)
			continue;
		b[i] = cnt++;
	}
	t = readInt();
	while(t--)
	{
		sum = 0;
		n = readInt();
		for(i = 0;i < n;i++)
		{
			for(j = 0;j < n;j++)
			{
				d[i][j] = readInt();
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
				for(k = 0;k < 4;k++)
				{
					x = i+dx[k];
					y = j+dy[k];
					if(inbounds(x,y,n))
					{
						if(d[i][j]%2==1)
						{
							if((e[x][y] == 1))
							{
								e[i][j] = 1;
								break;
							}
						}
						else
						{
							if((e[x][y] == 2))
							{
								e[i][j] = 2;
								break;
							}
						}
					}
				}
				if(k==4)
				{
					sum+=b[d[i][j]];
					if(d[i][j]%2==1)
					{
						for(k = 0;k < 2;k++)
						{
							x = i+dx[k];
							y = j+dy[k];
							l = d[x][y];
							if(a[l]<0 && (d[x][y]%2==1))
								e[x][y] == 1;
						}
					}
					else
					{
						for(k = 0;k < 2;k++)
						{
							x = i+dx[k];
							y = j+dy[k];
							l = d[x][y];
							if(a[l]>=0)
								continue;
							if(d[x][y]%2==0)
									e[x][y] == 2;
						}
					}
				}
			}
		}
		printf("%d\n",sum);
	}
	return 0;
}

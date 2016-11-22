#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <utility>
#include <queue>
#include <stack>
#include <list>
#include <algorithm>

using namespace std;

#define INF 2147483647
#define LLINF 9223372036854775807
#define mp make_pair
#define pb push_back

typedef long long int lli;
typedef unsigned int uint;
typedef unsigned long long int ulli;
typedef pair<int,int> pairint;

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

int i,j,len,flag;
char dict[90000][10],block[100000][10000];
vector<pair<int,int> > v[257];
int a[256];
int main()
{
	int n,m;
	
	scanf("%d",&n);
	int i;
	for(i = 0;i < n;i++)
	{
		scanf("%s",dict[i]);
	}
	scanf("%d",&m);
	for(i = 0;i < m;i++)
	{
		scanf("%s",block[i]);
		len = strlen(block[i]);
		for(j = 0;j < len;j++)
		{
			v[block[i][j]].push_back(make_pair(i,j));
		}
	}
	vector<pair<int,int> > u;
	pair<int,int> p;
	int taken[10000] = {0};
	for(i = 0;i < n;i++)
	{
		len = strlen(dict[i]);
		memset(a,0,sizeof(a));
		flag = 0;
		for(j = 0;j < len;j++)
		{
			a[dict[i][j]] = 1;
			if(v[dict[i][j]].size() == 0)
				flag = 1;
		}
		if(flag == 0)
		{
			for(j = 0;j < len;j++)
			{
				p = v[dict[i][j]];
				for(t = 0;t<p.second;t++)
				{
					if(a[block[p.first][t]==0)
					{
						printf("Take %c\n",block[p.first][t]);
						printf("Throw %c\n",block[p.first][t]);
					}
					
				}
				printf("Take %c\n",dict[i][j]);
				/*for(k = 0;k < v[dict[i][j]].size();k++)
				{
					u.push_back(v[dict[i][j]][k];
				}*/
			}
			printf("Play %s",dict[i]);
			//sort(u.begin(),u.end());
		}
		

		
	}
	return 0;
}

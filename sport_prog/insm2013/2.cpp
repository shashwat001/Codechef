//shashwat001

#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <queue>
#include <stack>
#include <map>
#include <list>
#include <utility>
#include <algorithm>
#include <cassert>

using namespace std;

#define INF 2147483647
#define LINF 9223372036854775807
#define mp make_pair
#define pb push_back

typedef long long int lli;
typedef pair<int,int> pi;
 
#define BUF 4096
char ibuf[BUF]; 
int ipt = BUF;
 
long long int readInt() 
{ 
    while (ipt < BUF && ibuf[ipt] < '0') ipt++;
 
    if (ipt == BUF) 
    {
		fread(ibuf, 1, BUF, stdin);
	 
		ipt = 0;
		while (ipt < BUF && ibuf[ipt] < '0') ipt++; 
    }
    long long int n = 0;
    while (ipt < BUF && ibuf[ipt] >= '0') n = (n*10)+(ibuf[ipt++]-'0');
 
    if (ipt == BUF) 
    {
		fread(ibuf, 1, BUF, stdin);
	 
		ipt = 0;
		while (ipt < BUF && ibuf[ipt] >= '0') n = (n*10)+(ibuf[ipt++]-'0'); 
    }
    return n;
}
 
int main ()
{
	int t;
	int s[100007];
	bool visited[100007];
	t = readInt();
	while(t--)
	{
		
		int n,m,x,y,i,j;
		n = readInt();
		m = readInt();
		vector<int> edge[n+1],comp;
		memset(visited,false,sizeof(visited));
		for(i = 0;i < m;i++)
		{
			x = readInt();
			y = readInt();
			edge[x].pb(y);
			edge[y].pb(x);
		}
		int top = 0;
		for ( i = 1; i <= n; i += 1)
		{
			top = 0;
			if(visited[i])
				continue;
			int cnt = 0;
			s[top++] = i;
			while(top!=0)
			{
				int u = s[top-1];
				visited[u] = true;
				cnt++;
				top--;
				for (j = 0; j < edge[u].size(); j += 1)
				{
					if(!visited[edge[u][j]])
					{
						s[top++] = edge[u][j];
					}
				}
			}
			comp.pb(cnt);
		}
		int oddmax = -1;
		int sumc = 0;
		for(i = 0;i < comp.size();i++)
		{
			if(comp[i]%2==0)
			{
				sumc+=comp[i];
			}
			else
			{
				oddmax = max(comp[i],oddmax);
			}
		}
		sumc+=oddmax+1;
		cout<<sumc<<endl;
	}
	return 0;
}

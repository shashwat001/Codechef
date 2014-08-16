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
 
int readInt() 
{
 
    while (ipt < BUF && ibuf[ipt] < '0') ipt++;
 
    if (ipt == BUF) {
	fread(ibuf, 1, BUF, stdin);
 
	ipt = 0;
	while (ipt < BUF && ibuf[ipt] < '0') ipt++;
 
    }
    int n = 0;
    while (ipt < BUF && ibuf[ipt] >= '0') n = (n*10)+(ibuf[ipt++]-'0');
 
    if (ipt == BUF) {
	fread(ibuf, 1, BUF, stdin);
 
	ipt = 0;
	while (ipt < BUF && ibuf[ipt] >= '0') n = (n*10)+(ibuf[ipt++]-'0');
 
    }
    return n;
}


const int maxm = 100004;
int v[maxm][30];
int cv[maxm] = {0};
int prime[maxm];
int cprime = 0;
vector<int>::iterator it,itib,itie;
vector<pi >::iterator itb,ite;
int primehash[100004] = {0};
vector<int> coun[100005];
vector<pi > ptable[10000];
vector<int> M[10000];


void createfactorvector()
{
	int i,j,a[100004] = {0};
	for(i = 2;i <= 100000;i++)
	{
		if(a[i]==1)
		{
			continue;
		}
		prime[cprime++] = i;
		primehash[i] = cprime-1;
		for(j = i;j<=100000;j+=i)
		{
			v[j][cv[j]++] = i;
			a[j] = 1;
		}
	}
}

void init(int map,int b,int e,int node)
{
	if(b==e)
	{
		M[map][node] = ptable[map][b].second;
		return ;
	}
	int mid = (b+e)/2;
	init(map,b,mid,2*node);
	init(map,mid+1,e,2*node+1);
	M[map][node] = max(M[map][2*node],M[map][2*node+1]);
}

void createsegmenttree(int i)
{
	init(i,0,ptable[i].size()-1,1);
}

int query(int map,int b,int e,int i,int j,int node)
{
	if(j < b || i>e)
	{
		return -1;
	}

	if(b==e)
	{
		return M[map][node];
	}
    if(b>=i && e<=j)
    {
        return M[map][node];
    }
	int mid = (b+e)/2;
	return max(query(map,b,mid,i,j,2*node),query(map,mid+1,e,i,j,2*node+1));
}

int getcount(int value,int x,int y)
{
	itib = lower_bound(coun[value].begin(),coun[value].end(),x);
	itie = upper_bound(coun[value].begin(),coun[value].end(),y);
	return (int)(itie-itib);
	
}
int main ()
{
	int i,n,m,k,x,y,j;
	createfactorvector();
	
	
	n = readInt();
	m = readInt();
	for(i = 0;i < n;i++)
	{
		k = readInt();
		coun[k].pb(i);
		for(j = 0;j<cv[k];j++)
		{
			int map = primehash[v[k][j]];
			ptable[map].pb(mp(i,k));
		}
	}
	
	
	for(i = 0;i < 10000;i++)
	{	
		if(ptable[i].size()>0)
		{
			M[i].resize(ptable[i].size() * 4);
			createsegmenttree(i);
		}
	}
	for(i = 0;i < m;i++)
	{
		k = readInt();
		x = readInt();
		y = readInt();
		x--;y--;
		int maxval = -1;
		for(j = 0;j<cv[k];j++)
		{
			int map = primehash[v[k][j]];
			itb = lower_bound(ptable[map].begin(),ptable[map].end(),mp(x,-1));
			ite = upper_bound(ptable[map].begin(),ptable[map].end(),mp(y,INF));
			ite--;
			int b = (int)(itb-ptable[map].begin());
			int e = (int)(ite-ptable[map].begin());
			//ptable[map].pb(mp(i,k));
			maxval = max(maxval,query(map,0,ptable[map].size()-1,b,e,1));
		}
		if(maxval == -1)
		{
			cout<<"-1 -1\n";
		}
		else
		{
			//getcount(maxval,x,y);
			cout<<maxval<<" "<<getcount(maxval,x,y)<<endl;
		}
	}
	return 0;
}

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
#include <fstream>


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

int i,j;

bool comp(pairint f,pairint s)
{
	if(f.first > s.first)
		return true;
	return false;
}

int main()
{
	int n,i,k,p,q,d[10000];
	ofstream myfile;
	memset(d,0,sizeof(d));
  	myfile.open ("output.txt");
	freopen("input.txt","r",stdin);
	scanf("%d %d",&n,&k);
	vector<pair<int,int> > a;
	for(i = 0;i < n;i++)
	{
		scanf("%d",&p);
		a.pb(mp(p,i));
	}
	sort(a.begin(),a.end(),comp);
	myfile << a[k-1].first<<endl;
	for(i = 0;i < k;i++)
	{
		d[a[i].second] = 1;
	}
	for(i = 0;i < n;i++)
	{
		if(d[i] == 1)
		{
			myfile << i+1 << " ";
		}
	}
	return 0;
}

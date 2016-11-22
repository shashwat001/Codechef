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
#include <set>

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

class strin
{
	public:
	char name[11];
	bool operator< (const strin &a) const
	{
		if(strcmp(this->name,a.name)<=0)
			return true;
		return false;
	}
	bool operator== (const strin &a) const
	{
		if(strcmp(this->name,a.name)==0)
			return true;
		return false;
	}
};


class Compare
{
	public:
	bool operator()(pair<strin,strin> a, pair<strin,strin> b) 
	{
		if(strcmp(a.first.name,b.first.name)<=0)
			return true;
		return false;
	}
};


int main()
{
	int n,t,m;
	
	multiset<strin> name,coun;
	set<pair<strin,strin>, Compare > a;
	set<pair<strin,strin>, Compare >::iterator it,maxitname,maxitcoun;
	pair<strin,strin> pr;
	strin val;
	int maxname,maxcoun,cnt;
	
	scanf("%d %d",&n,&m);
	for(i = 0;i < n;i++)
	{
		scanf("%s",pr.first.name);
		scanf("%s",pr.second.name);
		a.insert(pr);
	}
	
	for(i = 0;i < m;i++)
	{
		scanf("%s",pr.first.name);
		it = a.find(pr);
		name.insert(pr.first);
		coun.insert(it->second);
	}
	maxname = 0;
	maxcoun = 0;
	for(it = a.begin();it!=a.end();it++)
	{
		val = it->first;
		cnt = name.count(it->first);
		if(cnt== 0)
			continue;
		if(maxname < cnt)
		{
			maxname = cnt;
			maxitname = it;
		}
		else if(maxname == cnt)
		{
			if(it->first<maxitname->first)
				maxitname = it;
		}
	}
		
	for(it = a.begin();it!=a.end();it++)
	{
		cnt = coun.count(it->second);
		if(cnt== 0)
			continue;
		if(maxcoun < cnt)
		{
			maxcoun = cnt;
			maxitcoun = it;
		}
		else if(maxcoun == cnt)
		{
			if(it->second<maxitcoun->second)
				maxitcoun = it;
		}
	}
	printf("%s\n%s",maxitcoun->second.name,maxitname->first.name);
	return 0;
}

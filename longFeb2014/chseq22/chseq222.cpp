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
#define mod 1000000007

typedef long long int lli;
//typedef pair<int,int> pi;

#define BUF 4096
char ibuf[BUF];
 
int ipt = BUF;
 
int readInt() {
 
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



class pi
{
	public:
	int first,second;
	bool operator<(pi b) const
	{
		if(this->first < b.first)
			return true;
		if(this->first > b.first)
			return false;
		if(this->second > b.second)
			return true;
		return false;
	}
};

pi make_pair(int a,int b)
{
	pi temp;
	temp.first = a;
	temp.second = b;
	return temp;
}
int main ()
{
	int n,m,i,a,b,count=0,j;
	vector<pi >	v;
	n = readInt();
	m = readInt();
	
	set<pi > range;
	for(i = 0;i < m;i++)
	{
		a = readInt();
		b = readInt();
		range.insert(mp(a,b));
	}

	set<pi >::iterator it1,it2,itnext;
	it1 = range.begin();
	for(i = 1;i <= n;i++)
	{
		if(it1->first == i)
		{
			if(it1 == range.end())
				break;
			//cout<<"sf  "<<i<<"  "<<it1->second<<endl;
			count++;
		}
		else
			continue;
		itnext = it1;
		itnext++;
		vector<pi > temp;
		while(itnext != range.end() && itnext->first == it1->first)
		{
			int b = itnext->second+1;
			int e = it1->second;
			temp.pb(mp(b,e));
			itnext++;
		}
		for(j = 0;j < temp.size();j++)
		{
		
			range.insert(temp[j]);
		}
		//cout<<range.size()<<endl;
		it1 = range.upper_bound(mp(i,0));
	}
	lli f = 1;
	for(i = 0;i < count;i++)
	{
		f = (f*2)%mod;
	}
	cout<<f;
	return 0;
}

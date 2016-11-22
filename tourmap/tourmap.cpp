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
#include <string>

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

class Path
{
	public:
	string from,to;
	int cost;	
	
	void getinputfromuser()
	{
		string temp;
		getline(cin,from,' ');
		getline(cin,to,' ');
		getline(cin,temp,'$');
		cost = atoi(temp.c_str());
		//scanf("%d",&cost);
		getline(cin,temp);
	}
};

Path getinput()
{
	Path temp;
	temp.getinputfromuser();
	return temp;
}

bool comp(Path first,Path second)
{	
	if(first.to < second.to)
		return true;
	else
		return false;
}

int binary_search(vector<Path> &path,int begin,int end,int query)
{
	if(begin == end)
	{
		if(path[query].to == path[begin].to)
			return begin;
		else 
			return -1;
	}
	int mid = (begin+end)/2;
	if(path[query].from > path[mid].to)
		return binary_search(path,mid+1,end,query);
	else
		return binary_search(path,begin,mid,query);
}

void printpath(vector<Path> &path,int n)
{
	for(j = 0;j < n;j++)
	{
		cout<<path[j].from<<"\t"<<path[j].to<<endl;
	}
}

void printnextidx(vector<int> &nextidx,int n)
{
	int i;
	for(i = 0;i < n;i++)
	{
		cout<<nextidx[i]<<endl;
	}
}

int main()
{
	vector<Path> path;
	int nextidx[5000],startidx,idx;
	string temp;
	int n;
	scanf("%d",&n);
	getline(cin,temp);
	for(i = 0;i < n-1;i++)
	{
		path.pb(getinput());
	}
	
	sort(path.begin(),path.end(),comp);
	//printpath(path,n);
	for(i = 0;i < n-1;i++)
	{
		j = (binary_search(path,0,n-2,i));
		if(j == -1)
			startidx = i;
		else
			nextidx[j] = i;
	}
	idx = startidx;
	int sum = 0;
	for(i = 0;i < n-1;i++)
	{
		cout<<path[idx].from<<" "<<path[idx].to<<" "<<path[idx].cost<<"$"<<endl;
		sum+=path[idx].cost;
		idx = nextidx[idx];
	}
	cout<<sum<<"$"<<endl;
	//printnextidx(nextidx,n);
	return 0;
}

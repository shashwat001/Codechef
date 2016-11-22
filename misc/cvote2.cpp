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

int n,t,m;
pair<strin,strin> a[10001];
strin str,coun[10001],coun2[10001];
int freq[10001] = {0}, freqcoun[10001] = {0},idx,maxname,maxcoun,ccoun = 0;
strin finname,fincoun;

int bs(strin str,int b,int e)
{
	if(b==e)
	{
		return b;
	}
	int mid = (b+e)/2;
	if(strcmp(str.name,a[mid].first.name)<=0)
		return bs(str,b,mid);
	else
		return bs(str,mid+1,e);
}


int bscoun(strin str,int b,int e)
{
	if(b==e)
	{
		return b;
	}
	int mid = (b+e)/2;
	if(strcmp(str.name,coun2[mid].name)<=0)
		return bscoun(str,b,mid);
	else
		return bscoun(str,mid+1,e);
}





int main()
{


	scanf("%d %d",&n,&m);
	for(i = 0;i < n;i++)
	{
		scanf("%s",a[i].first.name);
		scanf("%s",a[i].second.name);
		strcpy(coun[i].name,a[i].second.name);
	}


		
	sort(a,a+n);
	sort(coun,coun+n);
	i = 0;
	while(i < n)
	{
		coun2[ccoun++] = coun[i++];
		while(coun2[ccoun-1]==coun[i]) i++;
	}
	for(i = 0;i < m;i++)
	{
		scanf("%s",str.name);
		idx = bs(str,0,n-1);
		freq[idx]++;
		freqcoun[bscoun(a[idx].second,0,ccoun-1)]++;
	}

	maxname =0, maxcoun = 0;
	for(i = 0;i < n;i++)
	{
		if(freq[i])
		{
			if(freq[i]>maxname)
			{
				maxname = freq[i];
				strcpy(finname.name,a[i].first.name);
			}
			else if(freq[i] == maxname)
			{
				if(strcmp(a[i].first.name,finname.name)<0)
					strcpy(finname.name,a[i].first.name);
			}
		}
	}
	for(i = 0;i < ccoun;i++)
	{
		if(freqcoun[i])
		{
			if(freqcoun[i]>maxcoun)
			{
				maxcoun = freqcoun[i];
				strcpy(fincoun.name,coun2[i].name);
			}
			else if(freqcoun[i] == maxcoun)
			{
				if(strcmp(coun2[i].name,fincoun.name)<0)
					strcpy(fincoun.name,coun2[i].name);
			}
		}
	}
	printf("%s\n%s\n",fincoun.name,finname.name);
	return 0;
}

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


int L;
int P[5006000],sortv[5000600];

char s[5006000];

void GetSuffixArray()
{
	int L = strlen(s);
	vector<pair<pair<int,int>,int> > M(L);
    for (int i = 0; i < L; i++) 
		P[i] = int(s[i]);
    for (int skip = 1; skip < L; skip *= 2) 
    {
		for (int i = 0; i < L; i++) 
			M[i] = make_pair(make_pair(P[i], i + skip < L ? P[i + skip] : -1000), i);
		sort(M.begin(), M.end());
		int prev;
		for (int i = 0; i < L; i++)
      	{ 
			P[M[i].second] = (i > 0 && M[i].first == M[i-1].first) ? prev : i;
			prev = P[M[i].second];
		}
	}
};

int upperbound(vector<int> &sortv,char s[],char a,int b, int e,int idx)
{
	if(b==e)
	{
		if(s[sortv[b]+idx]==a)
			return b;
		else
			return -1;
	}
	int mid = (b+e)/2;
	if(s[sortv[mid]+idx]<a)
	{
		return upperbound(sortv,s,a,mid+1,e,idx);
	}
	else
	{
		return upperbound(sortv,s,a,b,mid,idx);
	}
}

int lowerbound(vector<int> &sortv,char s[],char a,int b, int e,int idx)
{
	if(b==e)
	{
		if(s[sortv[b]+idx]==a)
			return b;
		else
			return -1;
	}
	int mid = (b+e)/2;
	if(s[sortv[mid+1]+idx]>a)
	{
		return lowerbound(sortv,s,a,b,mid,idx);
	}
	else
	{
		return lowerbound(sortv,s,a,mid+1,e,idx);
	}
}

int find(vector<int> &sortv,char s[],char word[])
{
	int i,ub,lb,b = 0,e = sortv.size()-1,l = strlen(word);
	for(i = 0;i < l;i++)
	{
		ub = upperbound(sortv,s,word[i],b,e,i);
		lb = lowerbound(sortv,s,word[i],b,e,i);
		if(ub==-1)
			return 0;
		if(lb==-1)
			return 0;
		b = ub;
		e = lb;
	}
	return e-b+1;
}
int main() 
{
	char words[500][5005];
	int sumd[501] = {0};
	unsigned int w,i,n,j;
//	scanf("%d",&w);
//	for(i = 0;i < w;i++)
//	{
//		scanf("%s",words[i]);
//	}
	scanf("%d",&n);
	int length = 0;
	for(i = 0;i < n;i++)
	{
		length = 0;
		scanf("%s",&s[length]);
		GetSuffixArray();
//		length = strlen(s);
//		if(i<n-1)
//		{
//			s[length] = ' ';
//			length++;
//		}
	}
	
	vector<int> sortv(length);
	for(j = 0;j < length;j++)
	{
		sortv[P[j]] = j;
	}
//	for(j = 0;j<w;j++)
//	{
//		sumd[j]=find(sortv,s,words[j]);
//	}
//	for(i = 0;i < w;i++)
//	{
//		printf("%d\n",sumd[i]);
//	}
	return 0;
}

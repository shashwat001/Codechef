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


struct SuffixArray 
{
  const int L;
  string s;
  vector<vector<int> > P;
  vector<pair<pair<int,int>,int> > M;

  SuffixArray(const string &s) : L(s.length()), s(s), P(1, vector<int>(L, 0)), M(L) {
    for (int i = 0; i < L; i++) P[0][i] = int(s[i]);
    for (int skip = 1, level = 1; skip < L; skip *= 2, level++) {
      P.push_back(vector<int>(L, 0));
      for (int i = 0; i < L; i++) 
	M[i] = make_pair(make_pair(P[level-1][i], i + skip < L ? P[level-1][i + skip] : -1000), i);
      sort(M.begin(), M.end());
      for (int i = 0; i < L; i++) 
	P[level][M[i].second] = (i > 0 && M[i].first == M[i-1].first) ? P[level][M[i-1].second] : i;
    }    
  }

  vector<int> GetSuffixArray() { return P.back(); }

  // returns the length of the longest common prefix of s[i...L-1] and s[j...L-1]
  int LongestCommonPrefix(int i, int j) {
    int len = 0;
    if (i == j) return L - i;
    for (int k = P.size() - 1; k >= 0 && i < L && j < L; k--) {
      if (P[k][i] == P[k][j]) {
	i += 1 << k;
	j += 1 << k;
	len += 1 << k;
      }
    }
    return len;
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
	char words[500][5005],s[50005];
	int sumd[501] = {0};
	unsigned int w,i,n,j;
	scanf("%d",&w);
	for(i = 0;i < w;i++)
	{
		scanf("%s",words[i]);
	}
	scanf("%d",&n);
	for(i = 0;i < n;i++)
	{
		scanf("%s",s);
		string str(s);
		SuffixArray sarr(str);
		vector<int> v = sarr.GetSuffixArray();
		vector<int> sortv(v.size());
		for(j = 0;j < v.size();j++)
		{
			sortv[v[j]] = j;
		}
		for(j = 0;j<w;j++)
		{
			sumd[j]+=find(sortv,s,words[j]);
		}
	}
	for(i = 0;i < w;i++)
	{
		printf("%d\n",sumd[i]);
	}
	return 0;
}

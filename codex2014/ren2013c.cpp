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

#define MAXN 100006
#define LOGMAXN 20

#define BUF 4096
char ibuf[BUF];
 
int ipt = BUF;

typedef long long int lli;
typedef pair<int,int> pi;

 
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

int P[MAXN][LOGMAXN],T[MAXN],L[MAXN];
lli dist[MAXN];
 void process3(int N)
  {
      int i, j;
   
  //we initialize every element in P with -1
      for (i = 0; i < N; i++)
          for (j = 0; 1 << j < N; j++)
              P[i][j] = -1;
   
  //the first ancestor of every node i is T[i]
      for (i = 0; i < N; i++)
          P[i][0] = T[i];
   
  //bottom up dynamic programing
      for (j = 1; 1 << j < N; j++)
         for (i = 0; i < N; i++)
             if (P[i][j - 1] != -1)
                 P[i][j] = P[P[i][j - 1]][j - 1];
  }


int query(int N,   int p, int q)
  {
      int tmp, log, i;
   
  //if p is situated on a higher level than q then we swap them
      if (L[p] < L[q])
          tmp = p, p = q, q = tmp;
  
  //we compute the value of [log(L[p)]
      for (log = 1; 1 << log <= L[p]; log++);
      log--;
   
  //we find the ancestor of node p situated on the same level
  //with q using the values in P
      for (i = log; i >= 0; i--)
          if (L[p] - (1 << i) >= L[q])
              p = P[p][i];
   
      if (p == q)
          return p;
   
  //we compute LCA(p, q) using the values in P
      for (i = log; i >= 0; i--)
          if (P[p][i] != -1 && P[p][i] != P[q][i])
              p = P[p][i], q = P[q][i];
   
      return T[p];
  }
int main ()
{
	int t,i;
	
	while(1)
	{
		
		int n;
		n = readInt();
		if(n==0)
			break;
		dist[0] = 0;
		T[0] = -1;
		L[0] = 0;
		for(i = 1;i <= n-1;i++)
		{
			int a,l;
			a = readInt();
			l = readInt();
			T[i] = a;
			dist[i] = dist[a]+l;
			L[i] = L[a]+1;
		}
		process3(n);
		int Q;
		Q = readInt();
		while(Q--)
		{
			int S,T;
			S = readInt();
			T = readInt();
			int com = query(n,S,T);
			lli ans = dist[S]+dist[T]-2*dist[com];
			cout<<ans<<endl;
		}
	}
	return 0;
}

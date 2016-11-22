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

#define LINF 9223372036854775807
#define mp make_pair
#define pb push_back

typedef long long int lli;

const int INF = 2000000000;
typedef pair<int,int> PII;



int main ()
{
	int N,i;
	cin>>N;
	int a[10000][2];
  vector<vector<PII> > edges(N+2);
  for (int i = 1; i <= N; i++)
    cin>>a[i][0]>>a[i][1];
    a[0][0] = 0;
    a[0][1] = 0;
    
    cin>>a[N+1][0]>>a[N+1][1];
    
    for(i = 0;i <= N+1;i++)
    {
    	for (unsigned int j = i+1; j <= N+1; j += 1)
    	{
    		float dista = (a[i][0]-a[j][0])*(a[i][0]-a[j][0])+(a[i][1]-a[j][1])*(a[i][1]-a[j][1]);
    		edges[i].push_back(make_pair(dista,j));
    		edges[j].push_back(make_pair(dista,i));
    	}
    }
	N = N+2;
	priority_queue<PII, vector<PII>, greater<PII> > Q;
  vector<int> dist(N, INF), dad(N, -1);
  int s = 0;
  int t = N-1;
  Q.push (make_pair (0, s));
  dist[s] = 0;
  while (!Q.empty()){
    PII p = Q.top();
    if (p.second == t) break;
    Q.pop();
    
    int here = p.second;
    for (vector<PII>::iterator it=edges[here].begin(); it!=edges[here].end(); it++){
      if (dist[here] + it->first < dist[it->second]){
        dist[it->second] = dist[here] + it->first;
        dad[it->second] = here;
        Q.push (make_pair (dist[it->second], it->second));
      }
    }
  }
  
  if (dist[t] < INF)
    cout<<dist[t];
	return 0;
}

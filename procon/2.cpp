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

#define LINF 9223372036854775807
#define mp make_pair
#define pb push_back

typedef long long int lli;
typedef pair<int,int> pi;
typedef pair<int,int> PII;
const int INF = 2000000000;

typedef struct 
{
	int a,b,c;
} abc;
int djik(vector<vector<PII> > edges,int s,int t)
{
priority_queue<PII, vector<PII>, greater<PII> > Q;
  vector<int> dist(15, INF), dad(15, -1);
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
  
  
    
  return dist[t];
}

int main ()
{
	abc temp[30];
	int i,t,j,k,s,v,x,a[100];
	char y[5],z[5];
	scanf("%d",&t);
	while(t--)
	{
		vector<vector<PII> > edges(15);
		for(i = 0;i < 15;i++)
		{
			scanf("%d",&a[i]);
		}
		for(i = 0;i < 26;i++)
		{
			scanf("%s %s %d",y,z,&x);
			temp[i].a = y[0]-65;
			temp[i].b = z[0]-65;
			temp[i].c = x;
//			printf("%d %d %d\n",temp[i].a,temp[i].b,temp[i].c);
		}
		scanf("%s",y);
		s = y[0]-65;
//		printf("%d\n",s);
		scanf("%s",z);
		v = z[0]-65;
//				printf("%d\n",v);
		
		for(i = 0;i < 26;i++)
		{
			//if(temp[i].b==v)
//				edges[temp[i].a].pb(mp(temp[i].c+a[temp[i].b],temp[i].b));
//			else
			//	edges[temp[i].a].pb(mp(temp[i].c,temp[i].b));
				
			//else if(temp[i].a==v)
//				edges[temp[i].b].pb(mp(temp[i].c+a[temp[i].a],temp[i].a));
//			else
			//	edges[temp[i].b].pb(mp(temp[i].c,temp[i].a));
			//else
			//{
				edges[temp[i].a].pb(mp(temp[i].c+a[temp[i].a],temp[i].b));
				edges[temp[i].b].pb(mp(temp[i].c+a[temp[i].b],temp[i].a));
			//}
		}
		printf("%d\n",djik(edges,s,v));
	}
	return 0;
}

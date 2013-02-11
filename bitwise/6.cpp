#include <bits/stdc++.h>

using namespace std;
int dj(int,int,int);

#define INF 1000000000

typedef pair<int,int> PII;
vector<int> a[1001];
vector<PII> edges[1001];

int b[1001][1001];
bool visited[1001];
int k;
int dfs(int idx)
{
	int i;
	int retval;
	if(idx == k)
	{
		return 0;
	}
	if(a[idx].size() == 0)
	{
		return -1;
	}
	for(i = 0;i < a[idx].size();i++)
	{
		if(visited[a[idx][i]] == false)
		{
			visited[a[idx][i]] = true;
			retval = dfs(a[idx][i]);
			visited[a[idx][i]] = false;
			if(retval > -1)
			{
				return retval + i;
			}
		}
	}
	return -1;
}


int main()
{
	int t,n,i,j,m;
	int val;
	scanf("%d",&t);
	while(t--)
	{
		memset(visited,false,sizeof(visited));
		scanf("%d",&k);
		scanf("%d",&m);
		for(i = 0;i < k;i++)
		{
			a[i].clear();
			edges[i].clear();
		}
		
		for(i = 0;i < m;i++)
		{
			scanf("%d %d",&j,&n);
			a[j-1].push_back(n-1);
		}
		
		for(i = 0;i < k;i++)
		{
			sort(a[i].begin(),a[i].end());
			for(j = 0;j < a[i].size();j++)
			{
				edges[i].push_back(make_pair(j,a[i][j]));
			}
		}
		//visited[1] = true;
		//val = dfs(1);
		printf("%d\n",dj(0,k,k-1));
		
	}
	return 0;
}





int dj(int s,int N,int t)
{
  priority_queue<PII, vector<PII>, greater<PII> > Q;
  vector<int> dist(N, INF), dad(N, -1);
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
  
  //printf ("%d\n", dist[t]);
  if(dist[t] == INF)
  	return -1;
  return dist[t];
  /*if (dist[t] < INF)
    for(int i=t;i!=-1;i=dad[i])
      printf ("%d%c", i, (i==s?'\n':' '));*/
    
}

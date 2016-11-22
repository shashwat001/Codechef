#include <bits/stdc++.h>

using namespace std;


const int INF = 2000000000;
typedef pair<int,int> PII;

typedef struct 
{
    int id;
    int len;
    int fchar;
} tup;


int dij( int N, int s, int t,vector<PII > edges[])
{

  // use priority queue in which top element has the "smallest" priority
  priority_queue<PII, vector<PII>, greater<PII> > Q;
  vector<int> dist(N, INF), dad(N, -1);
  Q.push (make_pair (0, s));
  dist[s] = 0;
  while (!Q.empty()){
    PII p = Q.top();
    if (p.second/26 == t) break;
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
  int mindist  = INF;
  for(int i = 0;i < 26;i++)
  {
  	mindist = min(mindist,dist[t*26+i]);
  }
  if(mindist==INF || mindist==0)
  	return -1;
  return mindist;
}

vector<PII > v[500*26];
int main()
{
	srand(time(NULL));
	int q = 10;
	cout<<q<<endl;
	while(q--)
	{
		int n = 6;
		string a[500];
		string word[500];
		cout<<n<<endl;
		for(int i = 0;i < n;i++)
		{
			for(int j = 0;j < 5;j++)
			{
				a[i]+=rand()%26+'a';
				word[i]+=rand()%26+'a';
			}
			word[i][0] = 'a';
		}
		int id1 = rand()%n;
		int id2 = rand()%n;
		cout<<a[id1]<<" "<<a[id2]<<endl;
		for(int i = 0;i < n;i++)
		{
			int id1,id2;
			do{
			id1 = rand()%n;
			id2 = rand()%n;
			}
			while(id1==id2);
			cout<<a[id1]<<" "<<a[id2]<<" "<<word[i]<<endl;
		}
	}
    return 0;
}

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


int main()
{
    int q;
    cin>>q;
    while(q--)
    {
        int n;
        cin>>n;
        int cur = 0;
        set<pair<string,int> > asins;
        set<pair<string,int> >::iterator it; 
        string first,last;
        cin>>first>>last;
        vector<PII > v[n*26];
/*		for(int i = 0;i < n;i++)
		{
			for(int j = 0;j < 26;j++)
			{
				v[i*j].clear();
			}
		}*/
		
        for(int i = 0;i < n;i++)
        {
            string as1,as2,word;
            cin>>as1>>as2>>word;
            int id1,id2;
            it = asins.lower_bound(make_pair(as1,0));

            if(it != asins.end())
            {

                if(it->first == as1)
                {
                    id1 = it->second;

                }
                else
                {
                    id1 = cur++;
                    asins.insert(make_pair(as1,id1));
                }
            }
            else
            {
                id1 = cur++;
                asins.insert(make_pair(as1,id1));
            }
            it = asins.lower_bound(make_pair(as2,0));

            if(it != asins.end())
            {

                if(it->first == as2)
                {
                    id2 = it->second;

                }
                else
                {
                    id2 = cur++;
                    asins.insert(make_pair(as2,id2));
                }
            }
            else
            {
                id2 = cur++;
                asins.insert(make_pair(as2,id2));
            }
            int len = word.size();
            int fchar = word[0]-'a';
            
            for(int i = 0 ; i < 26 ;i++)
            {
            	if(i != fchar)
            	{
            		v[id1*26+i].push_back(make_pair(len,id2*26+fchar));
            		v[id2*26+i].push_back(make_pair(len,id1*26+fchar));
            	}
            	else if(as1==first)
            	
            	{
            		v[id1*26+i].push_back(make_pair(len,id2*26+fchar));
            	}
            	else if(as2==first)
            	{
            	v[id2*26+i].push_back(make_pair(len,id1*26+fchar));
            	}
            }
        }
        if(first == last)
        {	cout<<"0"<<endl;
        	continue;
        }

        int s = (asins.lower_bound(make_pair(first,0)))->second;
        int t = (asins.lower_bound(make_pair(last,0)))->second;
        //cout<<cur;
        cout<<dij(n*26,s*26,t,v)<<endl;
    }
    return 0;
}

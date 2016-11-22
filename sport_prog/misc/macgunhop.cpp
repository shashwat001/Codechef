#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include<cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;
#define SIZE(A) ((int)(A.size()))
#define REP(i,N) for(int i=0;i<(int)N;i++)
#define FOR(i,a,b) for(int i=(int)a;i<=(int)b;i++)
#define REV(i,a,b) for(int i=(int)a;i>=(int)b;i--)
#define TR(c,i) for(typeof((c).begin() i = (c).begin(); i != (c).end(); i++)
 
#define MAXN 500000
int a[701][701];
struct HopcroftKarp{
    int n;
    vector<int> g[MAXN];
    int dx[MAXN];
    int dy[MAXN];
    int mx[MAXN];
    int my[MAXN];
    queue<int> q;
    
    inline void init(int m){
        n=m;
        REP(i,n) g[i].clear();
        memset(mx,-1,n*sizeof(int));
        memset(my,-1,n*sizeof(int));
    }
    
    inline void add_edge(int u,int v){
        g[u].push_back(v);
    }
    
    inline bool bfs(){
        bool found=false;
        REP(i,n) if(mx[i]==-1) q.push(i);
        REP(i,n) dx[i]=dy[i]=0;
        while(!q.empty()){
            int u=q.front();
            q.pop();
            for(vector<int>::const_iterator it=g[u].begin();it!=g[u].end();it++){
                if(dy[*it]==0){
                    dy[*it]=dx[u]+1;
                    if(my[*it]==-1)
                        found=true;
                    else
                        dx[my[*it]]=dy[*it]+1,q.push(my[*it]);
                }
            }
        }
        return found;
    }
    bool dfs(int u){
        for(vector<int>::const_iterator it=g[u].begin();it!=g[u].end();it++){
            if(dy[*it]==dx[u]+1){
                dy[*it]=0;
                if(my[*it]==-1||dfs(my[*it])){
                    mx[u]=*it;
                    my[*it]=u;
                    return true;
                }
            }
        }
        return false;
    }
    int find(){
        int res=0;
        while(bfs()) 
        	REP(i,n) 
        		if(mx[i]==-1) 
        			if(dfs(i)) 
        				res++;
        return res;
    }
    void printg(int tot)
    {
       	for(int i = 0;i < tot;i++)
   		{
   			for(vector<int>::iterator it = g[i].begin();it != g[i].end();it++)
   			{
   				printf("%d ",*it);
   			}
   			printf("\n");
   		}
   	}
}graph;
 
int r,c;
char s[701][701];
int node(int i,int j){
    return c*(i)+j;
}
bool ok(int i,int j){
    if( i<0 || i>=r || j<0||j>=c) return false;
    return true;
}

int dx[]={-2,-2,2,2};
int dy[]={-2,2,-2,2};
int main()
{
    	scanf("%d %d",&r,&c);
	while(!(r==0 && c==0))
	{
		memset(a,0,sizeof(a));
        graph.init(r*c);
        REP(i,r) scanf("%s",s[i]);
		REP(i,r) 
		{
			REP(j,c)
			
			{
				if(s[i][j] == 'G')
				{
					a[i][j] = -1;
					if((s[i-1][j-1] != 'P' && s[i-2][j-2]!='P') && ok(i-1,j-1)&& ok(i-2,j-2))
						a[i-2][j-2] = -1;
					if(s[i+1][j-1] != 'P' && s[i+2][j-2]!='P' && ok(i+1,j-1)&& ok(i+2,j-2))
						a[i+2][j-2] = -1;
					if(s[i-1][j+1] != 'P' && s[i-2][j+2]!='P' && ok(i-1,j+1)&& ok(i-2,j+2))
						a[i-2][j+2] = -1;
					if(s[i+1][j+1] != 'P' && s[i+2][j+2]!='P' && ok(i+1,j+1)&& ok(i+2,j+2))
						a[i+2][j+2] = -1;
				}
				if(s[i][j] == 'P')
				{
					a[i][j] = -1;
				}
			}
		}
    
    
    
    
    


        REP(i,r) 
        {
        	REP(j,c)
        	{
        		if((i%4<2))
        		{
		        if( a[i][j]==-1) 
		        	continue;
		        int x,y;
		        int deg=0;
		        REP(k,4)
		        {
		            x=i+dx[k];
		            y=j+dy[k];
		            if( ok(x,y) )
		            {
		                if( a[x][y]!=-1 && (s[(x+i)/2][(y+j)/2]!='P'))
		                {
		                    graph.add_edge(node(i,j),node(x,y));
		                    graph.add_edge(node(x,y),node(i,j));
		                }
		                
		            }
            	}
            	}
   			}
   		}
		//graph.printg(r*c);
        int ans=r*c;
        REP(i,r) REP(j,c) if( a[i][j]==-1) ans--;
        printf("%d\n",ans-graph.find()/2);
        scanf("%d %d",&r,&c);
    }
    return 0;
}
 
 

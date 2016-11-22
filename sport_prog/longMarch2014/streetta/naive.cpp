//shashwat001  
//Wednesday 12 March 2014 02:24:07 AM IST

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
lli a[10000] = {0},maxm[10000];

int main(int argc, char *argv[])
{
    lli n = 1000,m,i,j;
    fill(maxm,maxm+1000,INF);
    cin>>n>>m;
    for (i = 0; i < m; i++) 
    {
        
        lli c,u,aa,v,d,idx;
        cin>>c;
        if(c==1)
        {
            cin>>u>>v>>d>>aa;
            u--;v--;
            lli k = 0;
            for(j = u;j <= v;j++)
            {
                if(maxm[j]==INF)
                {
                    maxm[j] = aa+k*d;
                }
                else
                    maxm[j] = max(maxm[j],aa+k*d);
                k++;
            }
        }

        else if(c==2)
        {
            cin>>u>>v>>d>>aa;
            u--;v--;
            lli k = 0;
            for(j = u;j <= v;j++)
            {
                a[j] += aa+k*d;
                k++;
            }
        }
        else
        {
            cin>>idx;
            idx--;
            if(maxm[idx]==INF)
                cout<<"NA\n";
            else
                cout<<a[idx]+maxm[idx]<<endl;
        }
    }

    return 0;
}

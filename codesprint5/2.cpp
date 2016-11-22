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



const int MAX = 20002;

struct pred { lli p; char c; } pre[MAX];
bool flag[MAX];
lli n, Q[MAX];

inline lli mod(lli b, lli m) 
{
        if(b < m) return b;
        return b % m;
}
lli kk[] = {0,9};
lli k;


void print_path(lli u) 
{
        if(u==-1) return;
        print_path(pre[u].p);
        //cout<<pre[u].c;
        k = k*10+pre[u].c-'0';
}

int main() {
        lli t, i;
	        scanf("%lld", &t);
        while(t--) 
        {
        		k = 0;
                scanf("%lld", &n);
                if(n==1 || n==3) 
                {
                        cout<<"9\n";
                        continue;
                }
                if(n==9)
                {
                	cout<<"9\n";
                	continue;
                }
                for(i=0; i<n; i++) flag[i] = 0;
              	lli s = 9;

				lli qh, qt, p[2],  u;
				qh = qt = 0;
				Q[qt++] = s;
				flag[s] = 1;
				pre[s].p = -1;
				pre[s].c = '9';
				lli flagl = 1;
				while(qh < qt) 
				{
				        u = Q[qh++];
				        p[0] = mod((u * mod(10, n)), n);
				        p[1] = mod(p[0]+9, n);
				        for(i=0; i<2; i++) 
				        {
				                if(!flag[p[i]]) {
				                        pre[p[i]].p = u;
				                        pre[p[i]].c = '0'+kk[i];
				                        if(!p[i])
				                        {
				                        	flagl = 0;
				                        	break;
				                        }
				                        flag[p[i]] = 1;
				                        Q[qt++] = p[i];
				                }
				        }
				        if(flagl==0)
				        	break;
				}

                print_path(0);
                cout<<k<<endl;
        }
        return 0;
}

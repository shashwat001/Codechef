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
#define MAX_N 600000

typedef long long int lli;
typedef pair<int,int> pi;


#define BUF 4096
char ibuf[BUF];
 
int ipt = BUF;
 
int readInt() 
{
 
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


class suffixarray 
{
	public:
    suffixarray *first, *go[26];
    int l;
};


suffixarray samn[MAX_N];
suffixarray *lst;
char s1[MAX_N];
char s2[MAX_N];
int tot;

void init(int c) 
{
    suffixarray *p = lst;
    suffixarray *np = samn + (++tot);
    np->l = p->l + 1;
    while (p && !p->go[c]) 
    {
    	p->go[c] = np; 
    	p = p->first;
    }
    if (!p) 
    	np->first = samn;
    else 
    {
        suffixarray *q = p->go[c];
        if (q->l == p->l + 1) 
        	np->first = q;
        else 
        {
            suffixarray *nq = samn + (++tot);
            nq->l = p->l + 1;
            memcpy(nq->go, q->go, sizeof nq->go);
            nq->first = q->first;
            q->first = np->first = nq;
            while (p && p->go[c] == q) 
            {
            	p->go[c] = nq;
            	p = p->first;
            }
        }
    }
    lst = np;
}

int main(int argc, char *argv[]) 
{
	int i;
    scanf("%s %s", s1,s2);
    int l1 = strlen(s1);
    int l2 = strlen(s2);
    lst = samn;
    for (i = 0; i < l1; ++i) 
    	init(s1[i] - 'a');;
    suffixarray *p = samn;
    int now = 0, ans = 0;
    int maxidx = 0;
    for (i = 0; i < l2; ++i) 
    {
        int c = s2[i] - 'a';
        while (p != samn && !p->go[c]) 
        {
            p = p->first;
            if (p->l < now) now = p->l;
        }
        if (p->go[c])
        {
        	p = p->go[c];
        	now++;
        }
        if(now>ans)
        {
        	ans = now;
        	maxidx = i;
        }
    }
    if(ans>0)
    {
		for(i = maxidx-ans+1;i <= maxidx;i++)
		{
			printf("%c",s2[i]);
		}
		printf("\n");
	}
    printf("%d\n", ans);
}

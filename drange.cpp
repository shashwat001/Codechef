#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include <cmath>
#include <utility>

using namespace std;

long long int i,j;

#define BUF 4096
char ibuf[BUF];
 
int ipt = BUF;
 
inline int readInt() {
 
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

/**********************************************************************************************/

long long int maxtree[8000009],mintree[8000009],add[8000009] = {0};

inline void initialize(long long int node,long long int start,long long int end)
{
	long long int node2 = node<<1;
	//range[node][0] = start;
	//range[node][1] = end;
	if(start == end)
	{
		maxtree[node] = start+1;
		mintree[node] = start+1;
		return;
	}
	else
	{
		int mid = (start+end)>>1;
		initialize(node2,start,mid);
		initialize(node2 + 1,mid+1,end);
	
		maxtree[node] = max(maxtree[node2],maxtree[node2+1]);
		mintree[node] = min(mintree[node2],mintree[node2+1]);
	}
}


inline void update(long long int node,long long int b,long long int e,long long int i,long long int j,long long int value)
{
	long long int node2 = node<<1;
	if (b > e || b > j || e < i) 
	{
		return;
    }
	add[node2] +=  add[node];
	add[node2+1] +=  add[node];
	maxtree[node] += add[node];
	mintree[node] += add[node];
	add[node] = 0;
    if (i <= b && j >= e) 
    {
        maxtree[node] += value;
        mintree[node] += value;
        add[node2] += value;
        add[node2+1] += value;
        return;
    }
    update(node * 2 , b , (b + e)>>1 , i, j, value);
    update(node * 2 + 1 ,( (b + e)>>1) + 1 , e , i, j, value);
    
    maxtree[node] = max(maxtree[node2] + add[node2],maxtree[node2+1]+add[node2+1]);
    mintree[node] = min(mintree[node2] + add[node2],mintree[node2+1]+add[node2+1]);
}


int main()
{
	int t;
	long long int w,x,y,z,m,n;
	t = readInt();
	while(t--)
	{
		memset(add,0,sizeof(add));
		//scanf("%lld %lld",&n,&m);
		n = readInt();
		m = readInt();
		initialize(1,0,n-1);
		for(i = 0;i < m;i++)
		{
			//scanf("%lld %lld %lld %lld",&w,&x,&y,&z);
			w = readInt();
			x = readInt();
			y = readInt();
			z = readInt();
			if(w==2)
				z = -z;
			update(1,0,n-1,x-1,y-1,z);
			
		}
		printf("%lld\n",maxtree[1]-mintree[1]);
		
	}
	return 0;
}

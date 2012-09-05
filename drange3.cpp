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

long long int maxtree[10000009],mintree[10000009],add[10000009] = {0};

void initialize(long long int node,long long int start,long long int end)
{
	long long int node3 = node*3;
	//range[node][0] = start;
	//range[node][1] = end;
	if(start>end)
		return;
	if(start == end)
	{
		maxtree[node] = start+1;
		mintree[node] = start+1;
		return;
	}
	else
	{
		int first = start +(end-start)/3;
		int second = start + 2*(end-start)/3;
		initialize(node3,start,first);
		initialize(node3 + 1,first+1,second);
		initialize(node3+2,second+1,end);
	
		maxtree[node] = max(maxtree[node3],maxtree[node3+1]);
		maxtree[node] = max(maxtree[node],maxtree[node3+2]);
		
		mintree[node] = min(mintree[node3],mintree[node3+1]);
		mintree[node] = min(mintree[node],mintree[node3+2]);
	}
}


inline void update(long long int node,long long int b,long long int e,long long int i,long long int j,long long int value)
{
	long long int node3 = node*3;
	if (b > e || b > j || e < i) 
	{
		return;
    }
	add[node3] +=  add[node];
	add[node3+1] +=  add[node];
	add[node3+2] +=  add[node];
	maxtree[node] += add[node];
	mintree[node] += add[node];
	add[node] = 0;
    if (i <= b && j >= e) 
    {
        maxtree[node] += value;
        mintree[node] += value;
        add[node3] += value;
        add[node3+1] += value;
        add[node3+2] += value;
        return;
    }
    int first = b +(e-b)/3;
	int second = b + 2*(e-b)/3;
    update(node3 , b , first , i, j, value);
    update(node3 + 1 ,first + 1 , second , i, j, value);
    update(node3 + 2 ,second + 1 , e , i, j, value);
    
    maxtree[node] = max(maxtree[node3] + add[node3],maxtree[node3+1]+add[node3+1]);
    maxtree[node] = max(maxtree[node],maxtree[node3+2]+add[node3+2]);
    
    mintree[node] = min(mintree[node3] + add[node3],mintree[node3+1]+add[node3+1]);
    mintree[node] = min(mintree[node],mintree[node3+2]+add[node3+2]);
}


int main()
{
	int t;
	//freopen("input.txt","r",stdin);
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

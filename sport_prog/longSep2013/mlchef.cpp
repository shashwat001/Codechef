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

#define INF 2147483647
#define LINF 9223372036854775807
#define mp make_pair
#define pb push_back

typedef long long int lli;
typedef pair<int,int> pi;

#define BUF 4096
char ibuf[BUF]; 
int ipt = BUF;
 
long long int readInt() 
{ 
    while (ipt < BUF && ibuf[ipt] < '0') ipt++;
 
    if (ipt == BUF) 
    {
		fread(ibuf, 1, BUF, stdin);
	 
		ipt = 0;
		while (ipt < BUF && ibuf[ipt] < '0') ipt++; 
    }
    long long int n = 0;
    while (ipt < BUF && ibuf[ipt] >= '0') n = (n*10)+(ibuf[ipt++]-'0');
 
    if (ipt == BUF) 
    {
		fread(ibuf, 1, BUF, stdin);
	 
		ipt = 0;
		while (ipt < BUF && ibuf[ipt] >= '0') n = (n*10)+(ibuf[ipt++]-'0'); 
    }
    return n;
}
typedef struct { int node,status,par;} stackvar;
stackvar ms(int node, int status, int par)
{
	stackvar temp;
	temp.node = node;
	temp.status = status;
	temp.par = par;
	return temp;
}

typedef struct { int cnt,cum,min;} segtree;
segtree M[800005];
void init(int a[],int b,int e,int node)
{
	if(b==e)
	{
		M[node].min = a[b];
		M[node].cnt = 0;
		M[node].cum = 0;
		return;
	}
	int mid = (b+e)/2;
	init(a,b,mid,node*2);
	init(a,mid+1,e,node*2+1);
	
	M[node].min = min(M[2*node].min,M[2*node+1].min);
	M[node].cum = 0;
	M[node].cnt = 0;
}

void update(int a[],int b,int e,int i,int j,int node,int val)
{
	if(j<b || i>e)
	{
		return;
	}
	if(b==e)
	{
		M[node].min = M[node].min - M[node].cum - val;
		M[node].cum = 0;
		if(M[node].min<= 0)
		{
			M[node].cum = 0;
			M[node].min = INF;
			M[node].cnt = 1;
		}
		return;
	}
	if(b>=i && e<=j)
	{
		
		M[node].min = M[node].min - M[node].cum - val;
		M[2*node].cum +=  M[node].cum;
		M[2*node+1].cum += M[node].cum;
		M[node].cum = 0;
		if(M[node].min<=0)
		{		
			if(M[node].cnt<e-b+1)
			{
				int mid = (b+e)/2;
				update(a,b,mid,i,j,2*node,val);		
				update(a,mid+1,e,i,j,2*node+1,val);
			}
//			int nleft = 2*node;
//			int nright = 2*node+1;
//			
//			M[nleft].min -= M[nleft].cum;
//			M[2*nleft].cum+=M[nleft].cum;
//			M[2*nleft+1].cum+=M[nleft].cum;
//			M[nleft].cum = 0;
//			
//			M[nright].min -= M[nright].cum;
//			M[2*nright].cum += M[nright].cum;
//			M[2*nright+1].cum += M[nright].cum;
//			M[nright].cum = 0;
			
			M[node].min = min(M[2*node].min,M[2*node+1].min);
			M[node].cnt = M[2*node].cnt+M[2*node+1].cnt;		
			
		}
		else
		{
			M[2*node].cum += val;
			M[2*node+1].cum += val;
		}
		return;
	}
	M[node].min = M[node].min - M[node].cum - val;
	M[2*node].cum +=  M[node].cum;
	M[2*node+1].cum += M[node].cum;
	M[node].cum = 0;
	int mid = (b+e)/2;
	update(a,b,mid,i,j,2*node,val);		
	update(a,mid+1,e,i,j,2*node+1,val);
//	
//	int nleft = 2*node;
//	int nright = 2*node+1;
//	
//	M[nleft].min -= M[nleft].cum;
//	M[2*nleft].cum+=M[nleft].cum;
//	M[2*nleft+1].cum+=M[nleft].cum;
//	M[nleft].cum = 0;
//	
//	M[nright].min -= M[nright].cum;
//	M[2*nright].cum += M[nright].cum;
//	M[2*nright+1].cum += M[nright].cum;
//	M[nright].cum = 0;
	
	M[node].min = min(M[2*node].min,M[2*node+1].min);
	M[node].cnt = M[2*node].cnt+M[2*node+1].cnt;		
}

int query(int a[],int b,int e,int i,int j,int node)
{
	if(j<b || i>e)
		return 0;
	if(b>=i && e<=j)
	{
		return M[node].cnt;
	}
	int mid = (b+e)/2;
	int left = query(a,b,mid,i,j,2*node);		
	int right = query(a,mid+1,e,i,j,2*node+1);
	return left+right;	
}


int main ()
{
	int i,n,j,x,y;
	int a[100006],maps[100005],children[100006]={0},b[100005];
	n = readInt();
	vector<vector<int> > edge(n+1);
	for(i = 1;i <= n;i++)
	{
		x = readInt();
		y = readInt();
		a[i] = x;
		edge[y].pb(i);
	}
	stack<stackvar > s;
	s.push(ms(0,0,-1));
	int cnt = 0;
	while(!s.empty())
	{
		stackvar top = s.top();
		s.pop();
		if(top.status == 0)
		{
			s.push(ms(top.node,1,top.par));
			maps[top.node] = cnt++;
			for(j = edge[top.node].size()-1;j >= 0 ;j--)
			{
				s.push(ms(edge[top.node][j],0,top.node));
			}
			
		}
		else
		{
			if(top.par!=-1)
			{
				if(edge[top.node].size()==0)
					children[maps[top.node]] = 0;
				children[maps[top.par]] += children[maps[top.node]]+1;
			}
		}
	}
	for(i = 1;i <= n;i++)
	{
		b[maps[i]] = a[i];
	}
	init(b,1,n,1);
	int q,A,X,c;
	q = readInt();
	for(i = 0;i < q;i++)
	{
		c = readInt();
		if(c==1)
		{
			A = readInt();
			X = readInt();
			int first = maps[A]+1;
			int last = first-1 +children[maps[A]];
			update(b,1,n,first,last,1,X);
		}
		else
		{
			A = readInt();
			int first = maps[A]+1;
			int last = first-1 +children[maps[A]];
			printf("%d\n",children[maps[A]]-query(b,1,n,first,last,1));
		}
	}
	return 0;
}

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

pi a[10070],p[10070];
int d[10040];
int n;

#define BUF 4096
char ibuf[BUF];
 
int ipt = BUF;
 
int readInt() {
 
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

void naive(pi out[],int &co)
{
	int i,j,minidx;
	for(i = 0;i < n;i++)
	{
		int minv = 100000;
		for(j = i;j < n;j++)
		{
			if(a[j].first < minv)
			{
				minidx = j;
				minv = a[j].first;
			}
		}
		
		if(minidx == i)
		{
			continue;
		}
		int l = minidx-i+1;
		for(j = 0;j < l/2;j++)
		{
			swap(a[i+j],a[i+l-1-j]);
		}
		out[co++] = mp(i,minidx);
	}
}

void sortrec(pi out[],int &co,int b, int e)
{
	if(b==e)
		return ;
	int minv = 100000,maxv = 0,i,j,minidx,maxidx;
	for(j = b;j <= e;j++)
	{
		if(a[j].first < minv)
		{
			minidx = j;
			minv = a[j].first;
		}
	}
	for(j = b;j <= e;j++)
	{
		if(a[j].first > maxv)
		{
			maxidx = j;
			maxv = a[j].first;
		}
	}
	int lmin = minidx-b+1;
	int lmax = e-maxidx+1;
	if(lmin == 1)
	{
		sortrec(out,co,b+1,e);
		return ;
	}
	if(lmax==1)
	{
		sortrec(out,co,b,e-1);
		return ;
	}
	if(lmin > lmax)
	{
		for(j = 0;j < lmax/2;j++)
		{
			swap(a[e-j],a[e-lmax+1+j]);
		}
		out[co++] = mp(maxidx,e);
		sortrec(out,co,b,e-1);
	}
	else
	{
		for(j = 0;j < lmin/2;j++)
		{
			swap(a[b+j],a[b+lmin-1-j]);
		}
		out[co++] = mp(b,minidx);
		sortrec(out,co,b+1,e);
	}
	
}

int rec(pi out[],int &co,int b, int e, int dindex, int dec)
{
	int minv = 100000,maxv = 0,i,j,minidx=-1,maxidx;
	for(j = b;j <= e;j++)
	{
		if(a[j].first == d[dindex])
			minidx = j;
	}
	if(minidx == -1)
	{
		return -1;
	}
	int retdindex;
	if(dec == 0)
	{
		int l = minidx-b+1;
		if(l==1)
			return dindex;
		retdindex = rec(out,co,b,minidx-1,dindex+1,1-dec);

		for(j = 0;j < l/2;j++)
		{
			swap(a[b+j],a[b+l-1-j]);
		}
		out[co++] = mp(b,minidx);
	}
	else
	{
		int l = e-minidx+1;
		if(l==1)
			return dindex;
		retdindex = rec(out,co,minidx+1,e,dindex+1,1-dec);
		
		for(j = 0;j < l/2;j++)
		{
			swap(a[e-j],a[e-l+1+j]);
		}
		out[co++] = mp(minidx,e);
	}
	return retdindex;
}

void rec(pi out[],int &co)
{
	int dindex = 0;
	while(dindex < n)
	{

		dindex = rec(out,co,dindex,n-1,dindex,0);
		dindex++;
	}
}


int recr(pi out[],int &co,int b, int e, int dindex, int dec)
{
	int minv = 100000,maxv = 0,i,j,minidx=-1,maxidx;
	for(j = b;j <= e;j++)
	{
		if(a[j].first == d[dindex])
			minidx = j;
	}
	if(minidx == -1)
	{
		return dindex-1;
	}
	int retdindex;
	if(dec == 0)
	{
		int l = minidx-b+1;
		if(l==1)
			return dindex;
		retdindex = recr(out,co,b,minidx-1,dindex+1,1-dec);

		for(j = 0;j < l/2;j++)
		{
			swap(a[b+j],a[b+l-1-j]);
		}
		out[co++] = mp(b,minidx);
	}
	else
	{
		int l = e-minidx+1;
		if(l==1)
			return dindex;
		retdindex = recr(out,co,minidx+1,e,dindex+1,1-dec);
		
		for(j = 0;j < l/2;j++)
		{
			swap(a[e-j],a[e-l+1+j]);
		}
		out[co++] = mp(minidx,e);
	}
	return retdindex;
}

void recr(pi out[],int &co)
{
	int dindex = 0;
	while(dindex < n)
	{

		dindex = recr(out,co,0,n-1-dindex,dindex,1);
		dindex++;
	}
}
int main ()
{
	int i,k;
	scanf("%d",&n);
	//n = readInt();
	for(i = 0;i < n;i++)
	{
		scanf("%d",&k);
		//k = readInt();
		p[i] = mp(k,i);
		d[i] = k;
	}
	sort(d,d+n);
	pi out[10004],out1[10004];
	int co = 0,co1 = 0;;
	//naive(out,co);
	//sortrec(out,co,0,n-1);
	copy(p,p+n,a);
	rec(out,co);
	sort(d,d+n,greater<int>());
	copy(p,p+n,a);
	recr(out1,co1);
	if(co < co1)
	{
		cout<<co<<endl;
		for(i = 0;i < co;i++)
		{
			printf("%d %d\n",out[i].first+1,out[i].second+1);
		}
	}
	else
	{
		cout<<co1<<endl;
		for(i = 0;i < co1;i++)
		{
			printf("%d %d\n",out1[i].first+1,out1[i].second+1);
		}
	}
	return 0;
}

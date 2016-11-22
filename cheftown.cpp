#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <utility>
#include <queue>
#include <stack>
#include <list>

using namespace std;

#define INF 2147483647
#define LLINF 9223372036854775807
#define mp make_pair
#define pb push_back

typedef long long int lli;
typedef unsigned int uint;
typedef unsigned long long int ulli;
typedef pair<int,int> pairint;

int i,j,pcount = 0;
pair<int,int> p[400001];

void minmaxheapify(int H[],int n,int i)
{
	int min,j,l,r,ll,lr,rl,rr,p,t;
	while(1)
	{
		l = 2*i+1; r = l+1; ll = 2*l+1; lr = ll+1; rl = lr+1; rr = rl+1;
		if(l>=n)
			return;
		min = H[l];
		j = l;
		if(r<n && H[r]<min)
		{
			min = H[r];j = r;
		}
		if(ll<n && H[ll]<min)
		{
			min = H[ll];j = ll;p = l;
		}
		if(lr<n && H[lr]<min)
		{
			min = H[lr];j = lr;p = l;
		}
		if(rl<n && H[rl]<min)
		{
			min = H[ll];j = rl;p = r;
		}
		if(rr<n && H[rr]<min)
		{
			min = H[rr];j = rr;p = r;
		}
		if(min>=H[i])
			return;
		t = H[i];H[i] = H[j];H[j] = t;
		if((j==l) || (j==r)) return;
		if(H[p]<H[j])
		{
			t = H[p];H[p] = H[j];H[j] = t;
		}
		i = j;
	}
}

void deletemin(int H[],int n)
{
	if(n<=1) return;
	H[0] = H[n-1];
	minmaxheapify(H,n-1,0);
}

void deletemax(int H[],int n)
{
	int max;
	if(n<=2) return;
	max = (H[1]>H[2])?1:2;
	H[max] = H[n-1];
	minmaxheapify(H,n-1,max);
}

int findlevel(int n)
{
	n++;
	int i = 0;
	while(n>0)
	{
		n >>= 1;
		i++;
	}
	if(i&1)
	{
		return 0;
	}
	return 1;
}

void insert(int H[],int n,int newVal)
{
	int i,p,gp,t,level,newlevel;
	H[n] = newVal;
	if(n==0) return;
	p = (n-1)/2;newlevel = findlevel(n);
	if((newlevel == 0)&& H[p]>H[n])
	{
		i = n;
		level = newlevel;
	}
	else if((newlevel == 1) && H[p] < H[n])
	{
		i = n;
		level = newlevel;
	}
	else
	{	
		t = H[p];
		H[p] = H[n];
		H[n] = t;
		i = p;
		level = (newlevel == 0)?1:0;
	}
	while(i >= 3)
	{
		gp = (i-3)/4;
		if((level == 0) && H[gp] < H[i]) return;
		if((level == 1) && H[gp] > H[i]) return;
		t = H[gp]; H[gp] = H[i]; H[i] = t;
		i = gp;
	}
		
}

int main()
{
	int n,Min,Max,a[400001],w,b[400001],ways = 0,ca,k;
	scanf("%d",&n);
	scanf("%d",&w);
	if(w==1)
	{
		printf("%d",n);
		return 0;
	}
	ca = 0;
	scanf("%d",&b[0]);
	insert(a,ca,b[0]);
	ca++;
	for(i = 1;i < w;i++)
	{
		scanf("%d",&b[i]);
		insert(a,ca++,b[i]);
	}
	Min = a[0];
	Max = (a[1]>a[2])?a[1]:a[2];
	if(Max-Min+1 == w)
		ways++;
	for(i = i;i < n;i++)
	{
		Min = a[0];
		Max = (a[1]>a[2])?a[1]:a[2];



		if(b[i-w]==Min)
			deletemin(a,ca--);
		else if(b[i-w] == Max)
			deletemax(a,ca--);
		scanf("%d",&b[i]);
		insert(a,ca++,b[i]);
		Min = a[0];
		Max = (a[1]>a[2])?a[1]:a[2];
		if(Max-Min+1 == w)
			ways++;
		
	}
	printf("%d",ways);

	return 0;
}

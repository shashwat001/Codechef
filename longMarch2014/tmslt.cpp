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
int arr[1000000];
int main ()
{
	int t = readInt(),N,a,b,c,d,i;
	while(t--)
	{
		N = readInt();
		a = readInt();
		b = readInt();
		c = readInt();
		d = readInt();
		fill(arr,arr+1000000,0);
		lli f = d;
		arr[f]++;
		lli sum = 0;
		for(i = 1;i < N;i++)
		{
			f = (a*f*f + b*f +c)%1000000;
			arr[f]++;
		}
		f = 0;
		int cnt = 0;
		int chance = 0;
		for(i = 1000000-1;i >= 0;i--)
		{
			if(arr[i]%2==0)
			{
				continue;
			}
			if(chance == 0)
			{
				f+=i;
				chance = 1;
			}
			else
			{
				f -= i;
				chance = 0;
			}			
		}
		printf("%lld\n",abs(f));
	}	
	return 0;
}

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

#define BUF 4096
char ibuf[BUF];
 
int ipt = BUF;

typedef long long int lli;
typedef pair<int,int> pi;

 
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

int main ()
{
	int t,i,a[100003];
	t = readInt();
	while(t--)
	{
		int n;
		n = readInt();
		for(i = 1;i <= n;i++)
		{
			a[i] = readInt();

		}
		
		if(n==0)
		{
			cout<<"YES\n";
			continue;
		}
		if(n==1)
		{
			cout<<"YES\n";
			continue;
			
		}
		
		sort(a+1,a+n+1);
		a[0] = 0;
		lli sum = (lli)a[0];
		for(i = 1;i <= n;i++)
		{
			if(a[i]<=sum+1)
			{
				sum+=a[i];
			}
			else
			{
				break;
			}
		}
		if(i!=n+1)
		{
			cout<<"NO\n";
		}
		else
		{
			cout<<"YES\n";
		}
	}
	return 0;
}

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
#define base 10

char d[1001][1001];

int main ()
{
	
	int k,j,maxpath;
	cin>>k;
	for(int i = 0;i<=1000;i++)
	{
		for (unsigned int j = 0; j < 1001; j += 1)
		{
			d[i][j] = 'N';
		}
	}
	int i = 0;
	int a[100];
	while(k>0)
	{
		a[i++] = k%10;
		k=k/10;
	}
	maxpath = i-1;
	
	//cout<<"maxpath "<<maxpath<<endl;
	int cur = 3;
	
	for(j = i-1;j>=0;j--)
	{
		for(int n = 1;n<=a[j];n++)
		{
			d[1][cur] = 'Y';
			d[cur][1] = 'Y';
			for(k = 1;k<=j;k++)
			{
				for(int l = 1;l <= 10;l++)
				{
					d[cur][cur+l] = 'Y';
					d[cur+l][cur] = 'Y';
					d[cur+l][cur+base+1];
					d[cur+base+1][cur+l];
				}
				cur+=base+1;
				//cout<<"cur "<<cur<<endl;
				
			}
			for(k = 1;k<=a[j];k++)
			{
				d[cur][cur+1] = 'Y';
				d[cur+1][cur] = 'Y';
				d[cur+1][cur+2] = 'Y';
				d[cur+2][cur+1] = 'Y';
				cur+=2;
				//cout<<"cur "<<cur<<endl;
			}
			d[cur][2] = 'Y';
			d[2][cur] = 'Y';
			cur++;
			//cout<<"cur "<<cur<<endl;
		}
		
	}
	cur--;
	cout<<cur<<endl;
	for(int i = 1;i<=cur;i++)
	{
		for (unsigned int j = 1; j <= cur; j += 1)
		{
			cout<<d[i][j];
		}
		cout<<endl;
	}
	return 0;
}

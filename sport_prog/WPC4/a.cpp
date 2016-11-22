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

int main ()
{
	lli t,m,n,i;
	cin>>t;
	while(t--)
	{
		char s[100004];
		cin>>s;
		cin>>m>>n;
		lli l = strlen(s);
		lli max,min;
		if(m<n)
		{
			
			min = l;
			i = 0;
			lli cnta = 0;
			lli c=0;
			while(i < l)
			{
				while(i<l &&s[i]!='a') i++;
				cnta = 0;
				while(i < l && s[i]=='a') 
				{
					i++;
					cnta++;
				}
				
				if(cnta >= m)
				{
					c+=cnta/m;
				}
			}
			max = (n-m)*c+l;
		}
		else if(m>n)
		{
			max = l;
			i = 0;
			lli cnta = 0;
			lli c=0;
			while(i < l)
			{
				while(i<l &&s[i]!='a') i++;
				cnta = 0;
				while(i < l && s[i]=='a') 
				{
					i++;
					cnta++;
				}
				
				if(cnta >= m)
				{
					c+=cnta/m;
				}
			}
			min = l-(m-n)*c;
		}
		else
		{
			min = l;
			max = l;
		}
		cout<<min<<" "<<max<<endl;
	}
	return 0;
}

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

int main()
{


		int n ;
		cin>>n;
		int A[100006];
		for(int i=0;i<4;i++)
		{
			char ch[10000];
			cin>>ch;
			for(int j=0;j<4;j++)
			{
				if(ch[j]>=48 && ch[j]<=57)
				{
					A[ch[j]-48]++;
				}
			}
		}
		int check=0;
		for(int i=0;i<10;i++)
		{
			if(A[i]>2*n)
			{
				check=1;
				break;
			}
		}
		if(check==0)
		{
			cout<<"YES"<<endl;
		}
		else
		{
			cout<<"NO"<<endl;
		}
		return 0;
}


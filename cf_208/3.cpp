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
	int i,j,k,l,x,n;
	vector<pi > a;
	char in[3][30] = {"pushStack","pushQueue","pushFront"};
	char out[3][30] = {"popStack","popQueue","popFront"};
	cin>>n;
	for(j = 0;j < n;j++)
	{
		cin>>x;
		if(x==0)
		{
			vector<pi > b(a);
			sort(a.begin(),a.end());
			if(a.size()==0)
			{
				cout<<"0"<<endl;
			}
			else if(a.size()<=3 )
			{
				for(i = 0;i < a.size();i++)
				{
					cout<<in[i]<<endl;
				}
				cout<<a.size()<<" ";
				for(i = 0;i < a.size();i++)
				{
					cout<<out[i]<<" ";
				}
				cout<<endl;
			}
			else
			{
				int k = a.size();
				bool pushqueue = false,pushback = false,pushStack = false;
				for(i = 0;i < k;i++)
				{
					
					if((b[i]==a[k-1]) || (b[i]==a[k-2])|| (b[i]==a[k-3]))
					{
						if(pushqueue==false)
						{
							cout<<"pushQueue"<<endl;
							pushqueue = true;
							
						}
						else if(pushStack==false)
						{
							cout<<"pushStack"<<endl;
							pushStack = true;
							
						}
						else if(pushback == false)
						{
							cout<<"pushFront"<<endl;
						}
					}
					else
					{
						if(pushqueue==false)
						{
							cout<<"pushStack"<<endl;

						}
						else
							cout<<"pushQueue"<<endl;
					}
				}
				cout<<"3 "<<"popStack popQueue popFront"<<endl;
			}
			a.clear();
			b.clear();
		}
		else
		{
			a.pb(mp(x,j));
		}
	}
	return 0;
}

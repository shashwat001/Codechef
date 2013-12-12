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
int lis( int arr[], int n )
{
   int *lis, i, j, max = 0;
   lis = (int*) malloc ( sizeof( int ) * n );
 
   /* Initialize LIS values for all indexes */
   for ( i = 0; i < n; i++ )
      lis[i] = 1;
    
   /* Compute optimized LIS values in bottom up manner */
   for ( i = 1; i < n; i++ )
      for ( j = 0; j < i; j++ )
         if ( arr[i] > arr[j] && lis[i] < lis[j] + 1)
            lis[i] = lis[j] + 1;
    
   /* Pick maximum of all LIS values */
   for ( i = 0; i < n; i++ )
      if ( max < lis[i] )
         max = lis[i];
 
   /* Free memory to avoid memory leak */
   free( lis );
 
   return max;
}
int main ()
{
	int n,t,a[200000],i;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(i = 0;i < n;i++)
		{
			scanf("%d",&a[i]);			
		}
		set<int> my_set;
		set<int>::iterator it;
		vector <int> out;
		out.clear();
		my_set.clear();
		for(int i = 0; i < n; i++) {
			my_set.insert(a[i]);
			it = my_set.find(a[i]);
			it++;
			if(it != my_set.end()) 
				my_set.erase(it);
			else
				out.push_back(*it);
		}
		cout<< out.size()<<endl;
	}
		
	return 0;
}

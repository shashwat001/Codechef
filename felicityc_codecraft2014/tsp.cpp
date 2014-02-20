#include <cstdio>
#include <cstring>
using namespace std;
 #define CITY 5
 #define inf 37859
bool vis [CITY] [1 << CITY]; // is_visited
int val [CITY] [1 << CITY]; // cost at particular state
int weight [CITY] [CITY]; // given weight
 
int dp (int at, int mask)
{
    if ( mask ==  (1 << CITY) - 1 ) { // all visited
        vis [at] [mask] = true;
        return val [at] [mask];
    }
 
    if ( vis [at] [mask] ) return val [at] [mask];
    vis [at] [mask] = true;
 
    int ans = inf;
    int cost;
 
    for ( int i = 0; i < CITY; i++ ) {
        if ( weight [at] [i] != -1 && (mask & (1 << i)) == 0 ) {
            cost = dp (i, mask | (1 << i)) + weight [at] [i];
            if ( ans > cost ) ans = cost;
        }
    }
 
    return val [at] [mask] = ans;
}
 
int main ()
{
    memset (vis, false, sizeof (vis));
    memset (weight, -1, sizeof (weight));
    	
    printf ("Cost : %d\n", dp (0, 1));
 
    return 0;
}

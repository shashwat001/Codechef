//shashwat001  
//Wednesday 12 March 2014 02:30:11 AM IST

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

int main(int argc, char *argv[])
{
    srand(time(NULL));
    int n = 1000000000;
    int m = 100000;
    cout<<n<<" "<<m<<endl;
    int i;
    for (int i = 0; i < m; i++) 
    {
        int c = rand()%3;
        if(c==0)
        {
            int v = rand()%n+1;
            int u = rand()%(v) + 1;
            int a = rand()%2000000000 - 1000000000;
            int b = rand()%2000000000 - 1000000000;
            cout<<c+1<<" "<<u<<" "<<v<<" "<<a<<" "<<b<<endl;
        }
        else if(c==1)
        {
            int v = rand()%n+1;
            int u = rand()%(v) + 1;
            int a = rand()%20000 - 10000;
            int b = rand()%20000 - 10000;
            cout<<c+1<<" "<<u<<" "<<v<<" "<<a<<" "<<b<<endl;
        }
        else
        {
            int idx = rand()%n + 1;
            cout<<"3 "<<idx<<endl;
        }
    }

    return 0;
}

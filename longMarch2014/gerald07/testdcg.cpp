//shashwat001  
//Saturday 15 March 2014 06:59:34 PM IST

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


lli ed[100005] = {0};

bool addedge(lli a,lli b)
{
    lli edval;
    if(a < b)
    {
        edval = ((a<<20) | b);
    }
    else
    {
        edval = ((b<<20) | a);
    }
    if(ed[a] == ed[b])
    ed[a] ^= edval;
    ed[b] ^= edval;

}

bool removeedge(lli a, lli b)
{
    lli edval;
    if(a < b)
    {
        edval = ((a<<20) | b);
    }
    else
    {
        edval = ((b<<20) | a);
    }
    ed[a] ^= edval;
    ed[b] ^= edval;

    if(ed[a] == ed[b])
        return false;
    return true;
}

int main(int argc, char *argv[])
{
    lli ch,a,b;
    while(1)
    {
        cin>>ch;
        if(ch == 1)
        {
            cin>>a>>b;
            bool dec = addedge(a,b);
            if(dec == true)
            {
                cout<<"Now connected\n";
            }
            else
            {
                cout<<"Already connected\n";
            }
        }
        else if(ch==2)
        {
            cin>>a>>b;
            bool dec = removeedge(a,b);
            if(dec == true)
            {
                cout<<"Still connected\n";
            }
            else
            {
                cout<<"Not disconnected\n";
            }
        }
//        else
//        {
//            cin>>a>>b;
//            if(isconnected(a,b))
//            {
//                cout<<"YES"<<endl;
//
//            }
//            else
//            {
//                cout<<"NO"<<endl;
//            }
//        }
    }
    return 0;
}

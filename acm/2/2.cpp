/* Sajal Jain , 09EC1017

 *

 */



#include <string>

#include <vector>

#include <iostream>

#include <sstream>

#include <algorithm>

#include <numeric>

#include <set>

#include <map>

#include <queue>

#include <stack>

#include <cmath>

#include <cstdio>

#include <cstring>

#include <cassert>

#include <cstdlib>

#include <fstream>

using namespace std;



#define pp pair <int,int>

#define inf 999999999

#define MOD 1000000007

#define dim 2001



int main()

{

     int T;

     scanf("%d",&T);

     while(T--)

     {

        int p,q,n,m,k;

        scanf("%d %d %d %d %d",&p,&q,&m,&n,&k);
        queue<int> to_land;
        queue<int> to_takeoff;
        for(int i=1;i<=p;i++)to_land.push(0);
        
        for(int i=1;i<=q;i++)to_takeoff.push(0);
        int landed=0;
        int takenoff=0;
        //cout<<m<<endl;
        for(int i=0;i<=k;i++)
        {
            cout<<i<<" ";
            if(i%m==0 && i!=0)to_land.push(i);
            if(!to_land.empty())  //waiting to be landed
            {
                cout<<"L"<<" ";
                to_land.pop();
                landed++;
                to_takeoff.push(i+n+1); 
                
            }
            //no plane waiting to land
            else if((!to_takeoff.empty()) && (to_takeoff.front()<=i)) //can takeoff
            {
               cout<<"T"<<" ";
               to_takeoff.pop();
               takenoff++;
            }
            
        }
        printf("%d %d %d %d\n",landed,takenoff,to_land.size(),to_takeoff.size());





     }

     return 0;

}



#include <iostream>
#include <string.h>
#include <stdio.h>
 
using namespace std;
 
long long int c;
long long int x[31][20][16];
 
long long int recur(long long int n,int p2,int p3,int p4)
{
        long long int a,b,d,sum,max;
        long long int *p;
        if(n<12)
        {
                return n;
        }
        p = &x[p2][p3][p4];
        if(*p > 0)
                return *p;
        a = n>>1;
        a = recur(a,p2+1,p3,p4);
        b = recur(n/3,p2,p3+1,p4);
        c = n>>2;
        c = recur(c,p2,p3,p4+1);
        sum = a + b + c;
        if(sum > n)
        {
                *p = sum;
                return sum;
        }
        else
        {
                *p = n;
                return n;
        }
}
 
int main()
{
        long long int t,n,tot,i,j,k;
        //cin>>t;
        while(scanf("%lld",&n)>0)
        {
                for(i = 0;i < 31;i++)
                        for(j = 0;j < 20;j++)
                                for(k = 0;k < 16;k++)
                                        x[i][j][k] = -1;
                c = 0;
                //cin>>n;
                tot = recur(n,0,0,0);
                cout<<tot<<endl;
        }
        return 0;
} 

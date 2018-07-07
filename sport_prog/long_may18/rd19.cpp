#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int getgcd(int a , int b)
{
    if(a%b != 0)
    {
        return getgcd(b, a%b);  
    }
    return b;
}

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int n;
        scanf("%d", &n);
        vector<int> num(n);
        for(int i = 0;i < n;i++)
        {
            scanf("%d", &num[i]);
        }
        int gcd = num[0];
        for(int i = 1;i < n;i++)
        {
              gcd = getgcd(gcd, num[i]);
        }
        printf("%d\n", gcd == 1?0 : -1);
    }
    return 0;
}

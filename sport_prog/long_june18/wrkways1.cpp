#include <iostream>
#include <vector>
#include <cstdio>
#include <cmath>
#include <cassert>
#include <list>

#define S1(n) scanf("%d", &n)
#define S2(a,b) scanf("%d %d", &a, &b)

using namespace std;

int getlargestfactor(int n, int k)
{
    if(k == 1)
    {

        return n;
    }
    int kthroot = pow(n,1./k);
    if (pow(kthroot, k) != n && pow(kthroot+1, k) <= n)
    {
       kthroot++;
    }
    int i;
    for( i = kthroot; i >=1;i--)
    {
        if(n%i == 0)
        {
            return getlargestfactor(n/i, k-1);
        }
    }

    return 0;

}

void getinorder(vector<int> &output, vector<int> factors)
{
    vector<int> temp;
    int i = 0;
    for( i = 0; i < factors.size() - 1;i++)
    {
        if(factors[i] - factors[i + 1] <= 1)
        {
            continue;
            //temp.push_back(output.size() + factors[i]);
        }
        else
        {
            getinorder(output, vector<int>(factors.begin() + i+1, factors.end()));
            break;
        }
    }

    for(int j = 0;j <= i;j++)
    {
        output.push_back(output.size() + factors[j]);
    }
}

vector<int> compress(vector<int> factors)
{
    list<int> l(factors.begin(), factors.end());
    int maxval = l.front();
    for(list<int>::iterator it = next(l.begin()); it != l.end();it++)
    {
        for(list<int>::iterator it2 = next(it); it2 != l.end();)
        {
            if(*it * *it2 <= maxval)
            {
                *it = *it* *it2;
                auto tempit = it2;
                it2++;
                l.erase(tempit);
            }
            else
            {
                it2++;
            }
        }
    }

    return vector<int>(l.begin(), l.end());
}

int main()
{
    int t;
    S1(t);
    while(t--)
    {
        int n, c;
        S2(n, c);

        if(c == 1)
        {
            for(int i = 1;i <= n;i++)
            {
                printf("%d ", i);
            }
            printf("\n");
            continue;
        }

        vector<int> factors;
        int cc = c;

        int tempn = n<32?n:32;
        for(int i = 0;i < tempn;i++)
        {
            if(cc == 1)
                break;
            int ab = getlargestfactor(cc, tempn-i);
            factors.push_back(ab);
            cc = cc/ab;
        }

        factors = compress(factors);
        // for_each(factors.begin(), factors.end(), [](int x)
        // {
        //     cout<<x<<" ";
        // });

        vector<int> output;

        for(int i = 1; i <= n-factors.size();i++)
        {
            output.push_back(i);
        }

        getinorder(output, factors);

        for(int j = 0;j < output.size();j++)
        {
            printf("%d ", output[j]);
        }
        printf("\n");
    }
    return 0;
}

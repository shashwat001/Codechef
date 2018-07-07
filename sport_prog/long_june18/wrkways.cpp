#include <iostream>
#include <vector>
#include <cstdio>
#include <cmath>

#define S1(n) scanf("%d", &n)
#define S2(a,b) scanf("%d %d", &a, &b)

using namespace std;

vector<int> getallfactors(int n)
{
    vector<int> v;
    for(int i = 2; n>1 && i*i <= n;)
    {
        if(n%i == 0)
        {
            v.push_back(i);
            n = n/i;
        }
        else
        {
            i++;
        }
    }
    v.push_back(n);
    return v;
}

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

int main()
{
    freopen("input", "r", stdin);
    int t;
    S1(t);
    while(t--)
    {
        int n, c;
        S2(n, c);
        //auto af = getallfactors(c);
        vector<int> factors;
        // cout<< getlargestfactor(c, n);
        int cc = c;
        for(int i = 0;i < n;i++)
        {
            if(cc == 1)
                break;
            int ab = getlargestfactor(cc, n-i);
            factors.push_back(ab);
            cc = cc/ab;
        }

        for(int i = 0;i < factors.size();i++)
        {
            // cout << factors[i] << endl;
        }
        // reverse(factors.begin(), factors.end());

        int count = 0;
        int direct = n - factors.size();

        int part = 0;
        for(int i = factors.size() - 1; i > 0;i--)
        {
            if(factors[i - 1] - factors[i] > 1)
            {
                int diff = (factors[i - 1] - factors[i] - 1);
                if(count + diff > direct)
                {
                    part = i;
                    break;
                }
                else
                    count+=diff;
            }
        }

        count = count>direct?direct:count;

        vector<int> output;

        for(int i = 1; i <= direct-count;i++)
        {
            output.push_back(i);
        }
        int idx = part;
        bool done = false;
        while(count > 0)
        {
            while(idx < factors.size()  && (idx == 0 || (factors[idx-1] - factors[idx] <= 1 ) || done))
            {
                done = false;
                output.push_back(factors[idx] + output.size());
                idx++;
            }
            for(int i = 0;i < factors[idx - 1] - factors[idx] - 1;i++)
            {
                output.push_back(output.size() + 1);
                count--;
                done = true;
            }
        }
        for(int i = part - 1; i >= 0;i--)
        {
            output.push_back(factors[i] + output.size());
        }
        for(int j = 0;j < output.size();j++)
        {
            printf("%d ", output[j]);
        }
    }
    return 0;
}

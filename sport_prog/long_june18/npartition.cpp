#include <iostream>
#include <vector>
#include <cstdio>
#include <cmath>
#include <cassert>
#include <algorithm>

#define S1(n) scanf("%d", &n)
#define S2(a,b) scanf("%d %d", &a, &b)

using namespace std;

class Solution
{
public:
    vector<vector<vector<vector<int>>>> sets;
    vector<vector<int>> alloutputs;
    void solve()
    {
        int n,c;
        S2(n,c);

        vector<int> v = getallfactors(c);

        partition(v);

        for(int i = 0;i < sets.size() && i < n;i++)
        {
            for(int j = 0;j < sets[i].size();j++)
            {
                getoutput(n, getfactors(sets[i][j]));
            }
        }

        int minval = 1000000004;
        int minidx;
        for(int i = 0;i < alloutputs.size();i++)
        {
            if(alloutputs[i].back() < minval)
            {
                minval = alloutputs[i].back();
                minidx = i;
            }
        }

        for(int j = 0;j < alloutputs[minidx].size();j++)
        {
            printf("%d ", alloutputs[minidx][j]);
        }
        printf("\n");

    }

    void getoutput(int n, vector<int> factors)
    {
        vector<int> output;

        for(int i = 1; i <= n-factors.size();i++)
        {
            output.push_back(i);
        }

        getinorder(output, factors);
        alloutputs.push_back(output);

        // for(int j = 0;j < output.size();j++)
        // {
        //     printf("%d ", output[j]);
        // }
        // printf("\n");
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

    vector<int> getfactors(vector<vector<int>> factorsvector)
    {
        vector<int> factors;
        for(int i = 0;i < factorsvector.size();i++)
        {
            int product = 1;
            for(int j = 0;j < factorsvector[i].size();j++)
            {
                product *= factorsvector[i][j];
            }
            factors.push_back(product);
        }
        sort(factors.begin(), factors.end(), greater<int>());
        return factors;
    }

    void partition(vector<int> v)
    {
        for(int i = 0;i < v.size();i++)
        {
            addtoset(v[i]);
        }
    }

    void addtoset(int n)
    {
        vector<vector<vector<vector<int>>>> tempsets(sets.size()+1);
        if(sets.size() == 0)
        {
            tempsets[0] = vector<vector<vector<int>>>(1, vector<vector<int>>(1, vector<int>(1, n)));
        }
        else
        {
            for(int i = 0;i < sets.size();i++)
            {
                auto &vvv = sets[i];
                for(int j = 0;j < vvv.size();j++)
                {
                    auto &vv = vvv[j];
                    for(int k = 0;k < vv.size();k++)
                    {
                        vector<vector<int>> tempvv(vv);
                        tempvv[k].push_back(n);
                        tempsets[i].push_back(tempvv);
                    }
                    vector<vector<int>> tempvv(vv);
                    tempvv.push_back(vector<int>(1, n));
                    tempsets[i+1].push_back(tempvv);
                }
            }
        }

        sets = tempsets;
    }

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
};


int main()
{
    int t;
    S1(t);
    while(t--)
    {
        Solution().solve();
    }
    return 0;
}

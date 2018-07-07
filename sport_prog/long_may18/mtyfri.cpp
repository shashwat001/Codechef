#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int n,k;
        scanf("%d %d", &n, &k);
        vector<vector<int> > val(2);
        for(int i = 0;i < n;i++)
        {
            int a;
            scanf("%d", &a);
            val[i%2].push_back(a);
        }
        sort(val[0].begin(), val[0].end(), greater<int>());
        sort(val[1].begin(), val[1].end());
        for(int i = 0;i < min(min((int)val[0].size(), (int)val[1].size()),k);i++)
        {
            if(val[0][i] > val[1][i])
            {
                int temp = val[0][i];
                val[0][i] = val[1][i];
                val[1][i] = temp;
            }
        }
        int sum1 = 0, sum2 = 0;
        for(int i = 0;i < val[0].size();i++)
        {
            sum1 += val[0][i];
        }

        for(int i = 0;i < val[1].size();i++)
        {
            sum2 += val[1][i];
        }

        if(sum2 > sum1)
        {
            printf("YES\n");
        }
        else
        {
            printf("NO\n" );
        }

    }
    return 0;
}

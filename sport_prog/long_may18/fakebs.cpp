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
        int n,q;
        scanf("%d %d", &n, &q);
        vector<int> num(n);
        vector<pair<int, int> > pos(n);
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &num[i]);
            pos[i] = make_pair(num[i], i);
        }

        sort(pos.begin(), pos.end());

        for (int i = 0; i < q; i++)
        {
            int a;
            scanf("%d", &a);
            vector<pair<int, int> >::iterator curpos = lower_bound(pos.begin(), pos.end(), make_pair(a, 0));
            int numpos = curpos->second;

            int low, high, mid;
            low = 1;
            high = n;

            int lw = 0, mw = 0, lr = 0, mr = 0;

            while (low <= high)
            {
                mid = (low + high) / 2;
                if (numpos == mid-1)
                {
                    break;
                }
                else if (mid-1 < numpos)
                {
                    if(num[mid-1] < a)
                    {
                        lr++;
                    }
                    else
                    {
                        mw++;
                    }
                    low = mid+1;
                }
                else if(mid-1 > numpos)
                {
                    if(num[mid-1] > a)
                    {
                        mr++;
                    }
                    else
                    {
                        lw++;
                    }
                    high = mid-1;
                }
            }
            if(mw >= lw)
            {
                int swaps = lw;
                int totalLower = curpos - pos.begin();
                int toSettle = mw-lw;
                int usedLower = lw+lr;
                int remainingLower = totalLower - usedLower;
                if(remainingLower >= toSettle)
                {
                    printf("%d\n", swaps + toSettle);
                }
                else
                {
                    printf("%d\n", -1);
                }
            }
            else
            {

                int swaps = mw;
                int totalHigher = pos.end() - curpos - 1;
                // printf("lower wrong case: %d\n", totalHigher);
                int toSettle = lw-mw;
                int usedHigher = mw+mr;
                int remainingHigher = totalHigher - usedHigher;
                if(remainingHigher >= toSettle)
                {
                    printf("%d\n", swaps + toSettle);
                }
                else
                {
                    printf("%d\n", -1);
                }
            }
        }
    }
    return 0;
}

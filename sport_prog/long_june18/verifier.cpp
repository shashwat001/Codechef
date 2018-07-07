#include <iostream>
#include <vector>
#include <cstdio>
#include <cmath>
#include <ctime>

using namespace std;

int main()
{
    freopen("input", "r", stdin);
    int t;
    scanf("%d", &t);
    vector<int> n(t),c(t);
    for(int j = 0;j < t;j++)
    {

        scanf("%d %d", &n[j], &c[j]);
    }

    freopen("output", "r", stdin);
    for(int j = 0;j < t;j++)
    {
        int product = 1;
        int a;
        int b = 0;
        for(int i = 0;i < n[j];i++)
        {
            scanf("%d", &a);
            b = a;
            if(a<b)
            {
                cout<<"validation error\n";
                    return 0;
            }
            product = product*(a-i);
        }

        if(product == c[j])
            cout<<"true\n";
        else
            cout<<"false\n";
    }
    return 0;

}

#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int main(int argc, char const *argv[])
{
    int t;
    scanf("%d\n", &t);
    while(t--)
    {
        int n, a;
        scanf("%d", &n);
        int x = 0;
        while(n--)
        {
            scanf("%d", &a);
            x = x^(a<<1);
        }

        printf("%d\n", x);
    }
    return 0;
}

#include <iostream>
#include <vector>
#include <cstdio>
#include <cmath>
#include <ctime>

using namespace std;

int main()
{
    srand(time(NULL));
    int t = rand()%100 + 1;
    printf("%d\n", t);
    while(t--)
    {
        int n = rand()%100 + 1;
        int c = rand()%10000000 + 1;

        printf("%d %d\n", n, c);
    }
    return 0;
}

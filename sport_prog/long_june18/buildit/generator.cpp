#include <iostream>
#include <vector>
#include <cstdio>
#include <cmath>
#include <cassert>
#include <algorithm>
#include <ctime>
#include <sys/time.h>
#include <unistd.h>

#define S1(n) scanf("%d", &n)
#define P1(n) printf("%d\n", n)
#define S2(a,b) scanf("%d %d", &a, &b)
#define MOD 163577857

int main()
{
    srand(time(NULL));
    int n,h,x,k;
    n = 20;
    h = 1000000000;
    x = rand()%h+1;
    k = 100;
    P1(n);
    P1(h);
    P1(x);
    P1(k);

    for(int i = 0; i < n;i++)
    {
        printf("%d ",rand()%n + 1);
    }
    printf("\n");

    for(int i = 0; i < k;i++)
    {
        printf("%d ",rand()%h);
    }
    printf("\n");
    for(int i = 0; i < k;i++)
    {
        printf("%d ",rand()%h);
    }
    printf("\n");
}

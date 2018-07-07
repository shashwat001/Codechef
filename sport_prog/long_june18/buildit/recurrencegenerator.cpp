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
    h = rand()%100000000+1;
    k = 100;

    P1(k);
    P1(h);


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

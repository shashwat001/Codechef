#include <iostream>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    srand(time(NULL));
    int t = rand() % 10 + 1;
    printf("%d\n", t);
    while(t--)
    {
        int m = rand()%4 + 1;
        int n = rand()%100 + 1;
        printf("%d %d\n", m , n);
        for(int i = 0;i < m;i++)
        {
            int a = rand() % 10;
            printf("%d ", a);
        }
        printf("\n");
        for(int i = 0;i < m;i++)
        {
            int a = rand() % 10;
            printf("%d ", a);
        }
        printf("\n" );
    }
    return 0;
}

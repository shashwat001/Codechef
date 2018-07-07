#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

#define MOD 1000000007

void multiply(int F[2][2], int M[2][2])
{
  int x =  ((long long int)F[0][0]*M[0][0] + F[0][1]*M[1][0]) % MOD;
  int y =  ((long long int)F[0][0]*M[0][1] + F[0][1]*M[1][1]) % MOD;
  int z =  ((long long int)F[1][0]*M[0][0] + F[1][1]*M[1][0]) % MOD;
  int w =  ((long long int)F[1][0]*M[0][1] + F[1][1]*M[1][1]) % MOD;

  F[0][0] = x;
  F[0][1] = y;
  F[1][0] = z;
  F[1][1] = w;
}

/* Optimized version of power() in method 4 */
void power(int F[2][2], int n)
{
  if( n == 0 || n == 1)
      return;
  int M[2][2] = {{1,1},{1,0}};

  power(F, n/2);
  multiply(F, F);

  if (n%2 != 0)
     multiply(F, M);
}



int fib(int suma, int sumb, int n)
{
  int F[2][2] = {{1,1},{1,0}};
  if (n == 0)
    return 0;
  power(F, n-1);
  return ((long long int)F[0][0]*sumb + (long long int)F[1][0] * suma) % MOD;
}


int main()
{
    int t;
    scanf("%d\n", &t);
    while(t--)
    {
        int n,m;
        scanf("%d %d", &m,&n);
        int suma = 0, sumb = 0;
        for(int i = 0;i < m;i++)
        {
            int a;
            scanf("%d", &a);
            suma = (suma + a)%MOD;
        }

        for(int i = 0;i < m;i++)
        {
            int a;
            scanf("%d", &a);
            sumb = (sumb + a)%MOD;
        }
        suma = ((long long int)suma * m) %MOD;
        sumb = ((long long int)sumb * m) %MOD;
        if(n == 1)
        {
            printf("%d\n", suma);
        }
        else if(n == 2)
        {
            printf("%d\n", sumb);
        }
        else
        {
            int sum;
            for(int i = 3;i <= n;i++)
            {
                sum = (suma + sumb)%MOD;
                suma = sumb;
                sumb = sum;
            }
            printf("%d\n", sum);
        }
    }
    return 0;
}

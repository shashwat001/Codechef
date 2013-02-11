#include <bits/stdc++.h>

using namespace std;
#define MOD 1000000007

int main()
{
    int T,N,i,j,M,a,b,te;
    long long int mydp[1005];
    int A[1005][1005];
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&N);
 
        for(i=1 ; i< N+1 ; i++)
        {
            for(j=1 ;j < N+1 ; j++)
            {
                A[i][j] = 0;
            }
        }
        scanf("%d",&M);
        for(i=0 ; i < M ; i++)
        {
            scanf("%d %d",&a,&b);
            A[a][b] = 1;
            A[b][a] = 1;
        }
        

        mydp[0] = 1;
        mydp[1] = 2;
        for(i=2 ; i <= N ; i++)
        {
            mydp[i] = (mydp[i-1]*2)%MOD;
            for(j=1 ; j<i ; j++)
            {
                if(A[j][i] == 1)
                {
                	te = mydp[j]-mydp[j-1];
                	if(te < 0)
                		te+=MOD;
                    mydp[i]= (mydp[i]-te);
                    if(mydp[i] < 0)
                    	mydp[i]+=MOD;
                }
            }
        }
        printf("%lld\n",mydp[N]);
    }
    return 0;
}

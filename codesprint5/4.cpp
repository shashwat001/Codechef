//shashwat001

#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <queue>
#include <stack>
#include <map>
#include <list>
#include <utility>
#include <algorithm>
#include <cassert>
#include <numeric>

using namespace std;

#define INF 2147483647
#define LINF 9223372036854775807
#define mp make_pair
#define pb push_back

typedef long long int lli;
typedef pair<int,int> pi;



#define MAXN 200005
#define MOD 1000000007

long long phi[MAXN + 1];
int factor[MAXN + 1];

long long mod_pow(long long a, int b){
    long long ret = 1;
    
    while(b){
        if(b & 1) ret = ret * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    
    return ret;
}

int main(){
    memset(factor,-1,sizeof factor);
    phi[1] = 1;
    
    for(int i = 2;i <= MAXN;++i){
        if(factor[i] == -1){
            phi[i] = i - 1;
            
            if(i <= MAXN / i)
                for(int j = i*i;j <= MAXN;j += i)
                    factor[j] = i;
        }else{
            int p = factor[i];
            int aux = i / p;
            
            if(aux % p == 0) phi[i] = phi[aux] * p;
            else phi[i] = (p - 1) * phi[aux];
        }
    }
    
    partial_sum(phi,phi + MAXN,phi);
    
    int T,K;
    int A[501],B[501];
    
    scanf("%d",&T);
    
    while(T--){
        scanf("%d",&K);
        
        for(int i = 0;i < K;++i)
        {
            scanf("%d",&B[i]);
            A[i] = 1;
         }
            
        
        long long P = 0,Q = 1;
        int mnB = B[0];
        
        for(int i = 0;i < K;++i){
            Q = Q * (B[i] - A[i] + 1) % MOD;
            mnB = min(mnB,B[i]);
        }
        
        for(int s = 1,e;s <= mnB;s = e + 1){
            e = 200000;
            
            for(int i = 0;i < K;++i){
                if(B[i] / s) e = min(e,B[i] / (B[i] / s));
                if((A[i] - 1) / s) e = min(e,(A[i] - 1) / ((A[i] - 1) / s));
            }
            
            long long aux = phi[e] - phi[s - 1];
            
            for(int i = 0;i < K;++i)
                aux = aux * (B[i] / s - (A[i] - 1) / s) % MOD;
            
            P += aux;
            if(P >= MOD) P -= MOD;
        }
        
       cout<<P<<endl;
    }
    
    return 0;
}

#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

#define SIZE 4
#define MOD 1000000007


#define BUF 4096
char ibuf[BUF]; 
int ipt = BUF;
 
long long int readInt() 
{ 
    while (ipt < BUF && ibuf[ipt] < '0') ipt++;
 
    if (ipt == BUF) 
    {
		fread(ibuf, 1, BUF, stdin);
	 
		ipt = 0;
		while (ipt < BUF && ibuf[ipt] < '0') ipt++; 
    }
    long long int n = 0;
    while (ipt < BUF && ibuf[ipt] >= '0') n = (n*10)+(ibuf[ipt++]-'0');
 
    if (ipt == BUF) 
    {
		fread(ibuf, 1, BUF, stdin);
	 
		ipt = 0;
		while (ipt < BUF && ibuf[ipt] >= '0') n = (n*10)+(ibuf[ipt++]-'0'); 
    }
    return n;
}
 


void one(long long a[SIZE][SIZE])
{
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            a[i][j] = (i == j);
}

void mul(long long a[SIZE][SIZE], long long b[SIZE][SIZE])
{
    long long res[SIZE][SIZE] = {{0}};

    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            for (int k = 0; k < SIZE; k++)
            {
                res[i][j] += a[i][k] * b[k][j];
                res[i][j] = res[i][j] % MOD;
            }

    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            a[i][j] = res[i][j];
}

//Caluclate a^n and print result into matrix res
void pow(long long a[SIZE][SIZE], long long n, long long res[SIZE][SIZE])
{
    one(res);

    while (n > 0) {
        if (n % 2 == 0)
        {
            mul(a, a);
            n /= 2;
        }
        else {
            mul(res, a);
            n--;
        }
    }
}

int main()
{
    long long int T,N;
    long long int AB[4][4];
    T = readInt();
    while(T--)
    {
        N = readInt();
        if(N==1)
        {
            cout<<1<<endl;
            continue;
        }
        if(N==2)
        {
            cout<<2<<endl;
            continue;
        }
         if(N==3)
        {
            cout<<5<<endl;
            continue;
        }
         if(N==4)
        {
            cout<<12<<endl;
            continue;
        }
        int i,j;
        for(i=0 ; i<4 ; i++)
        {
            for(j=0 ; j< 4 ; j++)
            {
                AB[i][j] = 0;
            }
        }
        AB[0][0] = 1 ; AB[0][1] = 2; AB[0][2] = 3; AB[0][3] = 1;
        AB[1][0] = 1;  AB[2][1] = 1; AB[3][2] = 1;
        
       long long int BC[4][4];
       pow( AB, N-4, BC);
       long long int output;
       output = (12 *BC[0][0] + 5*BC[0][1] + 2*BC[0][2] + BC[0][3] ) % MOD;
       printf("%lld\n",output);
    }
    return 0;
}

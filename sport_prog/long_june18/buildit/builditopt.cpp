#include <iostream>
#include <vector>
#include <cstdio>
#include <cmath>
#include <cassert>
#include <algorithm>
#include <sys/time.h>
#include <unistd.h>
#include <chrono>

#define S1(n) scanf("%d", &n)
#define S2(a,b) scanf("%d %d", &a, &b)
#define MOD 163577857
#define SIZE 100

using namespace std;

int temp[SIZE][SIZE], temp2[SIZE][SIZE];
struct timeval start, end;

void print(int m[SIZE][SIZE], int k)
{
    for(int i = 0;i < k;i++)
    {
        for( int j = 0;j < k;j++)
        {
            printf("%d\t", m[i][j]);
        }
        printf("\n");
    }
}

class Matrix
{
public:

    static void multiply(int dest[SIZE][SIZE], int mat1[SIZE][SIZE], int mat2[SIZE][SIZE], int n)
    {
        chrono::high_resolution_clock::time_point t1 = chrono::high_resolution_clock::now();
        for(int i = 0;i < n;i++)
        {
            for(int j = 0;j < n;j++)
            {
                dest[i][j] = 0;
                for(int k = 0;k < n;k++)
                {
                    dest[i][j] += ((long long int)mat1[i][k] * mat2[k][j])%MOD;
                    dest[i][j] = dest[i][j]%MOD ;
                }
            }
        }
        chrono::high_resolution_clock::time_point t2 = chrono::high_resolution_clock::now();
        chrono::duration<double, std::milli> time_span = t2 - t1;
        cout<< "timediff "  <<time_span.count()<<endl;
    }

    static void copy(int dest[SIZE][SIZE], int src[SIZE][SIZE], int k)
    {
        for(int i = 0;i < k;i++)
        {
            for(int j = 0;j < k;j++)
            {
                dest[i][j] = src[i][j];
            }
        }
    }
};

class Solution
{
public:
    void solve()
    {


        long mtime, seconds, useconds;



        int n,h,x,k;
        S1(n);
        S1(h);
        S1(x);
        S1(k);

        vector<int> a(k), c(k), p(n), suma(k);
        for(int i = 0; i < n;i++)
        {
            S1(p[i]);
        }


        for(int i = 0; i < k;i++)
        {
            S1(a[i]);
            a[i] = a[i]%MOD;
            if(i == 0)
                suma[i] = a[i];
            else
                suma[i] = (suma[i-1] + a[i])%MOD;
        }

        for(int i = 0; i < k;i++)
        {
            S1(c[i]);
            c[i] = c[i]%MOD;
        }

        int mat[SIZE][SIZE];
        getMatrix(k, mat, c);
        int invmat[SIZE][SIZE];
        getMatrixInverse(k, mat, invmat);

        int v[32][100][100];
        Matrix::copy(v[0], mat, k);



        for(int i = 1;i < 32;i++)
        {
            Matrix::multiply(v[i], v[i-1], v[i-1], k);
            // v[i].print();
        }



        int s = getTotalSum1ton(h, a, v, suma, invmat);



        int sump = 0;
        for(int i = 0;i < n;i++)
        {
            int left, right;
            if(x > p[i])
            {
                left = p[i]-x + h + 1;
                sump += getTotalSumltor(left, h, a, v, suma, invmat);
                sump = sump%MOD;
                sump += getTotalSum1ton(p[i], a, v, suma, invmat);
                sump = sump%MOD;
            }
            else
            {
                sump += getTotalSumltor(p[i]-x+1, p[i],a, v, suma, invmat);
                sump = sump%MOD;
            }
        }

        sump = ((long long int)sump*modmulinverse(s, MOD))%MOD;
        printf("%d", sump);
    }

    void printtime(string msg = "")
    {
        // gettimeofday(&start, NULL);
        chrono::high_resolution_clock::time_point t1 = chrono::high_resolution_clock::now();
        // printf("%s time: %ld\n", msg.c_str(), start.tv_usec);
        cout<< "time " <<msg << " "<<t1.time_since_epoch().count()<<endl;
    }

    int getVal(int n, int mat[SIZE][SIZE], vector<int> a)
    {
        int val = 0;
        for(int i = 0;i < n;i++)
        {
            val += ((long long int)mat[0][i] * a[n-1-i])%MOD;
            val = val%MOD;
        }
        return val;
    }

    void getMatrix(int k, int m[SIZE][SIZE],  vector<int> a)
    {
        int n = k;

        for(int i = 0;i < n;i++)
        {
            m[0][i] = a[i];
        }

        for(int i = 1;i < n;i++)
        {
            m[i][i-1] = 1;
        }
    }

    void getMatrixInverse(int k, int m[SIZE][SIZE], int inv[SIZE][SIZE])
    {
        int a[k];
        a[0] = 1-m[0][0]+MOD;
        for(int i = 1;i < k;i++)
        {
            a[i] = (MOD - m[0][i] + a[i-1])%MOD;
        }
        int det = a[k-1];
        int detinv = modmulinverse(det, MOD);
        for(int i = 0;i < k;i++)
        {

            for(int j = 1;j < k;j++)
            {
                if(j > i)
                {
                    inv[i][j] = (a[j-1]-a[k-1] + MOD)%MOD;
                    inv[i][j] = ((long long int)inv[i][j] * detinv)%MOD;
                }
                else
                {
                    inv[i][j] = a[j-1];
                    inv[i][j] = ((long long int)inv[i][j] * detinv)%MOD;
                }
            }
            inv[i][0] = detinv;
        }


    }

    void powM(int res[SIZE][SIZE], int p, int saved[32][SIZE][SIZE], int k)
    {
        // printtime("powM start");
        // chrono::high_resolution_clock::time_point t1 = chrono::high_resolution_clock::now();
        for(int i = 0;i < k;i++)
        {
            for(int j = 0;j < k;j++)
            {
                res[i][j] = 0;
            }
            res[i][i] = 1;
        }


        int i = 0;
        while(p > 0)
        {
            if((p&1) == 1)
            {
                Matrix::multiply(temp2,res,saved[i],k);
                Matrix::copy(res, temp2, k);
            }
            p = p>>1;
            i++;
        }

        // printtime("powM end");
    }

    int getTotalSumltor(int l, int r, vector<int> &a, int saved[32][SIZE][SIZE], vector<int> &suma, int inv[SIZE][SIZE])
    {
        int val = getTotalSum1ton(r, a, saved, suma, inv) - getTotalSum1ton(l-1,a,saved, suma, inv) + MOD;
        return val%MOD;
    }

    int getTotalSum1ton(int n, vector<int> &a, int saved[32][SIZE][SIZE], vector<int> &suma, int inv[SIZE][SIZE])
    {
        if(n == 0)
            return 0;
        int k = a.size();
        int totalsum = 0;
        if(n > k)
        {
            sum1ton(temp2, n-k, saved, inv, k);
            totalsum = (getVal(k, temp2, a) + suma.back())%MOD;
        }
        else
            totalsum = suma[n-1];
        return totalsum;
    }

    void sum1ton(int temp2[SIZE][SIZE], int n, int saved[32][SIZE][SIZE], int inv[SIZE][SIZE], int k)
    {
        n= n+1;
        // if(n == 1)
        // {
        //     Matrix::copy(temp2, saved[0], k);
        // }

        powM(temp, n, saved, k);

        for(int i = 0;i < k;i++)
        {
            for(int j = 0;j < k;j++)
            {
                    temp[i][j] = MOD-temp[i][j];
            }
            temp[i][i] = (1+temp[i][i])%MOD;
        }

        Matrix::multiply(temp2, inv, temp, k);
        for(int i = 0;i < k;i++)
        {
            temp2[i][i] = (temp2[i][i]-1+MOD)%MOD;
        }
    }

    int modmulinverse(int a,int m)
    {
        int x = 0,y = 1,u = 1,v = 0;
        int e = m,f = a;
        int c,d,q,r;
        while(f != 1)
        {
            q = e/f;
            r = e%f;
            c = x-q*u;
            d = y-q*v;
            x = u;
            y = v;
            u = c;
            v = d;
            e = f;
            f = r;
        }
        u = (u+m)%m;
        return u;
    }
};

int main()
{
    Solution().solve();
    return 0;
}

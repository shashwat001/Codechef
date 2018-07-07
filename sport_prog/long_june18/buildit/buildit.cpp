#include <iostream>
#include <vector>
#include <cstdio>
#include <cmath>
#include <cassert>
#include <algorithm>

#define S1(n) scanf("%d", &n)
#define S2(a,b) scanf("%d %d", &a, &b)
#define MOD 163577857

using namespace std;

class Matrix
{
public:
    int n;
    vector<vector<int>> m;


    Matrix(int n): n(n), m(n, vector<int>(n,0))
    {
    }

    Matrix(){}

    Matrix(const Matrix &a):Matrix(a.n)
    {
        for(int i = 0;i < n;i++)
        {
            for(int j = 0;j < n;j++)
            {
                m[i][j] = a.m[i][j];
            }
        }
    }

    Matrix operator*(const Matrix &a)
    {
        Matrix tempm(a.n);

        auto &temp = tempm.m;
        for(int i = 0;i < n;i++)
        {
            for(int j = 0;j < n;j++)
            {
                temp[i][j] = 0;
                for(int k = 0;k < n;k++)
                {
                    temp[i][j] += ((long long int)m[i][k] * a.m[k][j])%MOD;
                    temp[i][j] = temp[i][j]%MOD ;
                }
            }
        }

        return tempm;
    }

    Matrix operator+(const Matrix &a)
    {
        Matrix tempm(a.n);
        auto &temp = tempm.m;
        for(int i = 0;i < n;i++)
        {
            for(int j = 0;j < n;j++)
            {

                temp[i][j] = (m[i][j] + a.m[i][j])%MOD;

            }
        }
        return tempm;
    }

    void print()
    {
        for(int i = 0;i < n;i++)
        {
            for(int j = 0;j < n;j++)
            {
                printf("%d ", m[i][j]);
            }
            printf("\n");
        }
        printf("\n");
    }
};

class Solution
{
public:
    void solve()
    {
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

        sort(p.begin(), p.end());

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

        Matrix mat = getMatrix(c);

        vector<Matrix> v(32);
        v[0] = mat;
        for(int i = 1;i < 32;i++)
        {
            v[i] = v[i-1]*v[i-1];
            // v[i].print();
        }

        int s = getTotalSum1ton(h, a, v, suma);

        int sump = 0;
        for(int i = 0;i < n;i++)
        {
            int left, right;
            if(x > p[i])
            {
                left = p[i]-x + h + 1;
                sump += getTotalSumltor(left, h, a, v, suma);
                sump = sump%MOD;
                sump += getTotalSum1ton(p[i], a, v, suma);
                sump = sump%MOD;
            }
            else
            {
                sump += getTotalSumltor(p[i]-x+1, p[i],a, v, suma);
                sump = sump%MOD;
            }
            // right = p[i] + x - 1;
            // if(right > h)
            // {
            //     sump += getTotalSumltor(p[i]+1, h,a, v, suma);
            //     sump = sump%MOD;
            //     sump += getTotalSum1ton(right-h, a, v, suma);
            //     sump = sump%MOD;
            // }
            // else
            // {
            //     sump += getTotalSumltor(p[i]+1, right,a, v, suma);
            //     sump = sump%MOD;
            // }
        }

        sump = ((long long int)sump*modmulinverse(s, MOD))%MOD;
        printf("%d", sump);
    }

    int getVal(int n, Matrix mat, vector<int> a)
    {
        int val = 0;
        for(int i = 0;i < n;i++)
        {
            val += ((long long int)mat.m[0][i] * a[n-1-i])%MOD;
            val = val%MOD;
        }
        return val;
    }

    Matrix getMatrix(vector<int> a)
    {
        int n = a.size();
        Matrix m(a.size());

        for(int i = 0;i < n;i++)
        {
            m.m[0][i] = a[i];
        }

        for(int i = 1;i < n;i++)
        {
            m.m[i][i-1] = 1;
        }

        return m;
    }

    Matrix powM(int p, vector<Matrix> &saved)
    {
        Matrix res(saved[0].n);
        for(int i = 0;i < res.n;i++)
        {
            res.m[i][i] = 1;
        }
        int i = 0;
        while(p > 0)
        {
            if((p&1) == 1)
            {
                res = res*saved[i];
            }
            p = p>>1;
            i++;
        }
        return res;
    }

    int getTotalSumltor(int l, int r, vector<int> &a, vector<Matrix> &saved, vector<int> &suma)
    {
        int val = getTotalSum1ton(r, a, saved, suma) - getTotalSum1ton(l-1,a,saved, suma) + MOD;
        return val%MOD;
    }

    int getTotalSum1ton(int n, vector<int> &a, vector<Matrix> &saved, vector<int> &suma)
    {
        if(n == 0)
            return 0;
        int k = a.size();
        int totalsum = 0;
        if(n > k)
            totalsum = (getVal(k, sum1ton(n-k, saved), a) + suma.back())%MOD;
        else
            totalsum = suma[n-1];
        return totalsum;
    }

    Matrix sum1ton(int n, vector<Matrix> &saved)
    {
        if(n == 1)
        {
            return saved[0];
        }
        Matrix power = powM(n/2, saved);
        for(int i = 0;i < power.n;i++)
        {
            power.m[i][i] = (power.m[i][i]+1)%MOD;
        }
        Matrix res = sum1ton(n/2, saved)*power;
        if(n&1)
        {
            return res+powM(n, saved);
        }
        else
        {
            return res;
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

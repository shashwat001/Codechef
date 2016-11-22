#include <cstdio>
#include <iostream>

using namespace std;

int main()
{

    bool a[40][40];
    a[1][1] = false;

    for(int i = 1;i < 40;i++)
    {
        for(int k = 1;k < 40;k++)
        {
            a[i][k] = false;
            for(int j = 1; j < i;j++)
            {
                if(a[i-j][k] == false && a[j][k] == false)
                {
                    a[i][k] = true;
                    break;
                }
            }
            if(a[i][k] == true)
                continue;

            for(int j = 1; j < k;j++)
            {
                if(a[i][k-j] == false && a[i][j] == false)
                {
                    a[i][k] = true;
                    break;
                }
            }
        }
    }

    for(int i = 1; i < 40;i++)
    {
        for(int k = 1;k < 40;k++)
            cout<<a[i][k]<<" ";
        cout<<endl;
    }
    return 0;
}

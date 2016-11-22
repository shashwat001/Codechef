#include <cstdio>
#include <iostream>

using namespace std;

int main()
{

    bool a[200];
    a[1] = false;

    for(int i = 2;i < 200;i++)
    {
        a[i] = false;
        for(int j = 1; j < i;j++)
        {
            if(a[i-j] == false && a[j] == false)
            {
                a[i] = true;
                break;
            }
        }
    }

    for(int i = 1; i < 200;i++)
    {
        cout<<i<<"\t"<<a[i]<<endl;
    }
    return 0;
}

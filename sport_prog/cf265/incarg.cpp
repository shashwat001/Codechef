#include <bits/stdc++.h>

using namespace std;
int main(int argc, char *argv[])
{
    int n;
    string bits;
    cin>>n;
    cin>>bits;
    int i = 0;
    while(bits[i++]=='1');
    cout<<min(i,(int)bits.size());
    return 0;
}

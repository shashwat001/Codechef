#include <bits/stdc++.h>
using namespace std;
int main()
{
	srand(time(NULL));
	int t = rand()%100+1;
	cout<<t<<endl;
	while(t--)
	{
		int n = rand()%9+2;
		cout<<n<<endl;
		while(n--)
		{
			int a = rand()%2000000001 - 1000000000;
			cout<<a<<endl;
		}
	}
	return 0;
}

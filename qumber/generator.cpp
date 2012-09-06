#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
	srand(time(NULL));
	long long int t,k;
	long long int n = rand()%1000000+1;
	long long int m = rand()%1000000+1;
	int c = rand()%500000+1;
	c = 500000;
	cout<<n*m<< " "<<c<<endl;
	while(c--)
	{
		t = rand()%3+1;
		int q = rand()%1000000+1;
		int r = rand()%1000000+1;
		k = (long long int)q*r;
		cout<<t<<" "<<k<<endl;
	}
	return 0;
}

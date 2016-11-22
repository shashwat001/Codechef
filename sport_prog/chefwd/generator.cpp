#include <cstdlib>
#include <iostream>
#include <ctime>

using namespace std;

int main()
{
	srand(time(NULL));
	long long int t,n,k;
	t = rand()%1000000 + 1;
	cout << t << endl;
	n = 1;
	while(t--)
	{
		//n = rand()%100000000 + 1;
		//k = rand() %10000000 + 1;
		cout << n << endl;
		n++;
	}
	return 0;
}

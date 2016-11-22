#include<bits/stdc++.h>

using namespace std;
#define MOD 1000000007

long long int A[18];

long long int sumu(long long int R)
{
    return (R*(R+1))/2;
}

long long int func(long long int P)
{
	int i;
	long long int sum1 = 0;
	long long int Q = P;
	int num_digit=0;
	while(Q>0)
	{
		Q = Q/10;
		num_digit++;
	}
	
	if(P < 10)
		return P;
		
	sum1 = 9 ;
	for(i=2 ; i < num_digit ; i++)
	{
		sum1 = sum1 + (A[i]);
	}
	
	sum1 = sum1 + (P - (pow(10,num_digit-1) - 1))*num_digit;

	return sum1;
} 

int main()
{
	
	int i;
	for(i= 1 ; i<= 18 ;i ++)
	{
		A[i] = ( (pow(10,i) - 1) - (pow(10,i-1) - 1) )* i;
	} 
	long long int w,m,k;
	cin>>w>>m>>k;
	long long num_d = w/k;
	num_d += func(m-1);
	long long int low = m;
	long long int high = 100000000000000000LL;
	while(low < high)
	{
		long long int mid = (low + high) / 2;
		if(func(mid) > num_d)
		{
			high = mid;
		}
		else
			low = mid + 1;
	}
	cout<<low-m<<endl;
	return 0;
}

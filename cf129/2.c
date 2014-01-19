#include <stdio.h>
#include <stdint.h>

#define MOD 1000000007

int64_t A[18];

int64_t sumu(int64_t R)
{
    return (R*(R+1))/2;
}

int64_t func(int64_t P)
{
	int i;
	int64_t sum1 = 0;
	int64_t Q = P;
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
	int64_t w,m,k;
	scanf("%I64d %I64d %I64d",&w,&m,&k);
	int64_t num_d = w/k;
	num_d += func(m-1);
	int64_t low = m;
	int64_t high = 100000000000000000LL;
	while(low < high)
	{
		int64_t mid = (low + high) / 2;
		if(func(mid) > num_d)
		{
			high = mid;
		}
		else
			low = mid + 1;
	}
	printf("%I64d\n",low-m);
	return 0;
}

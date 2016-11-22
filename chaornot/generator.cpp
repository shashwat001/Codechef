#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

int main()
{
	int a[10006] = {0},p,i;
	int n = rand()%100+1;
	cout<<n<<endl;
	for(i = 0;i < n;i++)
	{
		p = rand()%10000 ;
		p = i+1;
		if(a[p] != 1)
		{
			a[p] = 1;
			cout<<p<<endl;
		}
		else
		{
			i--;
		}
	}	
}

#include <stdio.h>

int tree[1000];
int MaxVal = 990;

int read(int idx)
{
	int sum = 0;
	while (idx > 0)
	{
		sum += tree[idx];
		idx -= (idx & -idx);
	}
	return sum;
}

void update(int idx ,int val)
{
	while (idx <= MaxVal)
	{
		tree[idx] += val;
		idx += (idx & -idx);
	}
}

int readSingle(int idx)
{
	int sum = tree[idx];
	if (idx > 0)
	{
		int z = idx - (idx & -idx); 
		idx--;
		while (idx != z)
		{ 
			sum -= tree[idx]; 
			idx -= (idx & -idx);
		}
	}
	return sum;
}


int main()
{
	int a,b,c;
	while(1)
	{
		scanf("%d",&c);
		if(c == 1)
		{
			scanf("%d %d ",&a,&b);
			update(a,b);
		}
		if(c == 2)
		{
			scanf("%d",&a);
			printf("%d",read(a));
		}
		else
		{
			scanf("%d",&a);
			printf("%d",readSingle(a));
		}
	}
	return 0;
}

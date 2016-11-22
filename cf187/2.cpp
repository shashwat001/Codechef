#include <bits/stdc++.h>

using namespace std;
#define sf(n) scanf("%d",&n)
#define pf(n) printf("%d\n",n)


int tree[100005] = {0},i,j,n,c,p,q,v,x,m,diff;
int read(int idx){
	int sumc = 0;
	while (idx > 0){
		sumc += tree[idx];
		idx -= (idx & -idx);
	}
	return sumc;
}

void update(int idx ,int val){
	while (idx <= n){
		tree[idx] += val;
		idx += (idx & -idx);
	}
}


int readSingle(int idx){
int sumc = tree[idx]; // sum will be decreased
if (idx > 0){ // special case
	int z = idx - (idx & -idx); // make z first
	idx--; // idx is no important any more, so instead y, you can use idx
	while (idx != z){ // at some iteration idx (y) will become z
		sumc -= tree[idx]; 
// substruct tree frequency which is between y and "the same path"
		idx -= (idx & -idx);
	}
}
return sumc;
}

int main()
{
	sf(n);
	sf(m);
	int sumc = 0;
	for(i = 1;i <= n;i++)
	{
		sf(p);
		update(i,p-sumc);
		sumc = p;
	}
	for(i = 0;i < m;i++)
	{
		sf(q);
		if(q==1)
		{
			sf(v);
			sf(x);
			p = read(v);
			diff = x-p;
			if(v!=n)
			{
				
				p = read(v+1);
				update(v+1,-diff);
			}
			update(v,diff);
		}
		if(q==2)
		{
			sf(v);
			update(1,v);
		}
		if(q==3)
		
		{
			sf(v);
			printf("%d\n",read(v));
		}
	}
	
	return 0;
}

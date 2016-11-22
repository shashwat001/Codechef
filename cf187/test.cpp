#include <bits/stdc++.h>

using namespace std;
#define sf(n) scanf("%d",&n)
#define pf(n) printf("%d\n",n)


int tree[100001] = {0},b[1001] = {0}	,i,j,n,c,p,q,d[1001] = {0};
int read(int idx){
	int sum = 0;
	while (idx > 0){
		sum += tree[idx];
		idx -= (idx & -idx);
	}
	return sum;
}

void update(int idx ,int val){
	while (idx <= n){
		tree[idx] += val;
		idx += (idx & -idx);
	}
}


int readSingle(int idx){
int sum = tree[idx]; // sum will be decreased
if (idx > 0){ // special case
	int z = idx - (idx & -idx); // make z first
	idx--; // idx is no important any more, so instead y, you can use idx
	while (idx != z){ // at some iteration idx (y) will become z
		sum -= tree[idx]; 
// substruct tree frequency which is between y and "the same path"
		idx -= (idx & -idx);
	}
}
return sum;
}

int main()
{
	n = 10;

	update(1,6);
	update(2,10);
	update(3,15);
	update(4,52);
	update(5,54);
	update(6,15);
	update(7,6);
	update(8,9);
	update(9,2);
	update(10,4);
	printf("%d",readSingle(2));
	
	return 0;
}

#include <stdio.h>
#include <string.h>

int a[100005],m[400005];
bool valid[100005];

int init(int b,int e,int node)
{
	if(b==e)
	{
		return m[node] = a[b];
	}
	int mid = (b+e)/2;
	return m[node] = init(b,mid,2*node) + init(mid+1,e,2*node+1);
}

int query(int b,int e,int i,int j,int node)
{
	if(j<b || i>e)
	{
		return 0;
	}
	if(i<=b && j>=e)
	{	
		if(valid[node] == true)
			return 0;
		return m[node];
	}
	int mid = (b+e)/2;
	if(valid[node] == true)
	{
		m[node] = 0;
		valid[node] = false;
		valid[2*node] = true;
		valid[2*node+1] = true;
	}
	return query(b,mid,i,j,2*node) + query(mid+1,e,i,j,2*node+1);
}

int update(int b,int e,int i,int j,int node,int val)
{
	if(j<b || i>e)
	{
		if(valid[node] == true)
			return 0;
		return m[node];
	}
	if(i<=b && j>=e)
	{
		if(b==e)
		{	
			valid[node] = false;
			m[node] = val;
			return val;
		}
		valid[node] = true;
		return val;
	}
	int mid = (b+e)/2;
	if(valid[node] == true)
	{
		m[node] = 0;
		valid[node] = false;
		valid[2*node] = true;
		valid[2*node+1] = true;
	}
	return m[node] = update(b,mid,i,j,2*node,val) + update(mid+1,e,i,j,2*node+1,val);
}


int main()
{	
	int n,i,l,r,q,c;
	memset(valid,false,sizeof(valid));
	scanf("%d",&n);
	for(i = 0;i <n;i++)
	{
		scanf("%d",&a[i]);
	}
	init(0,n-1,1);
	scanf("%d",&q);
	for(i = 0;i < q;i++)
	{
		scanf("%d %d %d",&c,&l,&r);
		if(c==3)
			printf("%d\n",query(0,n-1,l,r,1));
		else if(c==1)
			update(0,n-1,l,r,1,0);
		else 
			update(0,n-1,l,l,1,r);
	}
	
	return 0;
}

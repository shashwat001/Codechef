#include <stdio.h>
#include <string.h> 

int i,j,m,n;
int a[701][701],out,out1,out2;
char str[701][701],b[701][701];

bool inlimit(int i,int j)
{
	if(i >=0 && i < m && j >=0 && j < n)
			return true;
	return false;
}
const int dr[4]={-2, 2, 2, -2};
const int dc[4]={-2, -2, 2, 2};

int dfs(int r, int c, char seen[701][701]){
	if(seen[r][c] || a[r][c]==-1)
		return 0;
	seen[r][c]=1;
	for(int d=0; d<4; d++){
		int nr=r+dr[d];
		int nc=c+dc[d];
		if(inlimit(nr, nc)){
			int &val=a[nr][nc];
			if(!val || (val>0 && dfs(val/2, val%2, seen))){
				val=r*2+c;
				return 1;
			}
		}
	}
	return 0;
}



int solve(){
	int res=0;
	for(int i=0; i<m; i++)
	for(int j=0; j<n; j++)
		if(a[i][j]!=-1){
			res++;
			if((i%4==0 )&& (j%4==0)){
				char seen[701][701]={{0}};
				res-=dfs(i, j, seen);
			}
		}
	return res;
}

int solve1(){
	int res=0;
	for(int i=0; i<m; i++)
	for(int j=0; j<n; j++)
		if(a[i][j]!=-1){
			res++;
			if((i%4==1 )&& (j%4==1)){
				char seen[701][701]={{0}};
				res-=dfs(i, j, seen);
			}
		}
	return res;
}

int main()
{

	scanf("%d %d",&m,&n);
	//while(!(m==0 && n==0))
	//{
		memset(a,0,sizeof(a));
		for(i = 0;i < m;i++)
		{
			scanf("%s",str[i]);
		}
		for(i = 0;i < m;i++)
		{
			for(j = 0;j < n;j++)
			{
				if(str[i][j] == 'G')
				{
					a[i][j] = -1;
					if((str[i-1][j-1] != 'P' && str[i-2][j-2]!='P') && inlimit(i-1,j-1)&&inlimit(i-2,j-2))
						a[i-2][j-2] = -1;
					if(str[i+1][j-1] != 'P' && str[i+2][j-2]!='P' && inlimit(i+1,j-1)&&inlimit(i+2,j-2))
						a[i+2][j-2] = -1;
					if(str[i-1][j+1] != 'P' && str[i-2][j+2]!='P' && inlimit(i-1,j+1)&&inlimit(i-2,j+2))
						a[i-2][j+2] = -1;
					if(str[i+1][j+1] != 'P' && str[i+2][j+2]!='P' && inlimit(i+1,j+1)&&inlimit(i+2,j+2))
						a[i+2][j+2] = -1;
				}
				if(str[i][j] == 'P')
				{
					a[i][j] = -1;
				}
			}
		}
		printf("\n\n\n");
		for(i = 0;i < m;i++)
		{
			for(j = 0;j < n;j++)
			{
				printf("%d\t",a[i][j]);
			}
			printf("\n");
		}
		out1  = solve();
		out2 = solve1();
		printf("%d %d\n",(out1),(out2));
		//scanf("%d %d",&m,&n);
		
	//}
	return 0;
}

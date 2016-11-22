#include<stdio.h>
int max(int x,int y)
{
  if(x>y)
    return x;
  else
    return y;
}
int main()
{
  int i,j,k,t,A[5],B[5],len,C[20000],f,g;
  char a[20000],b[20000];
  scanf("%d",&t);
  for(i=0;i<t;i++)
    {
      len=0;
      for(j=0;j<5;j++)
	{
	  A[j]=0;
	  B[j]=0;
	}
      scanf("%s",a);
      scanf("%s",b);
      while(a[len]!='\0')
	{
	  f=(int)a[len]-48;
	  g=(int)b[len]-48;
	  if(f>7)
	    A[4]++;
	  else if(f==7)
	    A[3]++;
	  else if((f>4)&&(f<7))
	    A[2]++;
	  else if(f==4)
	    A[1]++;
	  else
	    A[0]++;
	  if(g>7)
	    B[4]++;
	  else if(g==7)
	    B[3]++;
	  else if((g>4)&&(g<7))
	    B[2]++;
	  else if(g==4)
	    B[1]++;
	  else
	    B[0]++;
	  len++;
	}
      k=0;
      while(A[3]!=0)
	{
	  if(B[2]!=0)
	    {
	      B[2]--;
	      C[k]=7;
	      k++;
	    }
	  else if(B[0]!=0)
	    {
	      B[0]--;
	      C[k]=7;
	      k++;
	    }
	  else if(B[1]!=0)
	    {
	      B[1]--;
	      C[k]=7;
	      k++;
	    }
	  else if(B[3]!=0)
	    {
	      B[3]--;
	      C[k]=7;
	      k++;
	    }
	  else 
	    {
	      B[4]--;
	    }
	  A[3]--;
	}
      while(B[3]!=0)
	{
	  if(A[2]!=0)
	    {
	      A[2]--;
	      C[k]=7;
	      k++;
	    }
	  else if(A[0]!=0)
	    {
	      A[0]--;
	      C[k]=7;
	      k++;
	    }
	  else if(A[1]!=0)
	    {
	      A[1]--;
	      C[k]=7;
	      k++;
	    }
	  else 
	    {
	      A[4]--;
	    }
	  B[3]--;
	}
      while(A[1]!=0)
	{
	  if(B[0]!=0)
	    {
	      B[0]--;
	      C[k]=4;
	      k++;
	    }
	  else if(B[1]!=0)
	    {
	      B[1]--;
	      C[k]=4;
	      k++;
	    }
	  A[1]--;
	}
      while(B[1]!=0)
	{
	  if(A[0]!=0)
	    {
	      A[0]--;
	      C[k]=4;
	      k++;
	    }
	  B[1]--;
	}
      for(j=0;j<k;j++)
	printf("%d",C[j]);
      printf("\n");
    }
  return 0;
}

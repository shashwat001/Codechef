#include<stdio.h>
#include<stdlib.h>
#include<time.h>


void swap(int& a,int& b)                    // function for swapping the values stored in a and b
{
  a=a+b;b=a-b;a=a-b;
}

void MaxHeapify(int *H,int n,int k)         // max-heapify function for setting the ordering property of max heap
{
  int max=k;
  if((2*k+1)<n){if(H[max]<H[2*k+1])max=2*k+1;}
  if((2*k+2)<n){if(H[max]<H[2*k+2])max=2*k+2;}
  if(max==k)return;
  else {swap(H[k],H[max]);MaxHeapify(H,n,max);}
}

void insertMax(int *H,int& n,int a)         //  inserting an element in the max heap
{
  H[n]=a;int i=n;
  while((i-1)/2>=0)
  {
    if(H[(i-1)/2]>=H[i]){n++;return;}
    else {swap(H[(i-1)/2],H[i]);i=(i-1)/2;}
  }
}

int findMax(int *H,int n)                   //  returns maximum element in the max heap in O(1) time
{ 
  if(n==0)return -1;
  return H[0];
} 

void deleteMax(int *H,int& n)               //  deletes the maximum element in the max heap
{
  H[0]=H[n-1];n--;
  MaxHeapify(H,n,0);
}

void MinHeapify(int *H,int n,int k)         // min-heapify function for setting the ordering property of min heap 
{
  int min=k;
  if((-n+2*k-1)>=0){if(H[-n+2*k-1]<H[min])min=(-n+2*k-1);}
  if((-n+2*k)>=0){if(H[-n+2*k]<H[min])min=(-n+2*k);}
  if(min==k)return;
  else {swap(H[k],H[min]);MinHeapify(H,n,min);}
}

void insertMin(int *H,int& n,int a)         // inserts an element in the min heap
{
  H=H-1;n++;
  H[0]=a;int i=0;
  while((i+n+1)/2<n)
  {
  if(H[(i+n+1)/2]<=H[i]){return;}
  if(H[(i+n+1)/2]>H[i]){swap(H[(i+n+1)/2],H[i]);i=(i+n+1)/2;}
  }
}

int findMin(int *H,int n)                    // returns the minimum element in the min heap in O(1) time
{
  if(n==0) return -1;
  else return H[n-1]; 
}

void deleteMin(int *H,int& n)                // deletes the minimum element in the min heap
{
  H[n-1]=H[0];n--;H=H+1;
  MinHeapify(H,n,n-1);
}

int findMedian(int *H,int n,int N1,int N2)    // returns the median element in the ned heap in O(1) time 
{  
  if(N1==0&&N2==0)return -1;
  else if(N1==N2)return (H[0]+H[n-1])/2;
  else return H[n-1];
}
 
void insertMed(int *H,int n,int& N1,int& N2,int x)   // inserts an element in the med heap
{
  int m=findMedian(H,n,N1,N2);
  if(m==-1){H[n-1]=x;N2++;return;}
  if(x<=m)
  {
    if(N2==N1+1)insertMax(H,N1,x);
    else
    {
       int max=findMax(H,N1);deleteMax(H,N1);
       insertMin(H+n-N2,N2,max);insertMax(H,N1,x);
    }
  }
  else
  {
    if(N2==N1)insertMin(H+n-N2,N2,x);
    else
    {
      int min=findMin(H+n-N2,N2);deleteMin(H+n-N2,N2);
      insertMax(H,N1,min);insertMin(H+n-N2,N2,x);  
    }
  }
}
 

int main()
{                                                                                                 
  int n=200000,H[200000],N1=0,N2=0,M;                                   int i=0,x;
  char s[1000];
  scanf("%s",s);
  while(s[0]!='E')
  { 
    if(s[0]=='A'){scanf("%d",&x);insertMed(H,n,N1,N2,x);}
    if(s[0]=='M'){printf("%d\n",findMedian(H,n,N1,N2));}
    scanf("%s",s);
  }
  


  return 0;
}

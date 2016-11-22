#include <deque>
#include <iostream>
#include <cstdio>

using namespace std;

void maxSlidingWindow(int A[], int n, int w, int B[],int C[]) {
  deque<int> Q,R;
  for (int i = 0; i < w; i++) {
    while (!Q.empty() && A[i] >= A[Q.back()])
      Q.pop_back();
    while (!R.empty() && A[i] <= A[R.back()])
      R.pop_back();
    Q.push_back(i);
    R.push_back(i);
  }
  for (int i = w; i < n; i++) {
    B[i-w] = A[Q.front()];
    C[i-w] = A[R.front()];
    while (!Q.empty() && A[i] >= A[Q.back()])
      Q.pop_back();
    while (!R.empty() && A[i] <= A[R.back()])
      R.pop_back();
    while (!Q.empty() && Q.front() <= i-w)
      Q.pop_front();
        while (!R.empty() && R.front() <= i-w)
      R.pop_front();
    Q.push_back(i);
    R.push_back(i);
  }
  B[n-w] = A[Q.front()];
  C[n-w] = A[R.front()];
}

int main()
{
	int A[400005] ,n,i,B[400005],C[400005],w,ways = 0;
	scanf("%d %d",&n,&w);
	for(i = 0;i < n;i++)
	{
		scanf("%d",&A[i]);
	}
	if(w == 1)
	{
		printf("%d",n);
		return 0;
	}
	if(w==2)
	{
		for(i = 0;i < n-1;i++)
		{
			if((A[i]==A[i+1]+1) || (A[i]==A[i+1]-1))
				ways++;
		}
		printf("%d",ways);
		return 0;
	}
	maxSlidingWindow(A,n,w,B,C);
	for(i = 0;i < n-w;i++)
	{
		if((B[i]-C[i]+1) == w)
			ways++;
	}
	printf("%d",ways);
	return 0;
}


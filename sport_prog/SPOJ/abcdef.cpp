#include <bits/stdc++.h>
using namespace std;

#define BUF 4096
class FastIO
{
	int Bufsize,oBuffersize;
	int bufferCounter,oBufferCounter;
	char Buffer[65536],oBuffer[4097];
	
	void align()
	{
		while(bufferCounter < Bufsize && Buffer[bufferCounter] < '0' && Buffer[bufferCounter] != '-')
			bufferCounter++;
			
		if(bufferCounter == Bufsize)
		{
			fread(Buffer,1,Bufsize,stdin);
			bufferCounter = 0;
			while(bufferCounter < Bufsize && Buffer[bufferCounter] < '0' && Buffer[bufferCounter] != '-')
				bufferCounter++;
		}
	}
	void FlushOBuffer()
	{
		oBuffer[oBuffersize] = '\0';
		fwrite(oBuffer,1,oBuffersize,stdout);
		oBufferCounter = 0;
	}
	
	public:
	
	FastIO(int Bufsize = 65536,int oBuffersize = 4096)
	{
		this->Bufsize = Bufsize;
		bufferCounter = 0;
		
		this->oBuffersize = oBuffersize;
		oBufferCounter = 0;
	}
	
	int readInt(int &n)
	{
		bool negativeFlag = false;
		align();

		if(Buffer[bufferCounter] == '-')
			negativeFlag = true,bufferCounter++;
			
		n = 0;
		while(bufferCounter < Bufsize && Buffer[bufferCounter] >= '0')
			n = (n*10) + (Buffer[bufferCounter++] - '0');
			
		if(bufferCounter == Bufsize)
		{
			fread(Buffer,1,Bufsize,stdin);
			bufferCounter = 0;
			if(Buffer[bufferCounter] == '-')
				negativeFlag = true,bufferCounter++;
				
			while(bufferCounter < Bufsize && Buffer[bufferCounter] >= '0')
				n = (n*10) + (Buffer[bufferCounter++] - '0');
		}
		
		if(negativeFlag)
			n = -n;
	}
	
	int readChar(char &c)
	{
		align();
		c = Buffer[bufferCounter++];
	}
	
	int readLong(long long &n)
	{
		bool negativeFlag = false;
		align();

		if(Buffer[bufferCounter] == '-')
			negativeFlag = true,bufferCounter++;
			
		n = 0;
		while(bufferCounter < Bufsize && Buffer[bufferCounter] >= '0')
			n = (n*10) + (Buffer[bufferCounter++] - '0');
			
		if(bufferCounter == Bufsize)
		{
			fread(Buffer,1,Bufsize,stdin);
			bufferCounter = 0;
			if(Buffer[bufferCounter] == '-')
				negativeFlag = true,bufferCounter++;
				
			while(bufferCounter < Bufsize && Buffer[bufferCounter] >= '0')
				n = (n*10) + (Buffer[bufferCounter++] - '0');
		}
		
		if(negativeFlag)
			n = -n;
	}
	
	int readStr(char *c)
	{
		int cc = 0;
		align();
		while(bufferCounter < Bufsize && Buffer[bufferCounter] >= '0')
			c[cc++] = Buffer[bufferCounter++];
		if(bufferCounter == Bufsize)
		{
			fread(Buffer,1,Bufsize,stdin);
			bufferCounter = 0;
			while(bufferCounter < Bufsize && Buffer[bufferCounter] >= '0')
				c[cc++] = Buffer[bufferCounter++];
		}
		c[cc] = '\0';
	}
	
	template <class T>
	void printInt(const T &n)
	{
		T i = n;
		int ct = 0,r;
		bool negativeFlag = false;
		char tempstr[12];
		if(i == 0)
		{
			oBuffer[oBufferCounter++] = '0';
			return ;
		}
		if(i < 0)
		{
			negativeFlag = true;
			i = -i;
		}
		while(i > 0)
		{
			r = i%10;
			tempstr[ct++] = r + '0';
			i = i/10;
		}
		if(negativeFlag)
			oBuffer[oBufferCounter++] = '-';
		ct--;
		while(ct >= 0)
		{
			oBuffer[oBufferCounter++] = tempstr[ct--];
			if(oBufferCounter == oBuffersize)
				FlushOBuffer();
		}		
	}
	
	void printStr(const char *str)
	{
		int cs = 0;
		while(str[cs]!='\0')
		{
			oBuffer[oBufferCounter++] = str[cs++];
			if(oBufferCounter == oBuffersize)
				FlushOBuffer();
		}
	}
	
	~FastIO()
	{
		oBuffer[oBufferCounter] = '\0';
		fwrite(oBuffer,1,oBufferCounter,stdout);
	}
} io;


int main()
{
	int n,val,i,j,k,l1,l2,c1,c2,a[105],sum,v1[1000000],v2[1000000],cv1 = 0,cv2 = 0;
	//vector<int> v1,v2;
	io.readInt(n);
	for(i = 0;i < n;i++)
	{
		io.readInt(a[i]);
	}
	for(i = 0;i < n;i++)
	{
		for(j = 0;j < n;j++)
		{
			for(k = 0;k < n;k++)
			{
				//v1.push_back(a[i]*a[j] + a[k]);
				v1[cv1++] = a[i]*a[j] + a[k];
				if(a[i] != 0)
					//v2.push_back(a[i]*(a[j]+a[k]));
					v2[cv2++] = a[i]*(a[j]+a[k]);
			}
		}
	}
	//sort(v1.begin(),v1.end());
	//sort(v2.begin(),v2.end());
	sort(v1,v1+cv1);
	sort(v2,v2+cv2);
	l1 = cv1;
	l2 = cv2;
	i = 0;
	j = 0;
	sum = 0;
	while(i<l1 && j<l2)
	{
		if(v1[i] == v2[j])
		{
			val = v1[i];
			c1 = 0;
			c2 = 0;
			while(j<l2 && v2[j] == val)
			{
				j++;
				c2++;
			}
			while(i<l1 && v1[i] == val)
			{
				i++;
				c1++;
			}
			sum+=c1*c2;
		}
		else if(v1[i] < v2[j])
			i++;
		else
			j++;
	}
	printf("%d\n",sum);
	return 0;
}


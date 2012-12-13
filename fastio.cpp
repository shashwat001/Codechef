#include <cstdio>
#include <cstdlib>
static class FastIO
{
	int Bufsize,oBuffersize;
	int bufferCounter,oBufferCounter;
	char *Buffer,*oBuffer;
	
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
		fwrite(oBuffer,1,oBuffersize,stdout);
		oBufferCounter = 0;
	}
	
	public:
	
	FastIO(int Bufsize = 4096,int oBuffersize = 4096)
	{
		this->Bufsize = Bufsize;
		bufferCounter = 0;
		Buffer = (char *)malloc(sizeof(char)*Bufsize);
		
		this->oBuffersize = oBuffersize;
		oBufferCounter = 0;
		oBuffer = (char*)malloc(sizeof(char)*oBuffersize);
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
			align();
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
			align();
			if(Buffer[bufferCounter] == '-')
				negativeFlag = true,bufferCounter++;
				
			while(bufferCounter < Bufsize && Buffer[bufferCounter] >= '0')
				n = (n*10) + (Buffer[bufferCounter++] - '0');
		}
		
		if(negativeFlag)
			n = -n;
	}
	
	int readString(char *c)
	{
		int cc = 0;
		align();
		while(bufferCounter < Bufsize && Buffer[bufferCounter] >= '0')
			c[cc++] = Buffer[bufferCounter++];
		if(bufferCounter == Bufsize)
		{
			align();
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
		FlushOBuffer();
		free(Buffer);
		free(oBuffer);
	}
};

int main()
{
	return 0;
}

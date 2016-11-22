#include <bits/stdc++.h>
#define MAXLEN 555555
/*Suffix arrays construction - taken from github */
using namespace std;

int len, it; //length of the string, and the iterator
string s="";
int SA[MAXLEN], LCP[MAXLEN]; //SA+LCP
int tmp[MAXLEN], posInSA[MAXLEN]; //position of i in SA, used as a hint for sorting
int currPaired; //used in LCP build

bool suffcmp(int i, int j)//used for smart sorting
{
    //different bucket
    if(posInSA[i]!=posInSA[j])
        return posInSA[i] < posInSA[j];
    //same bucket, jump it chars
    //rinse and repeat
    i+=it;
    j+=it;
    if(i<len && j<len)
        return posInSA[i] < posInSA[j];
    else
        return i > j;
}

//O(len log^2 len)
//sort the array of suffixes
void buildSA()
{
    //initialize SA
    for(int i=0;i<=len-1;i++)
    {
        SA[i]=i;
        posInSA[i]=s[i]; //initial sorting hint is first char
    }
    for(it=1;it<=2*len;it*=2) //exponential increments
    {
        //sort using the current hint
        sort(SA,SA+len,suffcmp);

        //update the hints
        //(create the buckets, for every inequality tmp++)
        //preparing for the next iteration
        for(int i=0;i<=len-2;i++)
        {
            tmp[i+1]=tmp[i];
            if(suffcmp(SA[i],SA[i+1]))
                tmp[i+1]++;
        }
        //copy the buckets where they belong
        for(int i=0;i<=len-1;i++)
            posInSA[SA[i]]=tmp[i];
        //sorted?
        if(tmp[len-1]==len-1)
            break;
    }
}

//O(len)
//LCP[i] := LCP(SA[i],SA[i+1])
void buildLCP()
{
    //variable init
    int j;
    currPaired=0;
    //main loop(banana,anana,nana,ana,na,a)
    for(int i=0;i<=len-1;i++)
      if(posInSA[i]!=len-1) //s[len] doesn't exist
      {
          //we are currently computing LCP(i,j=i's successor in SA)
          j=SA[posInSA[i]+1];
          //manually find the longest common prefix
          while( s[i+currPaired] == s[j+currPaired] )
             currPaired++;
          //write it down
          LCP[posInSA[i]]=currPaired;
          //decrease it only by one to prepare for the next iteration
          //if SA[posInSA[i]] and SA[posInSA[j]] have currPaired in common
          //the successor of SA[posInSA[i+1]] must have at least currPaired-1
          //in common with SA[posInSA[i+1]] (SA[posInSA[i+1]]=SA[posInSA[i]] without the first char)
          if(currPaired>0)
            currPaired--;
      }
}

int main()
{
    //test
    string s1,s2;
    cin>>s1>>s2;
    s=s1+"#"+s2;
	len=s1.length()+1+s2.length();
    buildSA();
    buildLCP();
	int IDX1=10000000;
	//int IDX2=10000000;
	int i;
	string ans="";
	int ans_len=0;
	int max_LCP=-1;
	for(i=0;i<len-1;i++)//Traverse LCP array
	{
		if(LCP[i]>=max_LCP)
		{
			
			//cout<<"entered"<<endl;
			int val1=SA[i];
			int val2=SA[i+1];
			int left=min(val1,val2);
			int right=max(val1,val2);
			//cout<<left<<" "<<right<<endl;
			if((left+LCP[i])<=s1.length() && (right>(s1.length())))
			{
				if(LCP[i]>max_LCP)
				{
					ans_len=LCP[i];
					ans=s.substr(left,LCP[i]);
					IDX1=right;
				}
				else if (right<IDX1)
				{
					//cout<<"y"<<endl;
					ans_len=LCP[i];
					ans=s.substr(left,LCP[i]);
					IDX1=right;
					
				}
				max_LCP=LCP[i];
			}
			
		}
				//cout<<s.substr(left,LCP[i])<<" "<<s.substr(right,LCP[i])<<endl;
	}
	if(ans_len==0)
	{
		cout<<0<<endl;
	}
	else
	{			
	cout<<ans<<endl;
	cout<<ans_len<<endl;
	}
	
    return 0;
}
/*
Input 1:
adsyufsfdsfdsf
fdyusgfdfyu

Output 1:
fd
2
 
Input 2:
adsyufsfdsfdsf
bbbbbbbbb

Output 2:
0
Input 3:
abcdef
defabc

Output 3:
def
3
*/

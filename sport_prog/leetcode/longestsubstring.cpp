//https://leetcode.com/problems/longest-substring-without-repeating-characters/description/



#include<iostream>

using namespace std;

int main()
{
    string input;
    cin>> input;

    int maxlength = 0,currlength = 0;
    int lastindex[256];

    fill(lastindex, lastindex+256,-1);

    for (int i = 0;i < input.size(); i++)
    {
        if(lastindex[input[i]] == -1)
        {
            currlength++;
        }
        else if(lastindex[input[i]] < i - currlength )
        {
            currlength++;
        }
        else
        {
            currlength = i - lastindex[input[i]];
        }
        maxlength = max(maxlength,currlength);
        lastindex[input[i]] = i;
    }
    cout<<maxlength;
    return 0;
}

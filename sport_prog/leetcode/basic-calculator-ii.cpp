#include <iostream>
#include <stack>

using namespace std;

class Solution {
    
    stack<int> intstack;
    stack<char> operatorstack;

public:
    int calculate(string s) 
    {
        int i = 0,curval = 0;
        
        while(i < s.size())
        {
            
            if(s[i] >= '0' && s[i] <= '9')
            {
                curval = curval*10 + (s[i] - '0');
            }
            
            else if(s[i] == '*' || s[i] == '/' || s[i] == '+' || s[i] == '-')
            {
                intstack.push(curval);
                curval = 0;

                if(s[i] == '+' || s[i] == '-')
                {
                    reduce();
                }
                else
                {
                    if(!operatorstack.empty())
                    {
                        char topoperator = operatorstack.top();
                        if(topoperator == '*' || topoperator == '/')
                        {
                            operatorstack.pop();
                            int second = intstack.top();
                            intstack.pop();
                            int first = intstack.top();
                            intstack.pop();
                            if(topoperator == '*')
                                intstack.push(first*second);
                            if(topoperator == '/')
                                intstack.push(first/second);
                        }
                    }
                }
                operatorstack.push(s[i]);
            }
            i++;
        }
        intstack.push(curval);
        reduce();
        
        return intstack.top();
    }

    void reduce()
    {
        while(!operatorstack.empty())
        {
            char topoperator = operatorstack.top();
            operatorstack.pop();
            int second = intstack.top();
            intstack.pop();
            int first = intstack.top();
            intstack.pop();
            if(topoperator == '*')
                intstack.push(first*second);
            if(topoperator == '/')
                intstack.push(first/second);
            if(topoperator == '+')
                intstack.push(first+second);
            if(topoperator == '-')
                intstack.push(first-second);
        }
    }
};

int main()
{
    string s;
    cin >> s;
    cout<< Solution().calculate(s);
    return 0;
}

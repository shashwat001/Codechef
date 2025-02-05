#include <iostream>
#include <vector>
#include <sstream>
#include <cstdio>
#include <cassert>

using namespace std;

class Solution {
public:
    int strangePrinter(string s) 
    {
        vector<vector<int> > dp(s.size(), vector<int>(s.size(),100000));
        
        for(int i = 0;i < s.size(); i++)
        {
            dp[i][i] = 1;
        }
        
        for(int i = 2;i <= s.size(); i++)
        {
            for(int j = 0; j < s.size() - (i-1); j++)
            {
                int temp = dp[j][j+i-1];
                for(int k = 0; k < i-1;k++)
                {
                    if(s[j+k] == s[j+i-1])
                    {
                        temp = min(temp,dp[j][j+k] + dp[j+k+1][j+i-1] - 1);
                    }
                    else
                    {
                        temp = min(temp,dp[j][j+k] + dp[j+k+1][j+i-1]);
                    }
                }
                dp[j][j+i-1] = temp;
            }
        }
        
        return dp[0][s.size()-1];
    }
};

string stringToString(string input) {
    assert(input.length() >= 2);
    string result;
    for (int i = 1; i < input.length() -1; i++) {
        char currentChar = input[i];
        if (input[i] == '\\') {
            char nextChar = input[i+1];
            switch (nextChar) {
                case '\"': result.push_back('\"'); break;
                case '/' : result.push_back('/'); break;
                case '\\': result.push_back('\\'); break;
                case 'b' : result.push_back('\b'); break;
                case 'f' : result.push_back('\f'); break;
                case 'r' : result.push_back('\r'); break;
                case 'n' : result.push_back('\n'); break;
                case 't' : result.push_back('\t'); break;
                default: break;
            }
            i++;
        } else {
          result.push_back(currentChar);
        }
    }
    return result;
}

int main() {
    string line;
    while (getline(cin, line)) {
        string s = stringToString(line);
        
        int ret = Solution().strangePrinter(s);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}

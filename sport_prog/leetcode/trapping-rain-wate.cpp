#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>
#include <stack>
#include <sstream>

using namespace std;

class Solution {
    
    typedef struct stackelem
    {
        int index;
        int tapped;
        
        public:
        stackelem(int index, int tapped) : index(index), tapped(tapped)
        {}
    } stackelem;
    
public:
    int trap(vector<int>& height) 
    {
        stack<stackelem> s;
        vector<stackelem> heightv;
        
        for(int j = 0;j < height.size(); j++)
        {
            heightv.push_back(stackelem(j, 0));
        }
        int i = 0;
        int res = 0;
        while(i < height.size())
        {
            while(i < height.size() && (s.empty() || height[s.top().index] > height[i]))
            {
                s.push(heightv[i]);
                i++;
            }
            while(i < height.size() && height[i] >= height[s.top().index])
            {
                stackelem top = s.top();
                s.pop();
                if(s.empty())
                {
                    res = res + top.tapped;
                    s.push(heightv[i]);
                    i++;
                }
                else
                {
                    stackelem prevtop = s.top();
                    if(height[prevtop.index] > height[i])
                    {
                        int currtapped = (height[i] - height[top.index]) * (i - prevtop.index - 1) ;
                        heightv[i].tapped += (currtapped + top.tapped);
                    }
                    else
                    {
                        int currtapped = (height[prevtop.index] - height[top.index]) * (i - prevtop.index - 1);
                        heightv[i].tapped += (currtapped + top.tapped);
                    }
                }
                
                
            }
        }
        while(!s.empty())
        {
            stackelem top = s.top();
            s.pop();
            res += top.tapped;
        }
        return res;
    }
};

void trimLeftTrailingSpaces(string &input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
        return !isspace(ch);
    }));
}

void trimRightTrailingSpaces(string &input) {
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
        return !isspace(ch);
    }).base(), input.end());
}

vector<int> stringToIntegerVector(string input) {
    vector<int> output;
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    stringstream ss;
    ss.str(input);
    string item;
    char delim = ',';
    while (getline(ss, item, delim)) {
        output.push_back(stoi(item));
    }
    return output;
}

int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> height = stringToIntegerVector(line);
        
        int ret = Solution().trap(height);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}

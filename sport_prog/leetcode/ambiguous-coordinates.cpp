#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    struct State
    {
        string first;
        string second;
        int state;
        int part;
        
        public: State(string first, string second, int state, int part):first(first), second(second), state(state), part(part)
        {
            
        }
    } ;

    
    vector<string> ambiguousCoordinates(string S) 
    {
        int empty = 0,
        zeroint = 1,
        integer = 2,
        emptydecimal = 3,
        zerodecimal = 4,
        decimal = 5;
        
        vector<State> currState, nextState;
        currState.push_back(State("", "", empty,0));
        
        for(int i = 0; i < S.size();i++)
        {
            for(State state : currState)
            {
                if(state.state == empty && isZero(S[i]))
                {
                    nextState.push_back(State(string(1,S[i]), state.second, zeroint, state.part));
                    nextState.push_back(State(string(1,S[i]) + '.', state.second, emptydecimal, state.part));
                    if(state.part == 0)
                    {
                        nextState.push_back(State("", string(1,S[i]), empty, 1));
                    }
                }
                else if(state.state == empty && isDigit(S[i]))
                {
                    nextState.push_back(State(string(1,S[i]), state.second, integer, state.part));
                    nextState.push_back(State(string(1,S[i]) + '.', state.second, emptydecimal, state.part));
                    if(state.part == 0)
                    {
                        nextState.push_back(State("", string(1,S[i]), empty, 1));
                    }
                }
                else if(state.state == integer && isDigit(S[i]))
                {
                    nextState.push_back(State( string(state.first + S[i]), state.second, integer, state.part));
                    nextState.push_back(State(string(state.first + S[i]) + '.', state.second, emptydecimal, state.part));
                    if(state.part == 0)
                    {
                        nextState.push_back(State("", state.first += S[i], empty, 1));
                    }
                }
                else if(state.state == emptydecimal && isZero(S[i]))
                {
                    nextState.push_back(State( string(state.first + S[i]), state.second, zerodecimal, state.part));
                }
                else if(state.state == emptydecimal && isDigit(S[i]))
                {
                    nextState.push_back(State( string(state.first + S[i]), state.second, decimal, state.part));
                    if(state.part == 0)
                    {
                        nextState.push_back(State( "", string(state.first + S[i]), empty, 1));
                    }
                }
                else if(state.state == zerodecimal && isZero(S[i]))
                {
                    nextState.push_back(State( string(state.first + S[i]), state.second, zerodecimal, state.part));
                }
                else if(state.state == zerodecimal && isDigit(S[i]))
                {
                    nextState.push_back(State( string(state.first + S[i]), state.second, decimal, state.part));
                    if(state.part == 0)
                    {
                        nextState.push_back(State( "", string(state.first + S[i]), empty, 1));
                    }
                }
                else if(state.state == decimal && isZero(S[i]))
                {
                    nextState.push_back(State( string(state.first + S[i]), state.second, zerodecimal, state.part));
                }
                else if(state.state == decimal && isDigit(S[i]))
                {
                    nextState.push_back(State( string(state.first + S[i]), state.second, decimal, state.part));
                    if(state.part == 0)
                    {
                        nextState.push_back(State( "", string(state.first + S[i]), empty, 1));
                    }
                }
                
            }
            currState = nextState;
            nextState.clear();
        }
        
        vector<string> result;
        for(State state: currState)
        {
            if(state.part == 1 && state.first != "" && (state.state == integer || state.state == decimal || state.state == zeroint))
            {
                result.push_back(state.second + ", " + state.first);
            }
        }
        return result;
        
    }
    
    bool isZero(char c)
    {
        if(c == '0')
            return true;
        return false;
    }
    
    bool isDigit(char c)
    {
        if(c >= '0' && c <= '9')
            return true;
        return false;
    }
};

int main()
{
    string input;
    cin>> input;
    for(string s : Solution().ambiguousCoordinates(input))
        cout<<s<<endl;
    return 0;
}


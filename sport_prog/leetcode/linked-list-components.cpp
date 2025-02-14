#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <sstream>
/**
 * Definition for singly-linked list.*/
  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };


using namespace std;
class Solution {
public:
    int numComponents(ListNode* head, vector<int>& G) 
    {
        set<int> Gset;
        for(int nums : G)
        {
            Gset.insert(nums);
        }
        
        int groups = 0;
        bool newgroup = true;
        
        while(head)
        {
            if(Gset.find(head->val) != Gset.end() && newgroup)
            {
                cout<<"here ";
                newgroup = false;
                groups++;
            }
            else
            {
                newgroup = true;
            }
            head = head->next;
        }
        
        return groups;
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

ListNode* stringToListNode(string input) {
    // Generate list from the input
    vector<int> list = stringToIntegerVector(input);

    // Now convert that list into linked list
    ListNode* dummyRoot = new ListNode(0);
    ListNode* ptr = dummyRoot;
    for(int item : list) {
        ptr->next = new ListNode(item);
        ptr = ptr->next;
    }
    ptr = dummyRoot->next;
    delete dummyRoot;
    return ptr;
}

int main() {
    string line;
    while (getline(cin, line)) {
        ListNode* head = stringToListNode(line);
        getline(cin, line);
        vector<int> G = stringToIntegerVector(line);
        
        int ret = Solution().numComponents(head, G);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}

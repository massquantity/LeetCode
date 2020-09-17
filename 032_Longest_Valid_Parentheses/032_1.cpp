#include <iostream>
#include <string>
#include <vector>
#include <climits>
#include <algorithm>
#include <cstring>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <stack>
#include <bitset>
#include <array>
#include <queue>
#include <sstream>
#include <set>
using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> stack;
        stack.push(-1);
        int maxVal = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                stack.push(i);
            } else {
                stack.pop();
                if (stack.empty())
                    stack.push(i);
                else
                    maxVal = max(maxVal, i - stack.top());
            }
        }
        return maxVal;
    }
};


int main() {
    string s = ")()())";
    Solution so;
    cout << so.longestValidParentheses(s) << endl;
}



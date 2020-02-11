#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <stack>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        vector<char> v;
        for (char c : s) {
            if (c == '{')
                v.push_back('}');
            else if (c == '[')
                v.push_back(']');
            else if (c == '(')
                v.emplace_back(')');
            else if (v.empty())
                return false;
            else if (v[v.size() - 1] != c)
                return false;
            else if (v[v.size() - 1] == c)
                v.pop_back();
        }
        return v.empty();
    }

    bool isValid2(string s) {
        vector<char> v;
        unordered_map<char, char> m;
        m['['] = ']';
        m['{'] = '}';
        m['('] = ')';
        for (int i = 0; i < s.length(); ++i) {
            if (m.find(s[i]) != m.end())
                v.push_back(m[s[i]]);
            else if (v.empty() || v[v.size() - 1] != s[i])
                return false;
            else if (v[v.size() - 1] == s[i])
                v.pop_back();
        }
        return v.empty();
    }

    bool isValid3(string s) {
        stack<char> v;
        for (int i = 0; i < s.length(); ++i) {
            switch(s[i]) {
                case '[': case '{': case '(': v.push(s[i]); break;
                case ']':
                    if (v.empty() || v.top() != '[')
                        return false;
                    else
                        v.pop();
                    break;
                case '}':
                    if (v.empty() || v.top() != '{')
                        return false;
                    else
                        v.pop();
                    break;
                case ')':
                    if (v.empty() || v.top() != '(')
                        return false;
                    else
                        v.pop();
                    break;
                default:
                    break;
            }
        }
        return v.empty();
    }
};

int main() {
    Solution s;
    string ss = "}";
    cout << s.isValid3(ss) << endl;
}
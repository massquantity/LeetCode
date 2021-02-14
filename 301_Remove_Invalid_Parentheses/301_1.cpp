class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        vector<string> res;
        int left = 0, right = 0;
        for (char c : s) {
            if (c == '(') {
                left++;
            } else if (c == ')') {
                if (left > 0) left--;
                else          right++;
            }
        }
        dfs(s, 0, left, right, res);
        return res;
    }

    void dfs(string s, int idx, int left, int right, vector<string> &res) {
        if (left == 0 && right == 0 && isValid(s)) {
            res.push_back(s);
            return;
        }
        for (int i = idx; i < s.size(); i++) {
            if (i > idx && s[i] == s[i - 1]) continue;
            string tmp = s.substr(0, i) + s.substr(i + 1, s.size() - i - 1);
            if (left > 0 && s[i] == '(') {
                dfs(tmp, i, left - 1, right, res);
            } 
            if (right > 0 && s[i] == ')') {
                dfs(tmp, i, left, right - 1, res);
            }
        }
    }

    bool isValid(string s) {
        int count = 0;
        for (char c : s) {
            if (c == '(')      count++;
            else if (c == ')') count--;
            if (count < 0) return false;
        }
        return count == 0;
    }
};

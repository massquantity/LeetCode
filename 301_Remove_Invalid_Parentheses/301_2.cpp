class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        unordered_set<string> res;
        string tmp;
        int left = 0, right = 0;
        for (char c : s) {
            if (c == '(') {
                left++;
            } else if (c == ')') {
                if (left > 0) left--;
                else          right++;
            }
        }
        dfs(s, tmp, 0, 0, 0, left, right, res);
        return vector<string>(res.begin(), res.end());
    }

    void dfs(string s, string &tmp, int idx, int leftKeep, int rightKeep, int left, int right, unordered_set<string> &res) {
        if (idx == s.size()) {
            if (left == 0 && right == 0) {
                res.insert(tmp);
            }
            return;
        }
        if (s[idx] == '(' && left > 0) {
            dfs(s, tmp, idx + 1, leftKeep, rightKeep, left - 1, right, res);
        }
        if (s[idx] == ')' && right > 0) {
            dfs(s, tmp, idx + 1, leftKeep, rightKeep, left, right - 1, res);
        }
        tmp.push_back(s[idx]);
        if (s[idx] != '(' && s[idx] != ')') {
            dfs(s, tmp, idx + 1, leftKeep, rightKeep, left, right, res);
        } else if (s[idx] == '(') {
            dfs(s, tmp, idx + 1, leftKeep + 1, rightKeep, left, right, res);
        } else if (leftKeep > rightKeep) {
            dfs(s, tmp, idx + 1, leftKeep, rightKeep + 1, left, right, res);
        }
        tmp.pop_back();
    }
};

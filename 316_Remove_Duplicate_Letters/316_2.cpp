class Solution {
public:
    string removeDuplicateLetters(string s) {
        stack<char> stack;
        int count[26];
        memset(count, 0, sizeof(count));
        for (int i = 0; i < s.size(); i++) {
            count[s[i] - 'a'] = i;
        }
        unordered_set<char> seen;
        for (int i = 0; i < s.size(); i++) {
            char c = s[i];
            if (seen.find(c) == seen.end()) {
                while (!stack.empty() && c < stack.top() && i < count[stack.top() - 'a']) {
                    seen.erase(stack.top());
                    stack.pop();
                }
                stack.emplace(c);
                seen.insert(c);
            }
        }

        string res;
        while (!stack.empty()) {
            res.push_back(stack.top());
            stack.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
class Solution {
public:
    string removeDuplicateLetters(string s) {
        stack<char> stack;
        int count[255];
        memset(count, 0, sizeof(count));
        for (char c : s) {
            count[c]++;
        }
        unordered_set<char> seen;
        for (char c : s) {
            if (seen.find(c) == seen.end()) {
                while (!stack.empty() && c < stack.top() && count[stack.top()] > 0) {
                    seen.erase(stack.top());
                    stack.pop();
                }
                stack.emplace(c);
                seen.insert(c);
            }
            count[c]--;
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
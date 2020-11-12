class Solution {
public:
    bool isValid(string s) {
        unordered_map<char, char> map;
        map[')'] = '(';
        map[']'] = '[';
        map['}'] = '{';
        stack<char> stack;
        for (char c : s) {
            if (stack.empty() && map.find(c) != map.end()) {
                return false;
            }
            else if (map.find(c) != map.end() && map[c] == stack.top()) {
                stack.pop();
            }
            else {
                stack.push(c);
            }
        }
        return stack.empty();
    }
};
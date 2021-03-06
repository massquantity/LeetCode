class Solution {
public:
    string decodeString(string s) {
        string res = "";
        int num = 0;
        stack<int> numStack;
        stack<string> resStack;
        for (char c : s) {
            if (c >= '0' && c <= '9') {
                num = num * 10 + (c - '0');
            } else if (c == '[') {
                numStack.push(num);
                resStack.push(res);
                num = 0;
                res.clear();
            } else if (c == ']') {
                string tmp = resStack.top();
                resStack.pop();
                int curNum = numStack.top();
                numStack.pop();
                for (int i = 0; i < curNum; i++) {
                    tmp += res;
                }
                res = tmp;
            } else {
                res.push_back(c);
            }
        }
        return res;
    }
};

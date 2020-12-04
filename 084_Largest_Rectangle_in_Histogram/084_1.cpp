class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int res = 0;
        int len = heights.size();
        stack<int> stack;
        for (int i = 0; i < len; i++) {
            while (!stack.empty() && heights[stack.top()] > heights[i]) {
                int curHeight = heights[stack.top()];
                stack.pop();
                while (!stack.empty() && heights[stack.top()] == curHeight)
                    stack.pop();
                int curWidth;
                if (stack.empty())
                    curWidth = i;
                else
                    curWidth = i - stack.top() - 1;
                res = max(res, curHeight * curWidth);
            }
            stack.push(i);
        }

        while (!stack.empty()) {
            int curHeight = heights[stack.top()];
            stack.pop();
            while (!stack.empty() && heights[stack.top()] == curHeight)
                stack.pop();
            int curWidth;
            if (stack.empty())
                curWidth = len;
            else
                curWidth = len - stack.top() - 1;
            res = max(res, curHeight * curWidth);
        }
        return res;
    }
};
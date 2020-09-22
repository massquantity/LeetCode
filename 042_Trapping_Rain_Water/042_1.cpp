class Solution {
public:
    int trap(vector<int>& height) {
        int res = 0;
        stack<int> stack;
        for (int i = 0; i < height.size(); i++) {
            while (!stack.empty() && height[stack.top()] < height[i]) {
                int cur = stack.top();
                stack.pop();
                if (stack.empty()) break;
                int l = stack.top();
                int r = i;
                int h = min(height[l], height[r]) - height[cur];
                res += (r - l - 1) * h;
            }
            stack.push(i);
        }
        return res;
    }
};
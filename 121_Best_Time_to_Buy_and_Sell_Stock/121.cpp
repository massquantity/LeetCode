class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = INT_MAX, maxPrice = 0;
        for (int p : prices) {
            minPrice = min(minPrice, p);
            maxPrice = max(maxPrice, p - minPrice);
        }
        return maxPrice;
    }
};
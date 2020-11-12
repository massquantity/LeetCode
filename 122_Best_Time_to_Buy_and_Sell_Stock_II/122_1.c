int maxProfit(int* prices, int pricesSize){
    int profit = 0;
    for (int i = 1; i < pricesSize; i++) {
        int tmp = prices[i] - prices[i - 1];
        if (tmp > 0) profit += tmp;
    }
    return profit;
}
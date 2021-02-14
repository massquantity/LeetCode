class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if (amount == 0) return 0;
        deque<int> queue;
        vector<bool> visited(amount + 1, false);
        visited[amount] = true;
        queue.push_back(amount);
        sort(coins.begin(), coins.end());
        int step = 1;
        while (!queue.empty()) {
            int size = queue.size();
            for (int i = 0; i < size; i++) {
                int tmp = queue.front();
                queue.pop_front();
                for (int coin : coins) {
                    int next = tmp - coin;
                    if (next == 0) return step;
                    if (next < 0) break;
                    if (!visited[next]) {
                        queue.push_back(next);
                        visited[next] = true;
                    }
                }
            }
            step++;
        }
        return -1;
    }
};

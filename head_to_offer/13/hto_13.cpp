#include <iostream>
#include <string>
#include <vector>
#include <climits>
#include <algorithm>
#include <cstring>
using namespace std;

// https://leetcode-cn.com/problems/ji-qi-ren-de-yun-dong-fan-wei-lcof/solution/mian-shi-ti-13-ji-qi-ren-de-yun-dong-fan-wei-dfs-b/
class Solution {
    vector<vector<bool>> visited;
    int m, n, k;
public:
    int movingCount(int m, int n, int k) {
        this->m = m, this->n = n, this->k = k;
        visited.resize(m, vector<bool>(n));
        return dfs(0, 0, 0, 0);
    }
private:
    int dfs(int i, int j, int si, int sj) {
        if (i >= m || j >= n || visited[i][j] || si + sj > k) return 0;
        visited[i][j] = true;
        return 1 + dfs(i + 1, j, (i + 1) % 10 ? si + 1 : si - 8, sj)
                 + dfs(i, j + 1, si, (j + 1) % 10 ? sj + 1 : sj - 8);
    }
};

int main() {
    Solution s;
    cout << s.movingCount(2, 3, 1) << endl;
}

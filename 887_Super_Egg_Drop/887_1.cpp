#include <iostream>
#include <string>
#include <vector>
#include <climits>
#include <algorithm>
#include <cstring>
#include <map>
using namespace std;

class Solution {
public:
    int superEggDrop(int K, int N) {
        if (K == 1) return N;
        if (N == 0) return 0;
        pair<int, int> p(K, N);
        if (memo.find(p) != memo.end()) return memo.at(p);
        int res = INT_MAX;
        int lo = 1, hi = N;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            int broken = superEggDrop(K - 1, mid - 1);
            int n_broken = superEggDrop(K, N - mid);
            if (broken < n_broken) {
                lo = mid + 1;
                res = min(res, n_broken + 1);
            } else {
                hi = mid - 1;
                res = min(res, broken + 1);
            }
        }
        memo[p] = res;
        return res;
    }

private:
    map<pair<int, int>, int> memo;
};

int main() {
    Solution s;
    cout << s.superEggDrop(4, 5000) << endl;
}

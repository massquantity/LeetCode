#include <iostream>
#include <string>
#include <vector>
#include <climits>
#include <algorithm>
#include <cstring>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <stack>
#include <bitset>
#include <array>
#include <queue>
#include <sstream>
#include <set>
using namespace std;

struct heapCompare {
    bool operator() (const int &a, const int &b) const {
        return a > b;
    }
};

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
    //    priority_queue<int, vector<int>, greater<int>> pq;
        priority_queue<int, vector<int>, heapCompare> pq;
        for (int &num : nums) {
            if (pq.size() < k) {
                pq.push(num);
            } else if (num > pq.top()) {
                pq.pop();
                pq.push(num);
            }
        }
        return pq.top();
    }
};



int main() {
    Solution s;
    vector<int> v {3,2,3,1,2,4,5,5,6,8};
    cout << s.findKthLargest(v, 4) << endl;
}

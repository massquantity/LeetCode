#include <vector>
#include <iostream>
#include <cmath>
#include <climits>
using namespace std;

class Solution {
public:
    int reverse(int x) {
        int res = 0;
        while (x != 0) {
            int pop = x % 10;
            x /= 10;
            if (res > INT_MAX / 10 || (res == INT_MAX / 10 && pop > INT_MAX % 10)) return 0;
            if (res < INT_MIN / 10 || (res == INT_MIN / 10 && pop < INT_MIN % 10)) return 0;
            res = res * 10 + pop;
        }
        return res;
    }
};


int main() {
    Solution s;
    cout << LONG_LONG_MAX << " " << INT_MAX << endl;
    cout << s.reverse(12345) << endl;
    cout << s.reverse(1534236469) << endl;
}
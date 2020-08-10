#include <iostream>
#include <bitset>
using namespace std;

class Solution {
public:
    int hammingWeight(uint32_t n) {
        return bitset<32>(n).count();
    }
};

int main() {
    Solution s;
    cout << s.hammingWeight(1) << endl;
}
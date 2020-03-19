#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        string s = to_string(x);
        string s2 = s;
        reverse(s2.begin(), s2.end());
        return s == s2;
    }
};


int main() {
    Solution s;
    int x = 13331;
    cout << boolalpha;
    cout << s.isPalindrome(x) << endl;
}
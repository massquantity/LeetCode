#pragma ide diagnostic ignored "openmp-use-default-none"
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
#include <omp.h>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> need, window;
        for (char c : t) {
            need[c]++;
        }

        int left = 0, right = 0;
        int valid = 0;
        int start = 0, minLen = INT_MAX;
        while (right < s.size()) {
            char c = s[right];
            right++;
            if (need.find(c) != need.end()) {
                window[c]++;
                if (window[c] == need[c])
                    valid++;
            }

            while (valid == need.size()) {
                if (right - left < minLen) {
                    start = left;
                    minLen = right - left;
                }
                char d = s[left];
                left++;
                if (need.find(d) != need.end()) {
                    if (window[d] == need[d])
                        valid--;
                    window[d]--;
                }
            }
        }
        return minLen == INT_MAX ? "" : s.substr(start, minLen);
    }
};

int main() {
    Solution s;
    cout << s.minWindow("ADOBECODEBANC", "ABC") << endl;
}


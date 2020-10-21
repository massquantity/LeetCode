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

class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") return "0";
        size_t len1 = num1.size();
        size_t len2 = num2.size();
        size_t total_len = len1 + len2;
        vector<int> mult(total_len, 0);
        for (int i = len1 - 1; i >= 0; i--) {
            for (int j = len2 - 1; j >= 0; j--) {
                int m = (num1[i] - '0') * (num2[j] - '0');
                int sum = m + mult[i + j + 1];
                mult[i + j + 1] = sum % 10;
                mult[i + j] += sum / 10;
            }
        }

        int k = 0;
        while (!mult[k] && k < total_len) k++;
        string res;
        while (k < total_len) {
            res.push_back(mult[k++] + '0');
        }
        return res;
    }
};


int main() {
    Solution so;
    cout << so.multiply("123", "456");
}


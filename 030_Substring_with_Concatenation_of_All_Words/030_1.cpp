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
    vector<int> findSubstring(string s, vector<string>& words) {
        if (s.empty() || words.empty()) return {};
        vector<int> res;
        size_t one_word = words[0].size();
        size_t word_num = words.size();
        size_t total_len = one_word * word_num;
        unordered_map<string, int> m1;
        for (const auto &w : words) m1[w]++;

        for (int i = 0; i < one_word; i++) {
            unordered_map<string, int> m2;
            int count = 0, left = i, right = i;
            while (right + one_word <= s.size()) {
                string w = s.substr(right, one_word);
                right += one_word;
                if (m1.find(w) == m1.end()) {
                    count = 0;
                    left = right;
                    m2.clear();
                } else {
                    m2[w]++;
                    count++;
                    while (m2.at(w) > m1.at(w)) {
                        string tmp_w = s.substr(left, one_word);
                        m2[tmp_w]--;
                        count--;
                        left += one_word;
                    }
                }

                if (count == word_num) res.push_back(left);
            }
        }
        return res;
    }
};


int main() {
    string s = "barfoothefoobarman";
    vector<string> words = {"foo","bar"};
    Solution so;
    for (int i : so.findSubstring(s, words))
        cout << i << " ";
}


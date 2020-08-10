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
    vector<string> permutation(string s) {
        c_len = s.size();
        c_char = new char[c_len + 1];
        strcpy(c_char, s.c_str());
        dfs(0);
        return res;
    }

    void dfs(int pos) {
        if (pos == c_len - 1) {
            res.emplace_back(string(c_char));
            return;
        }
        set<char> set;
        for (int i = pos; i < c_len; i++) {
            if (set.find(c_char[i]) != set.end()) continue;
            set.insert(c_char[i]);
            swap(c_char[pos], c_char[i]);
            dfs(pos + 1);
            swap(c_char[pos], c_char[i]);
        }
    }

private:
    vector<string> res;
    char *c_char;
    int c_len;
};

int main() {
    Solution s;
    for (string &str : s.permutation("abc")) {
        cout << str << endl;
    }
}


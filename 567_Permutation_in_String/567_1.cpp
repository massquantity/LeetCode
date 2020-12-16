#include <iostream>
#include <string>
#include <vector>

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int len1 = s1.size(), len2 = s2.size();
        if (len1 > len2) return false;
        vector<int> count1(26, 0);
        vector<int> count2(26, 0);
        for (int i = 0; i < len1; i++) {
            count1[s1[i] - 'a']++;
            count2[s2[i] - 'a']++;
        }

        for (int i = len1; i < len2; i++) {
            if (equal(count1, count2)) return true;
            int left  = s2[i - len1] - 'a';
            int right = s2[i] - 'a';
            count2[right]++;
            count2[left]--;
            
        }
        return equal(count1, count2);
    }

    bool equal(vector<int> c1, vector<int> c2) {
        for (int i = 0; i < 26; i++) {
            if (c1[i] != c2[i]) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    Solution s;
    cout << boolalpha << s.checkInclusion("abc", "dcda") << endl;
}

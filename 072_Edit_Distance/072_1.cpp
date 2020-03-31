#define min(a, b, c) ((a) < ((b) < (c) ? (b) : (c)) ? (a) : ((b) < (c) ? (b) : (c)));
typedef pair<int, int> P;

class Solution {
public:
    int minDistance(string word1, string word2) {
        return dpFunc(word1, word2, word1.size() - 1, word2.size() - 1);
    }

    int dpFunc(string word1, string word2, int i, int j) {
        if (memo.find(P(i, j)) != memo.end()) return memo[P(i, j)];
        if (i == -1) return j + 1;
        if (j == -1) return i + 1;
        if (word1[i] == word2[j])
            memo[P(i, j)] = dpFunc(word1, word2, i - 1, j - 1);
        else
            memo[P(i, j)] =  1 + min(dpFunc(word1, word2, i - 1, j),
                                     dpFunc(word1, word2, i, j - 1),
                                     dpFunc(word1, word2, i - 1, j - 1));
        return memo[P(i, j)];
    }
private:
    map<P, int> memo;
};
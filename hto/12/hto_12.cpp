#include <iostream>
#include <string>
#include <vector>
#include <climits>
#include <cstring>
using namespace std;

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int rows = board.size();
        int cols = board[0].size();
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                if (dfs(board, word, visited, i, j, 0)) return true;
            }
        }
        return false;
    }

private:
    bool dfs(vector<vector<char>> &board, string &word,
             vector<vector<bool>> &visited, int i, int j, int k) {
        if (k == word.size()) return true;
        if (i < 0 || i == board.size() || j < 0 || j == board[0].size() ||
            visited[i][j] || board[i][j] != word[k]) return false;
        visited[i][j] = true;
        bool res = dfs(board, word, visited, i + 1, j, k + 1) ||
                   dfs(board, word, visited, i - 1, j, k + 1) ||
                   dfs(board, word, visited, i, j + 1, k + 1) ||
                   dfs(board, word, visited, i, j - 1, k + 1);
        visited[i][j] = false;
        return res;
    }
};

int main() {
    vector<vector<char>> board = {{'A', 'B', 'C', 'E'},
                                  {'S', 'F', 'C', 'S'},
                                  {'A', 'D', 'E', 'E'}};
    string word = "ABCCED";
    Solution s;
    cout << boolalpha << s.exist(board, word) << endl;
}

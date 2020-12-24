class Solution {
public:
  vector<string> restoreIpAddresses(string s) {
    vector<string> res;
    string tmp;
    int n = s.size();
    dfs(res, tmp, 0, 0, s, n);
    return res;
  }

  void dfs(vector<string> &res, string tmp, int idx, int count, string &s, int size) {
    if (idx == size && count == 4) {
      res.emplace_back(tmp.substr(0, tmp.size() - 1));
      return;
    }
    if (count >= 4) return;
    for (int i = idx; i < idx + 3; i++) {
      if ((size - i) > 3 * (4 - count)) break;
      if (i >= size) break;
      if (s[idx] == '0') {
        dfs(res, tmp + "0.", i + 1, count + 1, s, size);
        break;
      }
      string subs = s.substr(idx, i - idx + 1);
      int num = stoi(subs);
      if (num > 0 && num <= 255) {
        dfs(res, tmp + subs + ".", i + 1, count + 1, s, size);
      }
    }
  }
};

class UnionFind {
public:
  int count;
  vector<int> parents;
  vector<int> sizes;
  explicit UnionFind(int n): count(n) {
    parents.resize(n);
    sizes.resize(n);
    fill(sizes.begin(), sizes.end(), 1);
    for (int i = 0; i < n; i++)
      parents[i] = i;
  }

  int find(int x) {
    while (parents[x] != x) {
        x = parents[x];
        parents[x] = parents[parents[x]];
    }
    return x;
  }

  void union_(int x, int y) {
    int rootX = find(x);
    int rootY = find(y);
    if (rootX == rootY) return;
    if (sizes[rootX] < sizes[rootY]) {
        parents[rootX] = rootY;
        sizes[rootY] += sizes[rootX];
    } else {
        parents[rootY] = rootX;
        sizes[rootX] += sizes[rootY];
    }
    count--;
  }
};

class Solution {
public:
  int numIslands(vector<vector<char>>& grid) {
    int m = grid.size(), n = grid[0].size();
    int spaces = 0;
    UnionFind uf{m * n};
    vector<vector<int>> directions{{0,1}, {1,0}};
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (grid[i][j] == '0') {
          spaces++;
        } else {
          if (i + 1 < m && grid[i + 1][j] == '1') {
            uf.union_(i * n + j, (i+1) * n + j);
          }
          if (j + 1 < n && grid[i][j + 1] == '1') {
            uf.union_(i * n + j, i * n + (j+1));
          }
        }
      }
    }
    return uf.count - spaces;
  }
};

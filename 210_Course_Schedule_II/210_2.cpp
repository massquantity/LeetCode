class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> res;
        if (numCourses == 0) return vector<int>(0);
        if (prerequisites.empty()) {
            for (int i = 0; i < numCourses; i++) {
                res.push_back(i);
            }
            return res;
        }

        vector<vector<int>> graph(numCourses, vector<int>());
        for (vector<int> &p : prerequisites) {
            graph[p[1]].push_back(p[0]);
        }

        bool valid = true;
        vector<int> visited(numCourses, 0);
        vector<int> stack;
        for (int i = 0; i < numCourses && valid; i++) {
            if (visited[i] == 0) {
                dfs(i, graph, visited, stack, valid);
            }
        }

        if (!valid) {
            return vector<int>();
        }
        reverse(stack.begin(), stack.end());
        return stack;
    }

    void dfs(int index, vector<vector<int>> &graph,
             vector<int> &visited, vector<int> &stack, bool &valid) {
        visited[index] = 1;
        for (const int &v : graph[index]) {
            if (visited[v] == 0) {
                dfs(v, graph, visited, stack, valid);
                if (!valid) return;
            }
            else if (visited[v] == 1) {
                valid = false;
                return;
            }
        }
        visited[index] = 2;
        stack.push_back(index);
    }
};

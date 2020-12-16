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

        vector<set<int>> graph(numCourses, set<int>());
        for (vector<int> &p : prerequisites) {
            graph[p[1]].insert(p[0]);
        }

        vector<int> marked(numCourses, 0);
        stack<int> stack;
        for (int i = 0; i < numCourses; i++) {
            if (dfs(i, graph, marked, stack)) {
                return vector<int>();
            }
        }
        while (!stack.empty()) {
            res.push_back(stack.top());
            stack.pop();
        }
        return res;
    }

    bool dfs(int index, vector<set<int>>& graph,
             vector<int>& marked, stack<int>& stack) {
        if (marked[index] == 1) return true;  // visited twice, has cycle
        if (marked[index] == 2) return false; // visit has finished, return
        marked[index] = 1;
        for (int s : graph[index]) {
            if (dfs(s, graph, marked, stack))
                return true;
        }

        marked[index] = 2;
        stack.push(index);
        return false;
    }
};

int main() {
    Solution s;
    vector<vector<int>> aa{{1,0},{2,0},{3,1},{3,2}};
    for (int v : s.findOrder(4, aa))
        cout << v << " ";
    cout << endl;
}
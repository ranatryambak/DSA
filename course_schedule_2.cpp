#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> v(n, 0);
        queue<pair<int, int>> q;
        vector<int> col(n);
        for (int i = 0; i < n; i++) {
            if (!v[i]) {
                v[i] = 1;
                col[i] = 0;
                q.push({i, 0});
                while (!q.empty()) {
                    auto [x, y] = q.front();
                    q.pop();
                    for (auto it : graph[x]) {
                        if (!v[it]) {
                            col[it] = !y;
                            v[it] = 1;
                            q.push({it, !y});
                        }
                        if (v[it] && col[it] == y) {
                            return false;
                        }
                    }
                }
            }
        }
        return true;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> graph = {
        {1, 3},
        {0, 2},
        {1, 3},
        {0, 2}
    };
    bool result = sol.isBipartite(graph);
    if (result) {
        cout << "Graph is bipartite." << endl;
    } else {
        cout << "Graph is not bipartite." << endl;
    }
    return 0;
}

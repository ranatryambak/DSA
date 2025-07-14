#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<int> adj[n];
        vector<int> v(n, 0);
        for (auto it : edges) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
            v[it[0]]++;
            v[it[1]]++;
        }

        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (v[i] == 1) q.push(i);
        }

        vector<int> ans = {0};

        while (!q.empty()) {
            int s = q.size();
            ans.clear();
            for (int i = 0; i < s; i++) {
                int tmp = q.front();
                q.pop();
                ans.push_back(tmp);
                for (auto it : adj[tmp]) {
                    v[it]--;
                    if (v[it] == 1) q.push(it);
                }
            }
        }

        return ans;
    }
};

int main() {
    Solution sol;
    int n = 6;
    vector<vector<int>> edges = {
        {0, 3}, {1, 3}, {2, 3}, {4, 3}, {5, 4}
    };

    vector<int> result = sol.findMinHeightTrees(n, edges);

    cout << "Roots of Minimum Height Trees: ";
    for (int node : result) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}

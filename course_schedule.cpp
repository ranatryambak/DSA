#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> v(numCourses, 0);
        vector<int> adj[numCourses];
        for (auto it : prerequisites) {
            v[it[1]]++;
            adj[it[0]].push_back(it[1]);
        }
        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (v[i] == 0) {
                q.push(i);
            }
        }
        vector<int> c;
        while (!q.empty()) {
            int tmp = q.front();
            q.pop();
            c.push_back(tmp);
            for (auto it : adj[tmp]) {
                v[it]--;
                if (v[it] == 0) q.push(it);
            }
        }
        return (c.size() == numCourses);
    }
};

int main() {
    Solution sol;
    int numCourses = 2;
    vector<vector<int>> prerequisites = {{1, 0}};
    bool result = sol.canFinish(numCourses, prerequisites);
    if (result) {
        cout << "You can finish all courses." << endl;
    } else {
        cout << "You cannot finish all courses." << endl;
    }
    return 0;
}

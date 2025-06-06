#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> adj[n];
        vector<int> in(n,0);
        vector<int> ans;
        for(int i=0;i<n;i++){
            for(auto it:graph[i]){
                adj[it].push_back(i);
            }
        }
        for(int i=0;i<n;i++){
            for(auto it:adj[i]){
                in[it]++;
            }
        }
        queue<int>q;
        for(int i=0;i<n;i++){
            if(in[i]==0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int tmp = q.front();
            q.pop();
            ans.push_back(tmp);
            for(auto it:adj[tmp]){
                in[it]--;
                if(in[it]==0){
                    q.push(it);
                }
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> graph = {{1,2},{2,3},{5},{0},{5},{},{}};
    vector<int> safeNodes = sol.eventualSafeNodes(graph);
    for(int node : safeNodes) {
        cout << node << " ";
    }
    cout << endl;
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int> v(n+1,INT_MAX);
        v[k] = 0;
        v[0] = 0;
        vector<pair<int,int>> adj[n+1];
        for(auto it:times){
            adj[it[0]].push_back({it[1],it[2]});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
        q.push({k,0});
        while(!q.empty()){
            int node = q.top().first;
            int d = q.top().second;
            q.pop();
            for(auto it:adj[node]){
                if(d+it.second<v[it.first]){
                    v[it.first] = d+it.second;
                    q.push({it.first,d+it.second});
                }
            }
        }
        int maxi = 0;
        for(int i=1;i<=n;i++){
            if(v[i]==INT_MAX) return -1;
            maxi = max(maxi,v[i]);
        }
        return maxi;
    }
};

int main() {
    Solution s;
    vector<vector<int>> times = {{2,1,1},{2,3,1},{3,4,1}};
    int n = 4, k = 2;
    cout << s.networkDelayTime(times, n, k) << endl;
    return 0;
}

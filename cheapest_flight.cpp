#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> v(n,INT_MAX);
        
        vector<pair<int,int>> V[n];
        for(auto it:flights){
            V[it[0]].push_back({it[1],it[2]});
        }
        v[src] = 0;
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> q;
        q.push({0,{src,0}});
        while(!q.empty()){
            int x = q.top().first;
            int node = q.top().second.first;
            int d = q.top().second.second;
            q.pop();
            for(auto it:V[node]){
                if(it.second+d<v[it.first]&&x<=k){
                    v[it.first] = it.second+d;
                    q.push({x+1,{it.first,v[it.first]}});
                }
            }
        }
        if(v[dst]!=INT_MAX) return v[dst];
        return -1;
    }
};

int main() {
    Solution sol;
    int n = 4;
    vector<vector<int>> flights = {{0,1,100},{1,2,100},{2,3,100},{0,2,500}};
    int src = 0, dst = 3, k = 1;
    cout << sol.findCheapestPrice(n, flights, src, dst, k) << endl;
    return 0;
}

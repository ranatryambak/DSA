#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class DSU {
public:
    vector<int> rank,parent,size;
    DSU(int n){
        rank.resize(n+1,0);
        parent.resize(n+1);
        size.resize(n+1);
        for (int i=0;i<=n;i++){
            parent[i] = i;
            size[i] = 1;
        }
    }
    int findparent(int node){
        if (node == parent[node]){
            return node;
        }
        return parent[node] = findparent(parent[node]);
    }
    void DSUbyrank(int u, int v){
        int u_p = findparent(u);
        int v_p = findparent(v);
        if(u_p==v_p) return;
        if(rank[u_p]>rank[v_p]){
            parent[v_p] = u_p;
        }
        else if(rank[u_p]<rank[v_p]){
            parent[u_p] = v_p;
        }
        else{
            parent[v_p] = u_p;
            rank[u_p]++;
        }
    }
    void DSUbysize(int u, int v){
        int u_p = findparent(u);
        int v_p = findparent(v);
        if(u_p==v_p) return;
        else if(size[u_p]>size[v_p]){
            parent[v_p] = u_p;
            size[u_p] += size[v_p];
        }
        else{
            parent[u_p] = v_p;
            size[v_p] += size[u_p];
        }
    }        
};

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        int maxrow = 0;
        int maxcol = 0;
        for(auto it:stones){
            maxrow = max(maxrow,it[0]);
            maxcol = max(maxcol,it[1]);
        }
        DSU ds(maxrow+maxcol+2);
        unordered_map<int,int> mp;
        for(auto it:stones){
            int rnode = it[0];
            int cnode = it[1] + maxrow+1;
            ds.DSUbysize(rnode,cnode);
            mp[rnode] = 1;
            mp[cnode] = 1;
        }
        int cmp = 0;
        for(auto it:mp){
            if(ds.findparent(it.first)==it.first) cmp++;
        }
        return n - cmp;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> stones = {{0,0},{0,1},{1,0},{1,2},{2,1},{2,2}};
    cout << sol.removeStones(stones) << endl;
    return 0;
}

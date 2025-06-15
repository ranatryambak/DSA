#include <iostream>
#include <vector>
using namespace std;

class DSU {
    vector<int> rank,parent,size;
public:
    DSU(int n){
        rank.resize(n+1,0);
        parent.resize(n+1);
        size.resize(n+1);
        for (int i=0;i<n;i++){
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
        if(size[u_p]>size[v_p]){
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
    int makeConnected(int n, vector<vector<int>>& connections) {
        DSU ds(n);
        int cntext = 0;
        for(auto it:connections){
            int a = it[0];
            int b = it[1];
            if(ds.findparent(a)==ds.findparent(b)){
                cntext++;
            }
            else{
                ds.DSUbysize(a,b);
            }
        }
        int cntc = 0;
        for(int i=0;i<n;i++){
            if(ds.findparent(i)==i) cntc++;
        }
        int ans = cntc-1;
        if(cntext>=ans) return ans;
        return -1;
    }
};

int main() {
    Solution sol;
    int n = 6;
    vector<vector<int>> connections = {{0,1},{0,2},{0,3},{1,4}};
    cout << sol.makeConnected(n, connections) << endl;
    return 0;
}

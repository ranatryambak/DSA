#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class DSU{
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
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        DSU ds(n);
        sort(accounts.begin(),accounts.end());
        unordered_map<string,int> mp;
        for(int i=0;i<n;i++){
            for(int j =1;j<accounts[i].size();j++){
                string mail = accounts[i][j];
                if(mp.find(mail)==mp.end()){
                    mp[mail] = i;
                }
                else{
                    ds.DSUbysize(i,mp[mail]);
                }
            }
        }

        vector<string> v[n];
        for(auto it:mp){
            string mail  = it.first;
            int node = ds.findparent(it.second);
            v[node].push_back(mail);
        }

        vector<vector<string>> ans;
        for(int i=0;i<n;i++){
            if(v[i].size()==0) continue;
            sort(v[i].begin(),v[i].end());
            vector<string> tmp;
            tmp.push_back(accounts[i][0]);
            for(auto it:v[i]){
                tmp.push_back(it);
            }
            ans.push_back(tmp);
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};

int main() {
    Solution sol;
    vector<vector<string>> accounts = {
        {"John", "johnsmith@mail.com", "john00@mail.com"},
        {"John", "johnnybravo@mail.com"},
        {"John", "johnsmith@mail.com", "john_newyork@mail.com"},
        {"Mary", "mary@mail.com"}
    };

    vector<vector<string>> merged = sol.accountsMerge(accounts);
    for (auto acc : merged) {
        for (auto s : acc) {
            cout << s << " ";
        }
        cout << endl;
    }
    return 0;
}

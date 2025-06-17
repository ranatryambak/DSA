class Solution {
public:
    int timer = 1;
    void dfs(vector<int> adj[],int tin[],int low[],vector<int> &v,vector<vector<int>> &ans,int n,int i,int parent){
        v[i] = 1;
        tin[i] = low[i] = timer;
        timer++;
        for(auto it:adj[i]){
            if(it==parent)continue;
            if(!v[it]){
                dfs(adj,tin,low,v,ans,n,it,i);
                low[i] = min(low[i],low[it]);
                if(low[it]>tin[i]){
                    ans.push_back({i,it});
                }
            }
            else{
                low[i] = min(low[i],low[it]);
            }
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<int> adj[n];
        for(auto it:connections){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        int tin[n];
        int low[n];
        vector<int> v(n,0);
        vector<vector<int>> ans;
        for(int i=0;i<n;i++){
            if(!v[i]){
                dfs(adj,tin,low,v,ans,n,i,-1);
            }
        }
        return ans;
    }
};
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> v(numCourses,0);
        vector<int> adj[numCourses];
        for(auto it:prerequisites){
            v[it[1]]++;
            adj[it[0]].push_back(it[1]);
        }
        queue<int> q;
        for(int i=0;i<numCourses;i++){
            if(v[i]==0){
                q.push(i);

            }

        }
        vector<int> c;
        while(!q.empty()){
            int tmp = q.front();
            q.pop();
            c.push_back(tmp);
            for(auto it:adj[tmp]){
                v[it]--;
                if(v[it]==0) q.push(it);
            }
        }

        return (c.size()==numCourses);

    }
};
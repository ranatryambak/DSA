#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> v(n,vector<int>(n,INT_MAX));
        for(auto it:edges){
            v[it[0]][it[1]] = it[2];
            v[it[1]][it[0]] = it[2];
        }
        for(int i=0;i<n;i++){
            v[i][i] = 0;
        }
        int city=0;
        int mini = INT_MAX;
        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(v[i][k]!=INT_MAX&&v[k][j]!=INT_MAX){
                        v[i][j] = min(v[i][j],v[i][k] + v[k][j]);
                    }
                }
            }
        }
        for(int i=0;i<n;i++){
            int cnt = 0;
            for(int j=0;j<n;j++){
                if(v[i][j]<=distanceThreshold)cnt++;
            }
            if(mini>=cnt){
                mini = cnt;
                city = i;
            }
        }
        return city;
    }
};

int main() {
    Solution sol;
    int n = 4;
    vector<vector<int>> edges = {{0,1,3},{1,2,1},{2,3,4},{0,3,2}};
    int distanceThreshold = 4;
    cout << sol.findTheCity(n, edges, distanceThreshold) << endl;
    return 0;
}

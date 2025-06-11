#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <cmath>

using namespace std;

class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        queue<pair<int,int>> q;
        vector<vector<int>> v(n,vector<int>(m,INT_MAX));
        v[0][0] = 0;
        q.push({0,0});
        while(!q.empty()){
            auto [x,y] = q.front();
            q.pop();
            vector<int> dx = {-1,0,1,0};
            vector<int> dy = {0,-1,0,1};
            for(int i=0;i<4;i++){
                int nx = x+dx[i];
                int ny = y+dy[i];
                if(nx>=0&&nx<n&&ny>=0&&ny<m){
                    int diff = abs(heights[nx][ny]-heights[x][y]);
                    int eff = max(diff,v[x][y]);
                    if(eff<v[nx][ny]){
                        q.push({nx,ny});
                        v[nx][ny] = eff;
                    }
                }
            }
        }
        return v[n-1][m-1];
    }
};

int main() {
    vector<vector<int>> heights = {
        {1, 2, 2},
        {3, 8, 2},
        {5, 3, 5}
    };
    Solution sol;
    cout << sol.minimumEffortPath(heights) << endl;
    return 0;
}

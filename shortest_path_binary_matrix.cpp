#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if(grid[0][0]==1||grid[n-1][n-1]==1){
            return -1;
        }
        queue<pair<int,int>> q;
        q.push({0,0});
        vector<vector<int>> v(n,vector<int>(n,INT_MAX));
        v[0][0] = 0;
        int ans=1;
        if(n==1) return ans;
        while(!q.empty()){
            int s = q.size();
            ans++;
            for(int i=0;i<s;i++){
                auto [x,y] = q.front();
                q.pop();
                vector<int> dx = {-1,-1,-1,0,0,1,1,1};
                vector<int> dy = {-1,0,1,-1,1,-1,0,1};
                for(int j=0;j<8;j++){
                    int nx = x + dx[j];
                    int ny = y + dy[j];
                    if(nx>=0&&nx<n&&ny>=0&&ny<n&&grid[nx][ny]==0&&ans<v[nx][ny]){
                        v[nx][ny] = ans;
                        q.push({nx,ny});
                        if(nx==n-1&&ny==n-1) return ans;
                    }
                }
            }
        }

        return -1;
    }
};

int main() {
    vector<vector<int>> grid = {
        {0, 1},
        {1, 0}
    };
    Solution sol;
    cout << sol.shortestPathBinaryMatrix(grid) << endl;
    return 0;
}

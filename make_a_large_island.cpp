class DSU {
public:
    vector<int> rank, parent, size;

    DSU(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findparent(int node) {
        if (node == parent[node]) return node;
        return parent[node] = findparent(parent[node]);
    }

    void DSUbysize(int u, int v) {
        int u_p = findparent(u);
        int v_p = findparent(v);
        if (u_p == v_p) return;
        if (size[u_p] > size[v_p]) {
            parent[v_p] = u_p;
            size[u_p] += size[v_p];
        } else {
            parent[u_p] = v_p;
            size[v_p] += size[u_p];
        }
    }
};

class Solution {
private:
    bool isValid(int r, int c, int n) {
        return r >= 0 && r < n && c >= 0 && c < n;
    }

public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        DSU ds(n * n);
        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, -1, 0, 1};

        // Step 1: Union connected 1s
        for (int row = 0; row < n; row++) {
            for (int col = 0; col < n; col++) {
                if (grid[row][col] == 0) continue;
                int node = row * n + col;
                for (int k = 0; k < 4; k++) {
                    int nr = row + dr[k], nc = col + dc[k];
                    if (isValid(nr, nc, n) && grid[nr][nc] == 1) {
                        int adjNode = nr * n + nc;
                        ds.DSUbysize(node, adjNode);
                    }
                }
            }
        }

        int ans = 0;

        // Step 2: Try converting each 0 and compute max size
        for (int row = 0; row < n; row++) {
            for (int col = 0; col < n; col++) {
                if (grid[row][col] == 1) continue;

                set<int> uniqueParents;
                for (int k = 0; k < 4; k++) {
                    int nr = row + dr[k], nc = col + dc[k];
                    if (isValid(nr, nc, n) && grid[nr][nc] == 1) {
                        int parent = ds.findparent(nr * n + nc);
                        uniqueParents.insert(parent);
                    }
                }

                int size = 1; // converting 0 to 1
                for (int p : uniqueParents) {
                    size += ds.size[p];
                }
                ans = max(ans, size);
            }
        }

        // Step 3: If there is no 0 to flip, return largest island
        for (int i = 0; i < n * n; i++) {
            if (ds.findparent(i) == i) {
                ans = max(ans, ds.size[i]);
            }
        }

        return ans;
    }
};

class Solution {
public:
    long long bfs(vector<vector<int>>& grid, vector<vector<bool>>& vis, int r, int c) {
        int n = grid.size(), m = grid[0].size();
        queue<pair<int, int>> q;
        
        q.push({r, c});
        vis[r][c] = true;
        
        long long sum = 0;
        int dirX[] = {-1, 0, 1, 0};
        int dirY[] = {0, -1, 0, 1};

        while (!q.empty()) {
            auto [currR, currC] = q.front();
            q.pop();
            sum += grid[currR][currC];

            for (int i = 0; i < 4; i++) {
                int nr = currR + dirX[i];
                int nc = currC + dirY[i];

                if (nr >= 0 && nr < n && nc >= 0 && nc < m && !vis[nr][nc] && grid[nr][nc] > 0) {
                    vis[nr][nc] = true;
                    q.push({nr, nc});
                }
            }
        }
        return sum;
    }

    int countIslands(vector<vector<int>>& grid, int k) {
        int n = grid.size(), m = grid[0].size();
        int cnt = 0;
        vector<vector<bool>> vis(n, vector<bool>(m, false));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!vis[i][j] && grid[i][j] > 0) {
                    if (bfs(grid, vis, i, j) % k == 0) {
                        cnt++;
                    }
                }
            }
        }
        return cnt;
    }
};
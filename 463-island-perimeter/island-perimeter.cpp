class Solution {
public:
    int dx[4] = {0, 1, 0, -1}, dy[4] = {-1, 0, 1, 0}, p = 0;
    void dfs(int r, int c, vector<vector<bool>>& vis,
             vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vis[r][c] = 1;
        for (int i = 0; i < 4; i++) {
            int R = r + dx[i], C = c + dy[i];
            if (R < 0 || R >= n || C < 0 || C >= m || grid[R][C] == 0) p++;
            else if (!vis[R][C]) dfs(R, C, vis, grid);
        }
        return;
    }
    int islandPerimeter(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j]){
                    dfs(i, j, vis, grid);
                    return p;
                }
            }
        }
        return p;
    }
};
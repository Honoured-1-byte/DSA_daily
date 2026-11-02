class Solution {
public:
    int dfs(int r, int c, vector<vector<bool>>& vis, vector<vector<int>>& grid) {
        vis[r][c] = true;
        int perimeter = 0;
        int dx[] = {-1, 1, 0, 0}, dy[] = {0, 0, -1, 1};
        int n = grid.size(), m = grid[0].size();
        for (int i = 0; i < 4; i++) {
            int R = r + dx[i], C = c + dy[i];
            if (R < 0 || R >= n || C < 0 || C >= m || grid[R][C] == 0) perimeter++;
            else if (!vis[R][C]) perimeter += dfs(R, C, vis, grid);
        }
        return perimeter;
    }

    int islandPerimeter(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, 0));

        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (grid[i][j] == 1)
                    return dfs(i, j, vis, grid);
        return 0;
    }
};
class Solution {
public:
    void floodFill(int r, int c, int m, int n, vector<vector<int>>& grid) {
        if (r < 0 || r >= m || c < 0 || c >= n || grid[r][c] == 1) {
            return;
        }
        grid[r][c] = 1;
        floodFill(r - 1, c, m, n, grid); 
        floodFill(r + 1, c, m, n, grid); 
        floodFill(r, c - 1, m, n, grid); 
        floodFill(r, c + 1, m, n, grid); 
    }

    int closedIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if ((i == 0 || i == m - 1 || j == 0 || j == n - 1) && grid[i][j] == 0) {
                    floodFill(i, j, m, n, grid);
                }
            }
        }
        int closed_islands_count = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    closed_islands_count++;
                    floodFill(i, j, m, n, grid);
                }
            }
        }
        
        return closed_islands_count;
    }
};
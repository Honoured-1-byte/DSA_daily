class Solution {
    vector<vector<vector<int>>> jx, jy;

    pair<int, int> go(vector<vector<int>>& g, int r, int c, int d) {
        if (r >= g.size() || c >= g[0].size()) return {-1, -1};
        if (jx[r][c][d] != -1) return {jx[r][c][d], jy[r][c][d]};
        
        if (g[r][c] == 0) {
            jx[r][c][d] = r; 
            jy[r][c][d] = c;
        } else {
            auto p = d == 0 ? go(g, r + 1, c, 1) : go(g, r, c + 1, 0);
            jx[r][c][d] = p.first; 
            jy[r][c][d] = p.second;
        }
        return {jx[r][c][d], jy[r][c][d]};
    }

public:
    int uniquePaths(vector<vector<int>>& g) {
        int m = g.size(), n = g[0].size(), mod = 1e9 + 7;
        
        jx.assign(m, vector<vector<int>>(n, vector<int>(2, -1)));
        jy.assign(m, vector<vector<int>>(n, vector<int>(2, -1)));
        
        vector<vector<int>> dp(m, vector<int>(n, 0));
        dp[0][0] = 1;
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (!dp[i][j]) continue;
                
                auto p1 = go(g, i, j + 1, 0);
                if (p1.first != -1) {
                    dp[p1.first][p1.second] = (dp[p1.first][p1.second] + dp[i][j]) % mod;
                }
                
                auto p2 = go(g, i + 1, j, 1);
                if (p2.first != -1) {
                    dp[p2.first][p2.second] = (dp[p2.first][p2.second] + dp[i][j]) % mod;
                }
            }
        }
        return dp[m - 1][n - 1];
    }
};
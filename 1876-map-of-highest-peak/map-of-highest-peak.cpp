class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int n = isWater.size(), m = isWater[0].size();
        queue<pair<int, int>> q;
        vector<vector<int>> ans(n, vector<int>(m, -1));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(isWater[i][j]) {
                    q.push({i, j});
                    ans[i][j] = 0;
                }
            }
        }        
        vector<int> dx = {0, 1, 0, -1};
        vector<int> dy = {-1, 0, 1, 0};        
        while(!q.empty()) {
            auto [r, c] = q.front();
            q.pop();            
            for(int j = 0; j < 4; j++) {
                int nr = r + dx[j], nc = c + dy[j];
                if(nr >= 0 && nr < n && nc >= 0 && nc < m && ans[nr][nc] == -1) {
                    ans[nr][nc] = ans[r][c] + 1; 
                    q.push({nr, nc});
                }
            } 
        }
        return ans;
    }
};
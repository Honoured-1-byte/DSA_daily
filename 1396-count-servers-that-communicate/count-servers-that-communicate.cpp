class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int m=grid.size(), n=grid[0].size();
        vector<int>row(m,-1), col(n,-1);
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                row[i]+=grid[i][j];
                col[j]+=grid[i][j];
            }
        }
        int c=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] && (row[i] || col[j])) c++;
            }
        }
        return c;
    }
};
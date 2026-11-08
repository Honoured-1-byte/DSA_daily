class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<int> col(n, 0);
        vector<int> lone_candidates;
        int c = 0;

        for (int i = 0; i < m; i++) {
            int row_count = 0;
            int last_col = -1;

            for (int j = 0; j < n; j++) {
                if (grid[i][j]) {
                    row_count++;
                    col[j]++;
                    last_col = j;
                }
            }

            if (row_count > 1) {
                c += row_count;
            } else if (row_count == 1) {
                lone_candidates.push_back(last_col);
            }
        }
        for (int col_idx : lone_candidates) {
            if (col[col_idx] > 1) {
                c++;
            }
        }

        return c;
    }
};
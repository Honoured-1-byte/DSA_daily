class Solution {
public:
    int minimumChanges(string s, int k) {
        int n = s.length();
        const int INF = 1e9;
        vector<vector<int>> divisors(n + 1);
        for (int len = 2; len <= n; ++len) {
            for (int d = 1; d < len; ++d) {
                if (len % d == 0) {
                    divisors[len].push_back(d);
                }
            }
        }
        vector<vector<int>> cost(n, vector<int>(n, INF));        
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int len = j - i + 1;
                int min_ops = INF;
                
                for (int d : divisors[len]) {
                    int ops = 0;
                    for (int start = 0; start < d; ++start) {
                        int left = i + start;
                        int right = j - (d - 1 - start);
                        while (left < right) {
                            if (s[left] != s[right]) {
                                ops++;
                            }
                            left += d;
                            right -= d;
                        }
                    }
                    min_ops = min(min_ops, ops);
                }
                cost[i][j] = min_ops;
            }
        }
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, INF));
        dp[0][0] = 0;
        
        for (int p = 1; p <= k; ++p) {
            for (int i = 2 * p; i <= n; ++i) {
                for (int m = 2 * (p - 1); m <= i - 2; ++m) {
                    if (dp[m][p - 1] != INF) {
                        dp[i][p] = min(dp[i][p], dp[m][p - 1] + cost[m][i - 1]);
                    }
                }
            }
        }
        
        return dp[n][k];
    }
};
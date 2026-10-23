class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int maxVal = *max_element(nums.begin(), nums.end());
        vector<vector<int>> dp(maxVal + 1, vector<int>(maxVal + 1, 0));
        for (int num : nums) {
            for (int prev = 1; prev <= maxVal; prev++) {
                int diff = abs(num - prev);
                dp[num][diff] = max(dp[num][diff], dp[prev][diff] + 1);
            }
            for (int j = maxVal - 1; j >= 0; --j) {
                dp[num][j] = max(dp[num][j], dp[num][j + 1]);
            }
        }
        int maxLen = 0;
        for (int v = 1; v <= maxVal; ++v) {
            maxLen = max(maxLen, dp[v][0]);
        }
        return maxLen;
    }
};
class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return 0;
        int idx = 0;
        for (int i = 0; i < n; ++i) {
            if (nums[i] == 0) {
                idx = i;
                break;
            }
        }
        bool is_inc = true;
        for (int i = 0; i < n; ++i) {
            if (nums[(idx + i) % n] != i) {
                is_inc = false;
                break;
            }
        }
        bool is_dec = true;
        for (int i = 0; i < n; ++i) {
            if (nums[(idx - i + n) % n] != i) {
                is_dec = false;
                break;
            }
        }
        if (!is_inc && !is_dec) return -1;
        int ans = INT_MAX;
        if (is_inc) {
            if (idx == 0)  ans = min(ans, 0);
            else ans = min({ans, idx, n - idx + 2});
        }
        if (is_dec) {
            int opt1 = n - idx;
            int opt2 = (idx == n - 1) ? 1 : (idx + 2);
            ans = min({ans, opt1, opt2});
        }

        return ans;
    }
};
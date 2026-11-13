class Solution {
public:
    long long countNonDecreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        deque<int> dq;
        long long ops = 0, ans = 0;
        int r = n - 1;
        for (int l = n - 1; l >= 0; l--) {
            while (!dq.empty() && nums[dq.front()] <= nums[l]) {
                int curr = dq.front();
                dq.pop_front();
                int next_boundary = dq.empty() ? r + 1 : dq.front();
                long long len = next_boundary - curr;
                ops += 1LL * (nums[l] - nums[curr]) * len;
            }
            dq.push_front(l);
            while (ops > k) {
                ops -= (nums[dq.back()] - nums[r]);
                if (dq.back() == r) {
                    dq.pop_back();
                }
                r--;
            }

            ans += (r - l + 1);
        }

        return ans;
    }
};
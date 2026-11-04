class Solution {
    multiset<int> left, right;
    long long sum_left = 0, sum_right = 0;
    int target_left_size;

    void balance() {
        while (left.size() > target_left_size) {
            auto it = prev(left.end());
            int val = *it;
            left.erase(it);
            sum_left -= val;
            right.insert(val);
            sum_right += val;
        }
        while (left.size() < target_left_size && !right.empty()) {
            auto it = right.begin();
            int val = *it;
            right.erase(it);
            sum_right -= val;
            left.insert(val);
            sum_left += val;
        }
    }

    void add(int val) {
        if (left.empty() || val <= *left.rbegin()) {
            left.insert(val);
            sum_left += val;
        } else {
            right.insert(val);
            sum_right += val;
        }
        balance();
    }

    void remove(int val) {
        auto it = left.find(val);
        if (it != left.end()) {
            left.erase(it);
            sum_left -= val;
        } else {
            it = right.find(val);
            right.erase(it);
            sum_right -= val;
        }
        balance();
    }

    long long get_cost(int x) {
        long long median = *left.rbegin();
        if (x % 2 == 1) {
            return sum_right - sum_left + median;
        } else {
            return sum_right - sum_left;
        }
    }

public:
    long long minOperations(vector<int>& nums, int x, int k) {
        int n = nums.size();
        target_left_size = (x + 1) / 2;
        vector<long long> cost(n, 0);
        for (int i = 0; i < n; ++i) {
            add(nums[i]);
            if (i >= x) remove(nums[i - x]);
            if (i >= x - 1) cost[i] = get_cost(x);
        }
        const long long INF = 1e18;
        vector<long long> prev_dp(n + 1, 0);
        vector<long long> curr_dp(n + 1, INF);
        for (int j = 1; j <= k; ++j) {
            curr_dp.assign(n + 1, INF);
            for (int i = j * x; i <= n; ++i) {
                curr_dp[i] = curr_dp[i - 1];
                if (prev_dp[i - x] != INF) {
                    curr_dp[i] = min(curr_dp[i], prev_dp[i - x] + cost[i - 1]);
                }
            }
            prev_dp = curr_dp;
        }
        return prev_dp[n];
    }
};
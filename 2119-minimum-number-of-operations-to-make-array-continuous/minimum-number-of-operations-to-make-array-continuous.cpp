class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        nums.erase(unique(nums.begin(), nums.end()), nums.end());        
        int m = nums.size();
        int max_kept = 0;
        for (int i = 0; i < m; ++i) {
            int target = nums[i] + n - 1;
            int right_idx = upper_bound(nums.begin(), nums.end(), target) - nums.begin();
            
            int count = right_idx - i;
            max_kept = max(max_kept, count);
        }
        
        return n - max_kept;
    }
};
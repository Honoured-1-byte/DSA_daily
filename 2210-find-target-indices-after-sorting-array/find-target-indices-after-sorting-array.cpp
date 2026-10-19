class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        int less = 0, count = 0;
        for (int x : nums) {
            if (x < target) less++;
            else if (x == target) count++;
        }        
        vector<int> ans(count);
        for (int i = 0; i < count; i++) {
            ans[i] = less + i;
        }
        return ans;
    }
};
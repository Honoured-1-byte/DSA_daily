class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int t) {
        sort(nums.begin(), nums.end());
        int lo = lower_bound(nums.begin(), nums.end(), t) - nums.begin(),
            hi = upper_bound(nums.begin(), nums.end(), t) - nums.begin();
        vector<int> ans;
        ans.reserve(hi - lo);
        for (int i = lo; i < hi; i++)
            ans.push_back(i);
        return ans;
    }
};
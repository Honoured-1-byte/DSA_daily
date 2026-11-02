class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size(), med =(nums[(n-1)/2]+nums[n/2])/2, m=0;
        for(int x: nums) m+=abs(x-med);
        return m;
    }
};
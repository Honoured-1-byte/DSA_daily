class Solution {
public:
    int minMoves(vector<int>& nums) {
        return *max_element(nums.begin(),nums.end())*nums.size()-accumulate(nums.begin(),nums.end(),0);
    }
};
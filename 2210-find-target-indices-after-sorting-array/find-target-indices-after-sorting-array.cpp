class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int t) {
        vector<int> count(101,0),ans;
        for(int x:nums) count[x]++;
        for(int i=1;i<t;i++) count[i]+=count[i-1];
        if(!t) return {};
        ans.reserve(count[t]);
        for(int i=0;i<count[t];i++) ans.push_back(count[t-1]+i);
        return ans;
    }
};
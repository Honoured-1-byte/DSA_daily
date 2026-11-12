class Solution {
public:
    int lis(vector<int>& nums){
        int n=nums.size(), ans=1;    
        for(int i=0;i<n;i++){
            int len=1, val=nums[i];
            for(int j=i+1;j<n;j++){
                if(val<nums[j]){
                    len++;
                    val=nums[j];
                }
                else break;
            }
            ans=max(ans,len);
        }
        return ans;
    }
    int longestMonotonicSubarray(vector<int>& nums) {
        int a=lis(nums);
        reverse(nums.begin(),nums.end());
        int b=lis(nums);
        return max(a,b);        
    }
};
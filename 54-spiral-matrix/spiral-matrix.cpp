class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int upper=0,right=matrix[0].size()-1,lower=matrix.size()-1,left=0,i;
        vector<int> ans;
        while(upper<=lower || left<=right)
        {
            for(i=left;i<=right && upper<=lower;i++)
                ans.push_back(matrix[upper][i]);
            upper++;
            for(i=upper;i<=lower && left<=right;i++)
                ans.push_back(matrix[i][right]);
            right--;
            for(i=right;i>=left && upper<=lower;i--)
                ans.push_back(matrix[lower][i]);
            lower--;
            for(i=lower;i>=upper && left<=right;i--)
                ans.push_back(matrix[i][left]);
            left++;
        }
        return ans;
    }
        
    
};
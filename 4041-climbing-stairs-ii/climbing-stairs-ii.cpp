class Solution {
public:
    int climbStairs(int n, vector<int>& c) {
        int p=0, q=1+c[0];
        if(n==1) return q;
        int r=c[1]+min(4,q+1);
        if(n==2) return r;
        int cost;
        for(int i=2;i<n;i++){
            cost=c[i]+min({p+9,q+4,r+1});
            p=q;
            q=r;
            r=cost;
        }
        return cost;
    }
};